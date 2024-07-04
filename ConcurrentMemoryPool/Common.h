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
static const size_t FREELIST_SUM = 208;		// 256kb���ܹ�����208��Ͱ
static const size_t NPAGES = 129;
static const size_t PAGE_SHIFT = 13;		// page���ת��

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

// ֱ��ȥ���ϰ�ҳ����ռ�
inline static void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage << 13, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// linux��brk mmap��
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

// �����зֺõ�С����������б�
class FreeList
{
public:

	void Push(void* obj)
	{
		// ͷ��
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
		// ͷɾ
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

// ��������С�Ķ���ӳ�����
class SizeClass
{
	// �ڴ���Ƭ�˷ѿ�����10%
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

	//// ����ӳ�����һ����������Ͱ
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

	// ����ӳ�����һ����������Ͱ
	static inline size_t Index(size_t bytes)
	{
		assert(bytes <= MAX_BYTES);

		// ÿ�������ж��ٸ���
		static int group_array[4] = { 16,56,56,56 };
		if (bytes <= 128)
		{
			return _Index(bytes, 3);	 // 8�ֽڶ���
		}
		else if (bytes <= 1024)
		{
			return _Index(bytes - 128, 4) + group_array[0];		// 16�ֽڶ���
		}
		else if (bytes <= 8 * 1024)		 
		{
			return _Index(bytes - 1024, 7) + group_array[0] + group_array[1];		// 128�ֽڶ���
		}
		else if (bytes <= 64 * 1024)
		{
			return _Index(bytes - 8 * 1024, 10) + group_array[0] + group_array[1] 
				+ group_array[2];		// 1024�ֽڶ���
		}
		else if (bytes <= 256 * 1024)
		{
			return _Index(bytes - 64 * 1024, 13) + group_array[0] + group_array[1] 
				+ group_array[2] + group_array[3];		// 8*1024�ֽڶ���
		}
		else
		{
			assert(false);
		}
		return -1;
	}

	// һ��thread cache��central cache�����ȡ���ٸ�
	static size_t NumMoveSize(size_t size)
	{
		assert(size > 0);

		// [2,512] һ�������ƶ����ٸ����������ֵ
		int num = MAX_BYTES / size;
		if (num < 2)
			num = 2;
		if (num > 512)
			num = 512;

		return num;
	}

	// ����һ����ϵͳ��ȡ��ҳ
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

// ����������ҳ����ڴ��Ƚṹ
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

	PAGE_ID _pageID;		// ����ڴ���ʼҳ��ҳ��
	size_t _n;				// ҳ������

	Span* _next;				// ˫������Ľṹ
	Span* _prev;

	size_t _useCount;		// �к�С���ڴ棬�������thread cache�ļ���
	void* _freeList;        // �кõ�С���ڴ����������
};

// ��ͷ˫��ѭ������
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