#pragma once

#include "Common.h"

class ThreadCache
{

public:
	void* Allocate(size_t size);		// �����ڴ����

	void Deallocate(void* ptr, size_t size);		// �ͷ��ڴ����

	void* FetchFromCentralCache(size_t index, size_t size);		// �����Ļ����ȡ����

	void ListTooLong(FreeList& list, size_t size);				// �ͷŶ���ʱ���������ʱ������һ���������ڴ浽����central cache

private:
	FreeList _freeLists[FREELIST_SUM];
};


static _declspec(thread) ThreadCache* pTLSThreadCache = nullptr;

