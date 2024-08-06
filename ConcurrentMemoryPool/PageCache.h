#pragma once

#include "Common.h"

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_sInst;
	}

	// 获取一个k页的span，pc从_spanLists中拿出来一个k页的span
	Span* NewSpan(size_t k);

	std::mutex& getPageMutex() 
	{
		return _pageMtx;
	}

private:
	SpanList _SpanLists[NPAGES];	// pageCache
	std::mutex _pageMtx;			// pc整体的锁

	PageCache()
	{ }

	PageCache(const PageCache& pc) = delete;
	PageCache& operator= (const PageCache& pc) = delete;
	static PageCache _sInst;	// 单例类对象
};
