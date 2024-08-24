#include "CentralCache.h"
#include "PageCache.h"

CentralCache CentralCache::_sInst;	// CentralCache�Ķ�������

// ��ȡһ���ǿյ�span
Span* CentralCache::GetOneSpan(SpanList& list, size_t size)
{
	Span* it = list.Begin();
	while (it != list.End())
	{
		if (it->_freeList != nullptr)	// �ҵ�����ռ�ǿյ�span
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
	span->_isUse = true;
	PageCache::GetInstance()->getPageMutex().unlock();

	// ����span�Ĵ���ڴ����ʼ��ַ�ʹ���ڴ�Ĵ�С���ֽ�����
	char* start = (char*)(span->_pageID << PAGE_SHIFT);
	char* end = (char*)(start + (span->_n << PAGE_SHIFT));

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

	NextObj(tail) = nullptr;

	// �к�span֮����Ҫ��span�ҵ�centralCache��Ӧ�±��Ͱ����ȥ
	list._mtx.lock();
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
	size_t actualNum = 1;	// ����ʵ�ʵķ���ֵ
	while(i < batchNum - 1 && NextObj(end) != nullptr)
	{
		end = NextObj(end);
		++actualNum;
		++i; 
	}
	// ��[start, end]���ظ�threadCache�󣬵���Span��_freeList
	span->_freeList = NextObj(end);
	NextObj(end) = nullptr;		//end��nextҪָ���,��Ҫ��ԭ��Span��_freeList�еĿ�����

	span->_useCount += actualNum;

	_spanLists[index]._mtx.unlock();

	return actualNum;
}

void CentralCache::ReleaseListToSpans(void* start, size_t size)
{
	size_t index = SizeClass::Index(size);
	_spanLists[index]._mtx.lock();

	while (start)
	{
		void* next = NextObj(start);

		Span* span = PageCache::GetInstance()->MapObjectToSpan(start);
		// �ѵ�ǰ����뵽��Ӧspan��
		NextObj(start) = span->_freeList;
		span->_freeList = start;
		span->_useCount--;

		// ˵��span���зֳ�ȥ������С���ڴ涼������
		// ���span�Ϳ����ٻ��ո�page cache��pagecache�����ٳ���ȥ��ǰ��ҳ�ĺϲ�
		if (span->_useCount == 0)
		{
			_spanLists[index].Erase(span);
			span->_freeList = nullptr;	// �����span��centralCache��Ӧ��ϣͰͰɾ��
			span->_next = nullptr;
			span->_prev = nullptr;

			// �ͷ�span��page cacheʱ��ʹ��page cache�����Ϳ�����
			// ��ʱ��Ͱ�����
			_spanLists[index]._mtx.unlock();

			PageCache::GetInstance()->getPageMutex().lock();
			PageCache::GetInstance()->ReleaseSpanToPageCache(span);
			PageCache::GetInstance()->getPageMutex().unlock();

			_spanLists[index]._mtx.lock();
		}

		start = next;
	}

	_spanLists[index]._mtx.unlock();
}