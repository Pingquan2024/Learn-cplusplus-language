#pragma once

#include "Common.h"
#include "ThreadCache.h"
#include "PageCache.h"

// 线程调用这个函数申请空间
static void* ConcurrentAlloc(size_t size)
{
	if (size > MAX_BYTES)
	{
		size_t alignSize = SizeClass::RoundUp(size);	// 计算按多少字节对齐
		size_t kpage = alignSize >> PAGE_SHIFT;

		PageCache::GetInstance()->getPageMutex().lock();
		Span* span = PageCache::GetInstance()->NewSpan(kpage);
		span->_objSize = size;
		PageCache::GetInstance()->getPageMutex().unlock();

		void* ptr = (void*)(span->_pageID << PAGE_SHIFT);
		return ptr;
	}
	else
	{
		if (pTLSThreadCache == nullptr)
		{
			// pTLSThreadCache = new ThreadCache
			// 此时就相当于每个线程都有一个ThreadCache对象

			static ObjectPool<ThreadCache> tcpool;
			pTLSThreadCache = tcpool.New();
		}

		// cout << std::this_thread::get_id() << ":" << pTLSThreadCache << endl;

		return pTLSThreadCache->Allocate(size);
	}
	
}

// 线程调用这个函数来回收空间
static void* ConcurrentFree(void* ptr,size_t size)
{
	assert(pTLSThreadCache);

	pTLSThreadCache->Deallocate(ptr,size);

}

