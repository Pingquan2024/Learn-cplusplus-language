#pragma once

#include "Common.h"

// 单例模式
class CentralCache
{
public:
	static CentralCache* GetInstace()
	{
		return &_sInst;
	}

	// 从中心缓存获取一定数量的对象给thread cache
	size_t FetchRangeObj(void*& start, void*& end, size_t batchNum, size_t size);

	// 获取一个非空的span
	Span* GetOneSpan(SpanList& list, size_t size);

	void ReleaseListToSpans(void* start, size_t byte_size);		// 将一定数量的对象释放到span跨度

private:
	SpanList _spanLists[FREELIST_SUM];

private:
	CentralCache()
	{ }

	CentralCache(const CentralCache&) = delete;
	 
	static CentralCache _sInst;
};

