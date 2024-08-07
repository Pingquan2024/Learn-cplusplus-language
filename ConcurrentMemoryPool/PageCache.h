#pragma once

#include "Common.h"
#include <unordered_map>

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_sInst;
	}

	// 获取一个k页的span，pc从_spanLists中拿出来一个k页的span
	Span* NewSpan(size_t k);

	//通过页地址找到span
	Span* MapObjectToSpan(void* obj);

	// 管理central cache还回来的span
	void ReleaseSpanToPageCache(Span* span);

	std::mutex& getPageMutex() 
	{
		return _pageMtx;
	}

private:
	SpanList _SpanLists[NPAGES];	// pageCache
	std::mutex _pageMtx;			// pc整体的锁
	// 哈希映射，用来快速通过页号找到对应的span
	std::unordered_map<PAGE_ID, Span*> _idSpanMap;

	PageCache()
	{ }

	PageCache(const PageCache& pc) = delete;
	PageCache& operator= (const PageCache& pc) = delete;
	static PageCache _sInst;	// 单例类对象
};
