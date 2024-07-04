#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <cassert>
#include <time.h>

using std::cout;
using std::endl;

static const size_t MAX_BYTES = 25 * 1024;
static const size_t FREELIST_SUM = 208;		// 256kb下总共分了208个桶
static const size_t NPAGES = 129;
static const size_t PAGE_SHIFT = 13;		// page间的转换

#ifdef _WIN32
	#include <windows.h>
#else
// ...
#endif

#ifdef _WIN64
	typedef size_t PAGE_ID;
#elif _WIN32
	typedef unsigned long long PAGE_ID;	
#else
	// linux
#endif

// 直接去堆上按页申请空间
inline static void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage << 13, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// linux下brk mmap等
#endif

	if (ptr == nullptr)
	{
		throw std::bad_alloc();
	}

	return ptr;
}

static void*& NextObj(void* obj)
{
	return *(void**)obj;
}

// 管理切分好的小对象的自由列表
class FreeList
{
public:

	void Push(void* obj)
	{
		// 头插
		// *(void**)obj = _freeList;
		assert(obj);
		NextObj(obj) = _freeList;
		_freeList = obj;
	}

	void PushRange(void*start, void* end)
	{
		NextObj(end) = _freeList;
		_freeList = start;
	}

	void* Pop()
	{
		// 头删
		assert(_freeList);
		void* obj = _freeList;
		_freeList = NextObj(obj);
		return obj;
	}

	bool Empty()
	{
		return _freeList == nullptr;
	}

	size_t& MaxSize()
	{
		return _maxSize;
	}

private:
	void* _freeList = nullptr;

	size_t _maxSize = 1;
};

// 计算对象大小的对齐映射规则
class SizeClass
{
	// 内存碎片浪费控制在10%
public:
	//size_t _RoundUp(size_t size,size_t alignNum)
	//{
	//	size_t alignSize;
	//	if (size % alignNum != 0)
	//	{
	//		alignSize = (size / alignNum + 1) * alignNum;
	//	}
	//	else
	//	{
	//		alignSize = size;
	//	}
	//	return alignSize;
	//}

	static inline size_t _RoundUp(size_t bytes, size_t align)
	{
		return ((bytes+align - 1) & ~(align - 1));
	}

	static inline size_t RoundUp(size_t size)
	{
		if(size <= 128)
		{ 
			return _RoundUp(size, 8);
		}
		else if (size <= 1024)
		{ 
			return _RoundUp(size, 16);
		}
		else if(size <= 8*1024)
		{ 
			return _RoundUp(size, 128);
		}
		else if(size <= 64*1024)
		{ 
			return _RoundUp(size, 1024);
		}
		else if(size <= 256*1024)
		{ 
			return _RoundUp(size, 8 * 1024);
		}
		else
		{
			assert(false);
			return -1;
		}
	}

	//// 计算映射的哪一个自由链表桶
	//size_t _Index(size_t bytes, size_t alignNum)
	//{
	//	if (bytes % alignNum == 0)
	//	{
	//		return bytes / alignNum - 1;
	//	}
	//	else
	//	{
	//		return bytes / alignNum; 
	//	}
	//}

	static inline size_t _Index(size_t bytes, size_t align_shift)
	{
		return ((bytes + (1 << align_shift) - 1) >> align_shift) - 1;
	}

	// 计算映射的哪一个自由链表桶
	static inline size_t Index(size_t bytes)
	{
		assert(bytes <= MAX_BYTES);

		// 每个区间有多少个链
		static int group_array[4] = { 16,56,56,56 };
		if (bytes <= 128)
		{
			return _Index(bytes, 3);	 // 8字节对齐
		}
		else if (bytes <= 1024)
		{
			return _Index(bytes - 128, 4) + group_array[0];		// 16字节对齐
		}
		else if (bytes <= 8 * 1024)		 
		{
			return _Index(bytes - 1024, 7) + group_array[0] + group_array[1];		// 128字节对齐
		}
		else if (bytes <= 64 * 1024)
		{
			return _Index(bytes - 8 * 1024, 10) + group_array[0] + group_array[1] 
				+ group_array[2];		// 1024字节对齐
		}
		else if (bytes <= 256 * 1024)
		{
			return _Index(bytes - 64 * 1024, 13) + group_array[0] + group_array[1] 
				+ group_array[2] + group_array[3];		// 8*1024字节对齐
		}
		else
		{
			assert(false);
		}
		return -1;
	}

	// 一次thread cache从central cache缓存获取多少个
	static size_t NumMoveSize(size_t size)
	{
		assert(size > 0);

		// [2,512] 一次批量移动多少个对象的上限值
		int num = MAX_BYTES / size;
		if (num < 2)
			num = 2;
		if (num > 512)
			num = 512;

		return num;
	}

	// 计算一次向系统获取几页
	static size_t NumMovePage(size_t size)
	{
		size_t num = NumMoveSize(size);
		size_t npage = num * size;

		npage >>= PAGE_SHIFT;
		if (npage == 0)
			npage = 1;

		return npage;
	}
};

// 管理多个连续页大块内存跨度结构
struct Span
{
	Span()
		:_pageID(0)
		,_n(0)
		,_next(nullptr)
		,_prev(nullptr)
		,_useCount(0)
		,_freeList(nullptr)
	{ }

	PAGE_ID _pageID;		// 大块内存起始页的页号
	size_t _n;				// 页的数量

	Span* _next;				// 双向链表的结构
	Span* _prev;

	size_t _useCount;		// 切好小块内存，被分配给thread cache的计数
	void* _freeList;        // 切好的小块内存的自由链表
};

// 带头双向循环链表
class SpanList
{
public:
	SpanList()
	{
		_head = new Span;
		_head->_next = _head;
		_head->_prev = _head;
	}

	void Insert(Span* pos, Span* newSpan)
	{
		assert(pos);
		assert(newSpan);

		Span* prev = pos->_prev;
		// prev newSpan pos
		prev->_next = newSpan;
		newSpan->_prev = prev;
		newSpan->_next = pos;
		pos->_prev = newSpan;
	}

	void Erase(Span* pos)
	{
		assert(pos);
		assert(pos != _head);

		// prev pos next
		Span* prev = pos->_prev;
		Span* next = pos->_next;
		
		prev->_next = next;
		next->_prev = prev;
	}

	Span* Begin()
	{
		return _head->_next;
	}

	Span* End()
	{
		return _head;
	}

	void PushFront(Span* span)
	{
		Insert(Begin(), span);
	}

	Span* PopFront()
	{
		Span* front = _head->_next;
		Erase(front);
		return front;
	}

	bool Empty()
	{
		return _head->_next == _head;
	}


private:
	Span* _head;
public:
	std::mutex _mtx;
};