#pragma once

#include "Common.h"
#include "ThreadCache.h"
#include "PageCache.h"
#include "ObjectPool.h"

// �̵߳��������������ռ�
static void* ConcurrentAlloc(size_t size)
{
	if (size > MAX_BYTES)
	{
		size_t alignSize = SizeClass::RoundUp(size);	// ���㰴�����ֽڶ���
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
			// ��ʱ���൱��ÿ���̶߳���һ��ThreadCache����

			static ObjectPool<ThreadCache> tcpool;
			pTLSThreadCache = tcpool.New();
		}

		// cout << std::this_thread::get_id() << ":" << pTLSThreadCache << endl;

		return pTLSThreadCache->Allocate(size);
	}
	
}

// �̵߳���������������տռ�
void ConcurrentFree(void* ptr)
{
	assert(ptr);

	// ͨ��ptr�ҵ���Ӧ��span,��Ϊǰ������ռ��ʱ���Ѿ���֤��ά���Ŀռ���ҳ��ַ�Ѿ�ӳ�����
	Span* span = PageCache::GetInstance()->MapObjectToSpan(ptr);
	size_t size = span->_objSize;	// ͨ��ӳ������span��ȡptr��ָ�ռ��С

	// ͨ��size���ж��ǲ��Ǵ���256kb��,���˾���pthreadCache
	if (size > MAX_BYTES)
	{
		PageCache::GetInstance()->getPageMutex().lock();
		PageCache::GetInstance()->ReleaseSpanToPageCache(span);	//ֱ��ͨ��span�ͷſռ�
		PageCache::GetInstance()->getPageMutex().unlock();
	}
	else
	{
		pTLSThreadCache->Deallocate(ptr, size);
	}
}

