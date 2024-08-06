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
static const size_t NPAGES = 129;			// 多开一个，1号桶（下标1）映射的就是1页的span，n号桶（下标n）映射的就是n页的span。
static const size_t PAGE_SHIFT = 13;		// page间的转换

#ifdef _WIN32
	#include <windows.h>
#else
// ...
#endif

typedef size_t PAGE_ID;

// 直接去堆上按页申请空间
inline static void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage << PAGE_SHIFT, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
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

		++_size;
	}

	void PushRange(void*start, void* end,size_t n)
	{
		NextObj(end) = _freeList;
		_freeList = start;

		_size += n;
	}

	void* Pop()
	{
		// 头删
		assert(_freeList);
		void* obj = _freeList;		// 从 _freeList 获取当前链表头部的指针，并将其赋值给 obj
		_freeList = NextObj(obj);
		--_size;

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

	size_t Size()
	{
		return _size;
	}

	void PopRange(void*& start, void*& end, size_t n)
	{
		assert(n <= _size);
		start = _freeList;
		end = start;

		for (size_t i = 0; i < n - 1; ++i)
		{
			end = NextObj(end);
		}

		_freeList = NextObj(end);
		NextObj(end) = nullptr;
		_size -= n;
	}

private:
	void* _freeList = nullptr;	// 哈希桶中每个桶是一个自由链表

	size_t _size = 0;
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

	static inline size_t RoundUp(size_t size)	// 计算对齐字节数
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
			// 不可能的情况，这里通过threadCache申请空间不会超过256kb
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
		size_t num = NumMoveSize(size);	 //NumMoveSize是算出threadCache向centralCache申请size大小的块时的单次最大申请块数
		size_t npage = num * size;	// 单词申请最大空间的大小

		// PAGE_SHIFT表示一页要占用多少位，比如一页8kb就是13位，这里右移就是除于页大小，算出来就是单次申请最大空间有多少页
		npage >>= PAGE_SHIFT;
		if (npage == 0)
			npage = 1;

		return npage;
	}
};

// 管理以页为单位的结构体
class Span
{
public:
	Span()
		:_pageID(0)
		,_n(0)
		,_next(nullptr)
		,_prev(nullptr)
		,_useCount(0)
		,_freeList(nullptr)
		,_objSize(0)
		,_maxSize(1)
	{ }

	size_t& MaxSize()
	{
		return _maxSize;
	}

	PAGE_ID _pageID;		// 大块内存起始页的页号
	size_t _n;				// 页的数量

	Span* _next;				// 双向链表的结构
	Span* _prev;

	size_t _useCount;		// 切好小块内存，被分配给thread cache的计数
	void* _freeList;        // 每个span下面挂的小块空间的头节点
	size_t _objSize;
private:
	size_t _maxSize;		// 当前自由链表申请未达到上限时，能够申请的最大空间是多少
};

// 带头双向循环链表，这里SpanList就是CentralCache中的哈希桶
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
		assert(pos != _head);	// pos不能是哨兵位

		// prev pos next
		Span* prev = pos->_prev;
		Span* next = pos->_next;
		
		prev->_next = next;
		next->_prev = prev;
		// pos节点不需要调用delete删除，因为pos节点的Span需要回收，而不是直接删掉
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
		Span* front = _head->_next;	// 先获取到_head后面的第一个span
		Erase(front);
		return front;
	}

	bool Empty()
	{
		return _head->_next == _head;
	}


private:
	Span* _head;	// 哨兵位头节点
public:
	std::mutex _mtx;	// 每个CentralCache中的哈希桶都要有一个桶锁
};