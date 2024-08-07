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

	// ��ȡһ��kҳ��span��pc��_spanLists���ó���һ��kҳ��span
	Span* NewSpan(size_t k);

	//ͨ��ҳ��ַ�ҵ�span
	Span* MapObjectToSpan(void* obj);

	// ����central cache��������span
	void ReleaseSpanToPageCache(Span* span);

	std::mutex& getPageMutex() 
	{
		return _pageMtx;
	}

private:
	SpanList _SpanLists[NPAGES];	// pageCache
	std::mutex _pageMtx;			// pc�������
	// ��ϣӳ�䣬��������ͨ��ҳ���ҵ���Ӧ��span
	std::unordered_map<PAGE_ID, Span*> _idSpanMap;

	PageCache()
	{ }

	PageCache(const PageCache& pc) = delete;
	PageCache& operator= (const PageCache& pc) = delete;
	static PageCache _sInst;	// ���������
};
