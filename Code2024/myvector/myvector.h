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
		typedef const T* const_iterator;

		//构造函数1
		myvector()
			:_start(nullptr)
			,_finish(nullptr)
			, _end_of_storage(nullptr)
		{

		}

		//构造函数2
		template<class InputIterator>   //模板函数
		myvector(InputIterator first,InputIterator last)
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{
			//将迭代器区间在[first,last)的数据一个个尾插到容器当中
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		//构造函数3
		vector(size_t n,const T& val=T())
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{
			reserve(n);           //调用reserve函数将容器容量设置为n
			for (size_t i = 0; i < n, i++)
			{
				push_back(val);   //尾插n个值为val的数据到容器当中
			}
		}

		vector(long n, const T& val=T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);           //调用reserve函数将容器容量设置为n
			for (size_t i = 0; i < n, i++)
			{
				push_back(val);   //尾插n个值为val的数据到容器当中
			}
		}

		vector(int n, const T& val=T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);           //调用reserve函数将容器容量设置为n
			for (size_t i = 0; i < n, i++)
			{
				push_back(val);   //尾插n个值为val的数据到容器当中
			}
		}

		//拷贝构造(传统写法)
#if 0
		myvector(const myvector<T>& v)
		{
			_start = new T[v.capacity()];    //开辟一块和容器v大小相同的空间
			for (size_t i = 0; i < v.size(); i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();    //容器有效数据的尾
			_end_of_storage = _start + v.capacity(); //整个容器的尾
		}
#endif
		//拷贝构造(现代写法)
		myvector(const myvector<T>& v)
		{
			reserve(v.capacity()); //调用reserve函数将容器设置为与v相同
			for (auto e : v)
			{
				push_back(e);
			}
		}

		//赋值运算符重载函数
		// 写法一：传统写法
		myvector<T>& operator=(const myvector<T>& v)
		{
			if (*this != &v)    //*this为左操作数，v为右操作数
			{
				delete[] _start;  //释放原来的空间
				_start = new T[v.capacity()];
				for (size_t i = 0; i < v.size(); i++)
				{
					_start[i] = v._start[i];
				}
				_finish = _start + v.size();
				_end_of_storage = _start + v.capacity();
			}
			return*this;  //支持连续赋值
		}

#if 0
		// 写法二：现代写法
		myvector<T>& operator=(myvector<T> v)
		{
			swap(v);       //支持这两个对象
			return *this;  //支持连续赋值
		}
#endif

		//析构函数
		~myvector()
		{
			if (_start)
			{
				delete[] _start;  //释放容器存储数据的空间
				_start = nullptr;
				_finish = nullptr;
				_end_of_storage = nullptr;
			}
		}

		//迭代器相关参数
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;  //返回容器当中有效数据的下一个数据的地址
		}
		
		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end()const
		{
			return _finish;
		}

		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _end_of_storage - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();  //记录当前容器当中有效数据的个数
				T* tmp = new T[sz];  //开辟一块可以容纳n个数据的空间
				if (_start)
				{
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;  //将容器本身存储数据的空间释放
				}
				_start = tmp;  //将tmp维护的数据交给_start进行维护
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, const  T& val = T())
		{
			if (n < size()) //当n小于当前的size时
			{
				_finish = _start + n;
			}
			else  //当n大于当前的size时
			{
				//判断是否需要增容
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish < _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}
	private:
		iterator _start;		 // 指向数据块的开始
		iterator _finish;		 // 指向有效数据的尾
		iterator _end_of_storage;  // 指向存储容量的尾
	};
}

