#include "CentralCache.h"
#include "PageCache.h"

CentralCache CentralCache::_sInst;

// ��ȡһ���ǿյ�span
Span* CentralCache::GetOneSpan(SpanList& list, size_t size)
{
	Span* it = list.Begin();
	while (it != list.End())
	{
		if (it->_freeList != nullptr)
		{
			return it;
		}
		else
		{
			it = it->_next;
		}
	}

	// �Ȱ�central cache��Ͱ������������̻߳������������������
	list._mtx.unlock();

	// �ߵ�����û�п��е�span����pageCacheҪ
	PageCache::GetInstance()->getPageMutex().lock();
	Span* span = PageCache::GetInstance()->NewSpan(SizeClass::NumMovePage(size));

	// ����span�Ĵ���ڴ����ʼ��ַ�ʹ���ڴ�Ĵ�С���ֽ�����
	char* start = (char*)(span->_pageID << PAGE_SHIFT);
	size_t bytes = span->_n << PAGE_SHIFT;
	char* end = start + bytes;

	// �Ѵ���ڴ��г�����������������
	// ��������һ��ȥ��ͷ�ڵ㣬����β��
	span->_freeList = start;
	start += size;
	void* tail = span->_freeList;

	while (start < end)
	{
		NextObj(tail) = start;
		tail = NextObj(tail);		// tail = start;
		start += size;
	}

	list.PushFront(span);

	return span;
}

// �����Ļ����ȡһ�������Ķ����thread cache
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t batchNum, size_t size)
{
	size_t index = SizeClass::Index(size);
	_spanLists[index]._mtx.lock();

	Span* span = GetOneSpan(_spanLists[index], size);
	assert(span);
	assert(span->_freeList);

	// ��span�л�ȡbatchNum����
	// �ж����ö���
	start = span->_freeList;
	end = start;
	size_t i = 0;
	size_t actualNum = 1;
	while(i < batchNum - 1 && NextObj(end) != nullptr)
	{
		end = NextObj(end);
		++i; 
	}
	span->_freeList = NextObj(end);
	NextObj(end) = nullptr;

	span->_useCount += actualNum;

	_spanLists[index]._mtx.unlock();

	return actualNum;
}