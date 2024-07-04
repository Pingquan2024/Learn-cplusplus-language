#pragma once

#include "Common.h"

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_sInst;
	}

	// 获取一个k页的span
	Span* NewSpan(size_t k);

	//void* GetPageMtx()
	//{
	//	return _pageMtx;
	//}

private:
	std::mutex _pageMtx;

	SpanList _SpanLists[NPAGES];
	std::mutex _pageMtx;

	PageCache()
	{ }

	PageCache(const PageCache&) = delete;

	static PageCache _sInst;
};
