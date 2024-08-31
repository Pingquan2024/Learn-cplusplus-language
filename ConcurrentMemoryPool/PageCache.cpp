#include "PageCache.h"
#include "Common.h"

PageCache PageCache::_sInst;	// ��������

// ��ȡһ��kҳ��span
Span* PageCache::NewSpan(size_t k)
{
	assert(k > 0 && k < NPAGES);

	//GetInstance()->_pageMtx.lock();

	// �ȼ���k��Ͱ������û��span
	if (!_SpanLists[k].Empty())
	{
		Span* span =  _SpanLists->PopFront();

		// ��¼�����ȥ��span�����ҳ�ź����ַ��ӳ���ϵ
		for (PAGE_ID i = 0; i < span->_n; i++)
		{
			// i��Page_ID���ͣ���Ȼ��64λ�º�_pageID��ӻᱨ����
			_idSpanMap[span->_pageID + i] = span;
		}

		return span;
	}

	// ���һ�º����Ͱ����û��span�������������з�
	for (int i = k + 1; i < NPAGES; i++)
	{
		// [k + 1, NPAGES - 1]��Ͱ����û��span
		if (!_SpanLists[i].Empty())
		{
			// �ҵ���
			Span* nSpan = _SpanLists[i].PopFront();
			Span* kSpan = new Span;	// span�Ŀռ�����Ҫ�½��ģ��������õ�ǰ�ڴ���еĿռ�

			// ��span��ͷ����һ��span����
			// kҳSpan����
			// nSpan�ٹҵ���Ӧ��ӳ����

			kSpan->_pageID = nSpan->_pageID;
			kSpan->_n = k;

			nSpan->_pageID += k;
			nSpan->_n -= k;
			_SpanLists[nSpan->_n].PushFront(nSpan);

			// �ٰ�n-kҳ��span��Եҳӳ��һ�£���������ϲ�
			_idSpanMap[nSpan->_pageID] = nSpan;
			_idSpanMap[nSpan->_pageID + nSpan->_n - 1] = nSpan;


			// ��¼�����ȥ��span�����ҳ�ź����ַ��ӳ���ϵ
			for (PAGE_ID i = 0; i < kSpan->_n; i++)
			{
				// i��Page_ID���ͣ���Ȼ��64λ�º�_pageID��ӻᱨ����
				_idSpanMap[kSpan->_pageID + i] = kSpan;
			}

			return kSpan;
		}
	}

	// �ߵ���˵������û�д�ҳ��Span
	// ��ϵͳ��������128ҳ�Ĵ��ڴ�
	Span* bigSpan = new Span;
	void* ptr = SystemAlloc(NPAGES - 1);
	bigSpan->_pageID = (PAGE_ID)ptr >> PAGE_SHIFT;
	bigSpan->_n = NPAGES - 1;

	_SpanLists[bigSpan->_n].PushFront(bigSpan);

	// �ݹ��ٴ�����kҳ��span����εݹ�һ������ k��Ͱû��span���������Ͱ����span
	return NewSpan(k);	// ���ô���
}

// ͨ����ַ�ҵ�span
Span* PageCache::MapObjectToSpan(void* obj)
{
	PAGE_ID id = (((PAGE_ID)obj) >> PAGE_SHIFT);

	// ������
	std::unique_lock<std::mutex> lc(PageCache().getPageMutex());
	// ͨ����ϣ�ҵ�ҳ�Ŷ�Ӧ��span
	auto ret = _idSpanMap.find(id);

	if (ret != _idSpanMap.end())
	{
		return ret->second;
	}
	else
	{
		assert(false);
		return nullptr;
	}
}


void PageCache::ReleaseSpanToPageCache(Span* span) 
{
	// ���󲻶Ϻϲ�
	while(true)
	{
		PAGE_ID leftID = span->_pageID - 1;
		auto ret = _idSpanMap.find(leftID);

		// û������spanֹͣ�ϲ�
		if (ret == _idSpanMap.end())
		{
			break;
		}

		Span* leftSpan = ret->second;
		// ����span��centralCache�У�ֹͣ�ϲ�
		if (leftSpan->_isUse == true)
		{
			break;
		}

		//����span�뵱ǰspan�ϲ��󳬹�128ҳ��ֹͣ�ϲ�
		if (leftSpan->_n + span->_n > PAGE_SHIFT)
		{
			break;
		}

		// ��ǰspan������span���кϲ�
		span->_pageID = leftSpan->_pageID;
		span->_n += leftSpan->_n;

		_SpanLists[leftSpan->_n].Erase(leftSpan);	// �����ڶ����Ͱ��ɾ��
		delete leftSpan;
	}

	// ���Ҳ��Ϻϲ�
	while(true)
	{
		PAGE_ID rightID = span->_pageID + span->_n;
		auto it = _idSpanMap.find(rightID);

		// û������spanֹͣ�ϲ�
		if (it == _idSpanMap.end())
		{
			break;
		}

		Span* rightSpan = it->second;
		// ����span��centralCache�У�ֹͣ�ϲ�
		if (rightSpan->_isUse == true)
		{
			break;
		}

		//����span�뵱ǰspan�ϲ��󳬹�128ҳ��ֹͣ�ϲ�
		if (rightSpan->_n + span->_n > PAGE_SHIFT - 1)
		{
			break;
		}

		// ��ǰspan������span���кϲ�
		span->_n += rightSpan->_n;

		_SpanLists[rightSpan->_n].Erase(rightSpan);	// �����ڶ����Ͱ��ɾ��
		delete rightSpan;
	}

	// �Ϲ���ϣ�����ǰspan���ڶ�ӦͰ��
	_SpanLists[span->_n].PushFront(span);
	span->_isUse = false;	// ��cc���ص�pc��isUse�ĳ�false

	// ӳ�䵱ǰspan�ı�Եҳ�����������Զ����span�ϲ�
	_idSpanMap[span->_pageID] = span;
	_idSpanMap[span->_pageID + span->_n - 1] = span;

}
