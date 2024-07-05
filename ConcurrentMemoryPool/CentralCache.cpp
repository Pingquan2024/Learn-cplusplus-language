#include "CentralCache.h"
#include "PageCache.h"

CentralCache CentralCache::_sInst;

// 获取一个非空的span
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

	// 先把central cache的桶锁解掉，其他线程还对象回来，不会阻塞
	list._mtx.unlock();

	// 走到这里没有空闲的span，找pageCache要
	PageCache::GetInstance()->getPageMutex().lock();
	Span* span = PageCache::GetInstance()->NewSpan(SizeClass::NumMovePage(size));

	// 计算span的大块内存的起始地址和大块内存的大小（字节数）
	char* start = (char*)(span->_pageID << PAGE_SHIFT);
	size_t bytes = span->_n << PAGE_SHIFT;
	char* end = start + bytes;

	// 把大块内存切成自由链表链接起来
	// 先切下来一块去做头节点，方便尾插
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

// 从中心缓存获取一定数量的对象给thread cache
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t batchNum, size_t size)
{
	size_t index = SizeClass::Index(size);
	_spanLists[index]._mtx.lock();

	Span* span = GetOneSpan(_spanLists[index], size);
	assert(span);
	assert(span->_freeList);

	// 从span中获取batchNum对象
	// 有多少拿多少
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