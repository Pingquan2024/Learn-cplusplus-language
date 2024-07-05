#pragma once

#include "Common.h"

class ThreadCache
{

public:
	void* Allocate(size_t size);		// 申请内存对象

	void Deallocate(void* ptr, size_t size);		// 释放内存对象

	void* FetchFromCentralCache(size_t index, size_t size);		// 从中心缓存获取对象

	void ListTooLong(FreeList& list, size_t size);				// 释放对象时，链表过长时，回收一个批量的内存到中心central cache

private:
	FreeList _freeLists[FREELIST_SUM];
};


static _declspec(thread) ThreadCache* pTLSThreadCache = nullptr;

