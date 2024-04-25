#pragma once
#include <iostream>

//template < class T, class Alloc = allocator<T> > class vector; // generic template
namespace me
{
	class myvector
	{
		//构造函数
		myvector()
		{

		}

		//拷贝构造
		myvector(const myvector& v)
		{

		}

		//析构函数
		~myvector()
		{

		}

	private:

		int _size;
		int _capacity;
	};
}

