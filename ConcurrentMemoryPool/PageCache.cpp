#include "PageCache.h"

PageCache PageCache::_sInst;	// 单例对象

// 获取一个k页的span
Span* PageCache::NewSpan(size_t k)
{
	assert(k > 0 && k < NPAGES);

	//GetInstance()->_pageMtx.lock();

	// 先检查第k个桶里面有没有span
	if (!_SpanLists[k].Empty())
	{
		return _SpanLists->PopFront();
	}

	// 检查一下后面的桶里有没有span，如果有则进行切分
	for (int i = k + 1; i < NPAGES; i++)
	{
		// [k + 1, NPAGES - 1]号桶中有没有span
		if (!_SpanLists[i].Empty())
		{
			// 找到了
			Span* nSpan = _SpanLists[i].PopFront();
			Span* kSpan = new Span;	// span的空间是需要新建的，而不是用当前内存池中的空间

			// 在span的头部切一个span下来
			// k页Span返回
			// nSpan再挂到对应的映射上

			kSpan->_pageID = nSpan->_pageID;
			kSpan->_n = k;

			nSpan->_pageID += k;
			nSpan->_n -= k;
			_SpanLists[nSpan->_n].PushFront(nSpan);

			return kSpan;
		}
	}

	// 走到这说明后面没有大页的Span
	// 向系统堆上申请128页的大内存
	Span* bigSpan = new Span;
	void* ptr = SystemAlloc(NPAGES - 1);
	bigSpan->_pageID = (PAGE_ID)ptr >> PAGE_SHIFT;
	bigSpan->_n = NPAGES - 1;

	_SpanLists[bigSpan->_n].PushFront(bigSpan);

	// 递归再次申请k页的span，这次递归一定会走 k号桶没有span，但后面的桶中有span
	return NewSpan(k);	// 复用代码
}