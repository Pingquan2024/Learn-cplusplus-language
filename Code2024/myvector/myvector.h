#pragma once
#include <iostream>

//template < class T, class Alloc = allocator<T> > class vector; // generic template
namespace me
{
	class myvector
	{
		//���캯��
		myvector()
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
	};
}

