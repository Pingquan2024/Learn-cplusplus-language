#include "CentralCache.h"
#include "PageCache.h"

CentralCache CentralCache::_sInst;	// CentralCache的饿汉对象

// 获取一个非空的span
Span* CentralCache::GetOneSpan(SpanList& list, size_t size)
{
	Span* it = list.Begin();
	while (it != list.End())
	{
		if (it->_freeList != nullptr)	// 找到管理空间非空的span
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
	span->_isUse = true;
	PageCache::GetInstance()->getPageMutex().unlock();

	// 计算span的大块内存的起始地址和大块内存的大小（字节数）
	char* start = (char*)(span->_pageID << PAGE_SHIFT);
	char* end = (char*)(start + (span->_n << PAGE_SHIFT));

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

	NextObj(tail) = nullptr;

	// 切好span之后，需要把span挂到centralCache对应下标的桶里面去
	list._mtx.lock();
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
	size_t actualNum = 1;	// 函数实际的返回值
	while(i < batchNum - 1 && NextObj(end) != nullptr)
	{
		end = NextObj(end);
		++actualNum;
		++i; 
	}
	// 将[start, end]返回给threadCache后，调整Span的_freeList
	span->_freeList = NextObj(end);
	NextObj(end) = nullptr;		//end的next要指向空,不要和原先Span的_freeList中的块相连

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
		// 把当前块插入到对应span中
		NextObj(start) = span->_freeList;
		span->_freeList = start;
		span->_useCount--;

		// 说明span的切分出去的所有小块内存都回来了
		// 这个span就可以再回收给page cache，pagecache可以再尝试去做前后页的合并
		if (span->_useCount == 0)
		{
			_spanLists[index].Erase(span);
			span->_freeList = nullptr;	// 将这个span在centralCache对应哈希桶桶删掉
			span->_next = nullptr;
			span->_prev = nullptr;

			// 释放span给page cache时，使用page cache的锁就可以了
			// 这时把桶锁解掉
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