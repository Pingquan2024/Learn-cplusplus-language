#pragma once

#include "Common.h"
#include "ThreadCache.h"
#include "PageCache.h"
#include "ObjectPool.h"

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
void ConcurrentFree(void* ptr)
{
	assert(ptr);

	// 通过ptr找到对应的span,因为前面申请空间的时候已经保证了维护的空间首页地址已经映射过了
	Span* span = PageCache::GetInstance()->MapObjectToSpan(ptr);
	size_t size = span->_objSize;	// 通过映射来的span获取ptr所指空间大小

	// 通过size来判断是不是大于256kb的,是了就走pthreadCache
	if (size > MAX_BYTES)
	{
		PageCache::GetInstance()->getPageMutex().lock();
		PageCache::GetInstance()->ReleaseSpanToPageCache(span);	//直接通过span释放空间
		PageCache::GetInstance()->getPageMutex().unlock();
	}
	else
	{
		pTLSThreadCache->Deallocate(ptr, size);
	}
}

