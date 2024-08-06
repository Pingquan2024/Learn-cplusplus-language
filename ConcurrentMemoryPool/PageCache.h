#pragma once

#include "Common.h"

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_sInst;
	}

	// ��ȡһ��kҳ��span��pc��_spanLists���ó���һ��kҳ��span
	Span* NewSpan(size_t k);

	std::mutex& getPageMutex() 
	{
		return _pageMtx;
	}

private:
	SpanList _SpanLists[NPAGES];	// pageCache
	std::mutex _pageMtx;			// pc�������

	PageCache()
	{ }

	PageCache(const PageCache& pc) = delete;
	PageCache& operator= (const PageCache& pc) = delete;
	static PageCache _sInst;	// ���������
};
