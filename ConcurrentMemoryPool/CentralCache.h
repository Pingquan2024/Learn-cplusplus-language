#pragma once

#include "Common.h"

// ����ģʽ
class CentralCache
{
public:
	static CentralCache* GetInstace()
	{
		return &_sInst;
	}

	// �����Ļ����ȡһ�������Ķ����thread cache
	size_t FetchRangeObj(void*& start, void*& end, size_t batchNum, size_t size);

	// ��ȡһ���ǿյ�span
	Span* GetOneSpan(SpanList& list, size_t size);

private:
	SpanList _spanLists[FREELIST_SUM];

private:
	CentralCache()
	{ }

	CentralCache(const CentralCache&) = delete;
	 
	static CentralCache _sInst;
};

