#pragma once

// �����ڴ�أ�����أ�
#include "Common.h"

template<class T>
class ObjectPool
{
public:
	T* New()
	{
		T* obj = nullptr;
		if (_freeList)
		{
			void* next = *((void**)_freeList);
			obj = (T*)_freeList;
			_freeList = next;
		}
		else
		{
			// ��ʣ����ڴ治��һ�������Сʱ�����¿�һ�����ռ�
			if (_remainBytes < sizeof(T))
			{
				_remainBytes = 128 * 1024;
				_memory = (char*)malloc(_remainBytes);
				if (_memory == nullptr)
				{
					throw std::bad_alloc();		// �׳�һ��bad_alloc�Ķ���
				}
			}

			obj = (T*)_memory;
			size_t objSize = sizeof(T) < sizeof(void*) ? sizeof(void*) : sizeof(T);
			_memory += objSize;		// �г�һ��T����
			_remainBytes -= objSize;
		}

		// ��λnew����ʾ����T�Ĺ��캯����ʼ��
		new(obj)T;

		return obj;
	}

	void Delete(T* obj)
	{
		// ��ʾ�������������������
		obj->~T();

		//ͷ��
		*(void**)obj = _freeList;
		_freeList = obj;
	}

private:
	char* _memory = nullptr;		// ָ�����ڴ��ָ��
	void* _freeList = nullptr;		// �����б�ͷ�ڵ�
	size_t _remainBytes = 0;		// �зֺ�ʣ����ֽ���
};
