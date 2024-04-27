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
		typedef const T* const_iterator;

		//���캯��1
		myvector()
			:_start(nullptr)
			,_finish(nullptr)
			, _end_of_storage(nullptr)
		{

		}

		//���캯��2
		template<class InputIterator>   //ģ�庯��
		myvector(InputIterator first,InputIterator last)
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{
			//��������������[first,last)������һ����β�嵽��������
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		//���캯��3
		vector(size_t n,const T& val=T())
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{
			reserve(n);           //����reserve������������������Ϊn
			for (size_t i = 0; i < n, i++)
			{
				push_back(val);   //β��n��ֵΪval�����ݵ���������
			}
		}

		vector(long n, const T& val=T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);           //����reserve������������������Ϊn
			for (size_t i = 0; i < n, i++)
			{
				push_back(val);   //β��n��ֵΪval�����ݵ���������
			}
		}

		vector(int n, const T& val=T())
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(n);           //����reserve������������������Ϊn
			for (size_t i = 0; i < n, i++)
			{
				push_back(val);   //β��n��ֵΪval�����ݵ���������
			}
		}

		//��������(��ͳд��)
#if 0
		myvector(const myvector<T>& v)
		{
			_start = new T[v.capacity()];    //����һ�������v��С��ͬ�Ŀռ�
			for (size_t i = 0; i < v.size(); i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();    //������Ч���ݵ�β
			_end_of_storage = _start + v.capacity(); //����������β
		}
#endif
		//��������(�ִ�д��)
		myvector(const myvector<T>& v)
		{
			reserve(v.capacity()); //����reserve��������������Ϊ��v��ͬ
			for (auto e : v)
			{
				push_back(e);
			}
		}

		//��ֵ��������غ���
		// д��һ����ͳд��
		myvector<T>& operator=(const myvector<T>& v)
		{
			if (*this != &v)    //*thisΪ���������vΪ�Ҳ�����
			{
				delete[] _start;  //�ͷ�ԭ���Ŀռ�
				_start = new T[v.capacity()];
				for (size_t i = 0; i < v.size(); i++)
				{
					_start[i] = v._start[i];
				}
				_finish = _start + v.size();
				_end_of_storage = _start + v.capacity();
			}
			return*this;  //֧��������ֵ
		}

#if 0
		// д�������ִ�д��
		myvector<T>& operator=(myvector<T> v)
		{
			swap(v);       //֧������������
			return *this;  //֧��������ֵ
		}
#endif

		//��������
		~myvector()
		{
			if (_start)
			{
				delete[] _start;  //�ͷ������洢���ݵĿռ�
				_start = nullptr;
				_finish = nullptr;
				_end_of_storage = nullptr;
			}
		}

		//��������ز���
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;  //��������������Ч���ݵ���һ�����ݵĵ�ַ
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
				size_t sz = size();  //��¼��ǰ����������Ч���ݵĸ���
				T* tmp = new T[sz];  //����һ���������n�����ݵĿռ�
				if (_start)
				{
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;  //����������洢���ݵĿռ��ͷ�
				}
				_start = tmp;  //��tmpά�������ݽ���_start����ά��
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, const  T& val = T())
		{
			if (n < size()) //��nС�ڵ�ǰ��sizeʱ
			{
				_finish = _start + n;
			}
			else  //��n���ڵ�ǰ��sizeʱ
			{
				//�ж��Ƿ���Ҫ����
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
		iterator _start;		 // ָ�����ݿ�Ŀ�ʼ
		iterator _finish;		 // ָ����Ч���ݵ�β
		iterator _end_of_storage;  // ָ��洢������β
	};
}

