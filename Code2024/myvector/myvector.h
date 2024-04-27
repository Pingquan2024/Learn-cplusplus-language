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
		// Vector的迭代器是一个原生指针
		typedef T* iterator;

		//构造函数
		myvector(int _size=0,int _capacity=0)
			//_size=new int[]
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

		iterator _start;		// 指向数据块的开始
		iterator _finish;		// 指向有效数据的尾
		iterator _endOfStorage;  // 指向存储容量的尾
	};
}

