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

	void ReleaseListToSpans(void* start, size_t byte_size);		// ��һ�������Ķ����ͷŵ�span���

private:
	SpanList _spanLists[FREELIST_SUM];	// ��ϣͰ�йҵ���һ����Span

private:
	// ����ģʽ��ȥ�����졢��������Ϳ�����ֵ
	CentralCache()
	{ }

	CentralCache(const CentralCache& copy) = delete;
	CentralCache& operator=(const CentralCache& copy) = delete;
	 
	static CentralCache _sInst;	// ����ģʽ����һ��CentralCache
};

