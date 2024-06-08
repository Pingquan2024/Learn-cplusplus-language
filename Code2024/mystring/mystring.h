#pragma once

#include <iostream>
#include <string.h>
#include <assert.h>
#include <vector>

using namespace std;

namespace mystring
{
	class Mystring
	{
	public:

		typedef char* iterator;
		typedef const char* const_iterator;

		//构造函数
		Mystring(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size == 0 ? 3 : _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//拷贝构造
		Mystring(const Mystring& s)
			//初始化列表
			:_str(nullptr)
			, _capacity(0)
			, _size(0)
		{
			Mystring tmp(s._str);
			this->swap(tmp);
		}

		~Mystring()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		Mystring operator=(Mystring s)
		{
			this->swap(s);
			return *this;
		}

		Mystring& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		Mystring& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void append(const char* str)
		{
			//追加
			size_t  len = strlen(str);
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			strncpy(_str + _size, _str, len);
		}

		void swap(Mystring& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		const char* c_str()const
		{
			return _str;
		}

		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		//iterator
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		//const_iterator
		const_iterator begin()const
		{
			return _str;
		}

		const_iterator end()const
		{
			return _str + _size;
		}

		void push_back(char c)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}

			_str[_size++] = c;
			_str[_size] = '\0';
		}

		void resize(size_t newSize,char c='\0')
		{
			if (newSize > _size)
			{
				// 如果newSize大于底层空间大小，则需要重新开辟空间
				if (newSize > _capacity)
				{
					reserve(newSize);
				}
				
				memset(_str + _size, c, newSize - _size);
			}

			_size = newSize;
			_str[newSize] = '\0';
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			size_t len = strlen(str);

			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			//挪动数据
			size_t end = _size + len;
			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				--end;
			}

			//拷贝输入
			strncpy(_str + pos, str, len);
			_size += len;
		}

		size_t size()const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		bool empty()const
		{
			return 0 == _size;
		}

		bool operator>(const string& s)const
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator>=(const string& s)const
		{
			return *this > s || (s == *this);
		}

		bool operator<(const string& s) const
		{
			return !(*this >= s);
		}

		bool operator<=(const string& s) const
		{
			return !(*this > s);
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
