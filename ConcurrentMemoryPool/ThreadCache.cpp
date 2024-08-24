#include "ThreadCache.h"
#include "CentralCache.h"
#include "PageCache.h"

void* ThreadCache::Allocate(size_t size)
{
	assert(size <= MAX_BYTES);

	// 计算多少字节对齐
	size_t alignSize = SizeClass::RoundUp(size);
	// 计算在第几号桶
	size_t index = SizeClass::Index(size);

	if (!_freeLists[index].Empty())
	{
		// 自由链表不为空，可以直接从自由链表中获取空间
		return _freeLists[index].Pop();
	}
	else
	{
		return FetchFromCentralCache(index, alignSize);
	}
}

void ThreadCache::Deallocate(void* ptr, size_t size)
{
	// 回收线程中大小为size的obj空间
	assert(ptr);
	assert(size <= MAX_BYTES);

	// 找出映射的自由链表桶，对象插入进去
	size_t index = SizeClass::Index(size);
	_freeLists[index].Push(ptr);

	// 当链表长度大于一次批量申请的内存时就开始还一段list给central cache
	if (_freeLists[index].Size() >= _freeLists[index].MaxSize())
	{
		ListTooLong(_freeLists[index], size);
	}
}

// ThreadCache中空间不够时，像CentralCache申请空间的接口
void* ThreadCache::FetchFromCentralCache(size_t index, size_t size)
{
	// 慢开始反馈调节算法
#ifdef WIN32
	size_t batchNum = min(_freeLists[index].MaxSize(), SizeClass::NumMoveSize(size));
	// MaxSize表示index位置的自由链表单次申请未到上限时，能够申请的最大块空间是多少(一块能申请多大)
	// NumMoveSize表示tc单次向cc申请alignSize大小的空间块的最多块数是多少(最多能申请几块)
#else
	size_t batchNum = std::min(_freeLists[index].MaxSize(), SizeClass::NumMoveSize(size));
#endif

	if (_freeLists[index].MaxSize() == batchNum)
	{
		// 如果没有达到上限，那下次再申请这样的空间的时候可以再多申请一块
		_freeLists[index].MaxSize() += 1;
	}

	void* start = nullptr;
	void* end = nullptr;

	size_t actualNum = CentralCache::GetInstace()->FetchRangeObj(start, end, batchNum, size);
	assert(actualNum > 0);

	if (actualNum == 1)
	{
		assert(start == end);
		{
			return start;
		}
	}
	else
	{
		_freeLists[index].PushRange(NextObj(start), end, actualNum - 1);
		return start;
	}
}

void ThreadCache::ListTooLong(FreeList& list, size_t size)
{
	void* start = nullptr;
	void* end = nullptr;
	list.PopRange(start, end, list.MaxSize());

	CentralCache::GetInstace()->ReleaseListToSpans(start, size);
}
