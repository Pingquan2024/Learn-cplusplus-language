#pragma once

#include "Common.h"

class ThreadCache
{

public:
	void* Allocate(size_t size);		// 申请内存对象

	void Deallocate(void* ptr, size_t size);		// 回收线程中大小为size的obj空间

	void* FetchFromCentralCache(size_t index, size_t size);		// 从中心缓存获取对象

	void ListTooLong(FreeList& list, size_t size);				// 释放对象时，链表过长时，回收一个批量的内存到中心central cache

private:
	FreeList _freeLists[FREELIST_SUM];		// 哈希，每个桶表示一个自由链表
};


static _declspec(thread) ThreadCache* pTLSThreadCache = nullptr;

