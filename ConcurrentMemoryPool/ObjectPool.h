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


struct TreeNode
{
	int _val;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode()
		:_val(0)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

// �����ͷŵ��ִ�
const size_t Rounds = 5;

// ÿ�������ͷŶ��ٴ�
const size_t N = 100000;

void Test_Native_new()
{
	std::vector<TreeNode*> v1;
	v1.reserve(N);

	size_t begin1 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v1.push_back(new TreeNode);
		}
		for (int i = 0; i < N; ++i)
		{
			delete v1[i];
		}
		v1.clear();
	}
	size_t end1 = clock();

	cout << "new cost time:" << end1 - begin1 << endl;
}

void Test_ObjectPool()
{
	std::vector<TreeNode*> v2;
	v2.reserve(N);

	ObjectPool<TreeNode> TNPool;
	size_t begin2 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v2.push_back(TNPool.New());
		}
		for (int i = 0; i < N; ++i)
		{
			TNPool.Delete(v2[i]);
		}
		v2.clear();
	}
	size_t end2 = clock();

	cout << "Time required for fixed-length memory pools:" << end2 - begin2 << endl;
}


