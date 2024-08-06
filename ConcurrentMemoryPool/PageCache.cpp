#include "PageCache.h"

PageCache PageCache::_sInst;	// ��������

// ��ȡһ��kҳ��span
Span* PageCache::NewSpan(size_t k)
{
	assert(k > 0 && k < NPAGES);

	//GetInstance()->_pageMtx.lock();

	// �ȼ���k��Ͱ������û��span
	if (!_SpanLists[k].Empty())
	{
		return _SpanLists->PopFront();
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