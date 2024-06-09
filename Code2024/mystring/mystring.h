#pragma once

#include <iostream>
#include <cstring>
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
		{
			_size = (strlen(str));
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

		Mystring& operator=(Mystring s)
		{
			swap(s);
			return *this;
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

		size_t size()const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		void resize(size_t newSize, char c = '\0')
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

		bool empty()const
		{
			return 0 == _size;
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

		Mystring erase(size_t pos, size_t len = string::npos)
		{
			assert(pos < _size);
			size_t n = _size - pos;
			if (len >= n)
			{
				_size = pos;
				_str[_size] = '\0';
			}
			else
			{
				strcpy(_str + pos, _str + pos + len); //用需要保留的有效字符覆盖需要删除的有效字符
				_size -= len; //size更新
			}
			return *this;
		}

		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		void swap(Mystring& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
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

		//正向查找第一个匹配的字符
		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size); //检测下标的合法性
			for (size_t i = pos; i < _size; i++) //从pos位置开始向后寻找目标字符
			{
				if (_str[i] == ch)
				{
					return i; //找到目标字符，返回其下标
				}
			}
			return string::npos; //没有找到目标字符，返回npos
		}

		//反向查找第一个匹配的字符
		size_t rfind(char ch, size_t pos = string::npos)
		{
			Mystring tmp(*this); //拷贝构造对象tmp
			reverse(tmp.begin(), tmp.end()); //调用reverse逆置对象tmp的C字符串
			if (pos >= _size) //所给pos大于字符串有效长度
			{
				pos = _size - 1; //重新设置pos为字符串最后一个字符的下标
			}
			pos = _size - 1 - pos; //将pos改为镜像对称后的位置
			size_t ret = tmp.find(ch, pos); //复用find函数
			if (ret != string::npos)
				return _size - 1 - ret; //找到了，返回ret镜像对称后的位置
			else
				return string::npos; //没找到，返回npos
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

		//>运算符重载
		bool operator>(const Mystring& s)const
		{
			return strcmp(_str, s._str) > 0;
		}
		//==运算符重载
		bool operator==(const Mystring& s)const
		{
			return strcmp(_str, s._str) == 0;
		}

		//>=运算符重载
		bool operator>=(const Mystring& s)const
		{
			return (*this > s) || (*this == s);
		}
		//<运算符重载
		bool operator<(const Mystring& s)const
		{
			return !(*this >= s);
		}
		//<=运算符重载
		bool operator<=(const Mystring& s)const
		{
			return !(*this > s);
		}
		//!=运算符重载
		bool operator!=(const Mystring& s)const
		{
			return !(*this == s);
		}

		//读取一行含有空格的字符串
		istream& getline(istream& in, Mystring& s)
		{
			s.clear(); //清空字符串
			char ch = in.get(); //读取一个字符
			while (ch != '\n') //当读取到的字符不是'\n'的时候继续读取
			{
				s += ch; //将读取到的字符尾插到字符串后面
				ch = in.get(); //继续读取字符
			}
			return in;
		}


	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};

	//>>运算符的重载
	istream& operator>>(istream& in, string& s)
	{
		s.clear(); //清空字符串
		char ch = in.get(); //读取一个字符
		while (ch != ' ' && ch != '\n') //当读取到的字符不是空格或'\n'的时候继续读取
		{
			s += ch; //将读取到的字符尾插到字符串后面
			ch = in.get(); //继续读取字符
		}
		return in; //支持连续输入
	}

	//<<运算符的重载
	ostream& operator<<(ostream& out, const string& s)
	{
		//使用范围for遍历字符串并输出
		for (auto e : s)
		{
			cout << e;
		}
		return out; //支持连续输出
	}
}
