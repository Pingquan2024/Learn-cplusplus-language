#include "PageCache.h"
#include "Common.h"

PageCache PageCache::_sInst;	// 单例对象

// 获取一个k页的span
Span* PageCache::NewSpan(size_t k)
{
	assert(k > 0 && k < NPAGES);

	//GetInstance()->_pageMtx.lock();

	// 先检查第k个桶里面有没有span
	if (!_SpanLists[k].Empty())
	{
		Span* span =  _SpanLists->PopFront();

		// 记录分配出去的span管理的页号和其地址的映射关系
		for (PAGE_ID i = 0; i < span->_n; i++)
		{
			// i是Page_ID类型，不然在64位下和_pageID相加会报警告
			_idSpanMap[span->_pageID + i] = span;
		}

		return span;
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

			// 再把n-k页的span边缘页映射一下，方便后续合并
			_idSpanMap[nSpan->_pageID] = nSpan;
			_idSpanMap[nSpan->_pageID + nSpan->_n - 1] = nSpan;


			// 记录分配出去的span管理的页号和其地址的映射关系
			for (PAGE_ID i = 0; i < kSpan->_n; i++)
			{
				// i是Page_ID类型，不然在64位下和_pageID相加会报警告
				_idSpanMap[kSpan->_pageID + i] = kSpan;
			}

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

// 通过地址找到span
Span* PageCache::MapObjectToSpan(void* obj)
{
	PAGE_ID id = (((PAGE_ID)obj) >> PAGE_SHIFT);

	// 智能锁
	std::unique_lock<std::mutex> lc(PageCache().getPageMutex());
	// 通过哈希找到页号对应的span
	auto ret = _idSpanMap.find(id);

	if (ret != _idSpanMap.end())
	{
		return ret->second;
	}
	else
	{
		assert(false);
		return nullptr;
	}
}


void PageCache::ReleaseSpanToPageCache(Span* span) 
{
	// 向左不断合并
	while(true)
	{
		PAGE_ID leftID = span->_pageID - 1;
		auto ret = _idSpanMap.find(leftID);

		// 没有相邻span停止合并
		if (ret == _idSpanMap.end())
		{
			break;
		}

		Span* leftSpan = ret->second;
		// 相邻span在centralCache中，停止合并
		if (leftSpan->_isUse == true)
		{
			break;
		}

		//相邻span与当前span合并后超过128页，停止合并
		if (leftSpan->_n + span->_n > PAGE_SHIFT)
		{
			break;
		}

		// 当前span与相邻span进行合并
		span->_pageID = leftSpan->_pageID;
		span->_n += leftSpan->_n;

		_SpanLists[leftSpan->_n].Erase(leftSpan);	// 将相邻对象从桶中删除
		delete leftSpan;
	}

	// 向右不断合并
	while(true)
	{
		PAGE_ID rightID = span->_pageID + span->_n;
		auto it = _idSpanMap.find(rightID);

		// 没有相邻span停止合并
		if (it == _idSpanMap.end())
		{
			break;
		}

		Span* rightSpan = it->second;
		// 相邻span在centralCache中，停止合并
		if (rightSpan->_isUse == true)
		{
			break;
		}

		//相邻span与当前span合并后超过128页，停止合并
		if (rightSpan->_n + span->_n > PAGE_SHIFT - 1)
		{
			break;
		}

		// 当前span与相邻span进行合并
		span->_n += rightSpan->_n;

		_SpanLists[rightSpan->_n].Erase(rightSpan);	// 将相邻对象从桶中删除
		delete rightSpan;
	}

	// 合共完毕，将当前span挂在对应桶中
	_SpanLists[span->_n].PushFront(span);
	span->_isUse = false;	// 从cc返回到pc，isUse改成false

	// 映射当前span的边缘页，后续还可以对这个span合并
	_idSpanMap[span->_pageID] = span;
	_idSpanMap[span->_pageID + span->_n - 1] = span;

}
