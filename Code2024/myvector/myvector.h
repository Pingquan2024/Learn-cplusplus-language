#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

//template < class T, class Alloc = allocator<T> > class vector; // generic template
namespace me
{
	template<class T>
	class myvector
	{
	public:
		// Vector�ĵ�������һ��ԭ��ָ��
		typedef T* iterator;

		//���캯��
		myvector(int _size=0,int _capacity=0)
			//_size=new int[]
		{

		}

		//��������
		myvector(const myvector& v)
		{

		}

		//��������
		~myvector()
		{

		}

	private:

		int _size;
		int _capacity;

		iterator _start;		// ָ�����ݿ�Ŀ�ʼ
		iterator _finish;		// ָ����Ч���ݵ�β
		iterator _endOfStorage;  // ָ��洢������β
	};
}

