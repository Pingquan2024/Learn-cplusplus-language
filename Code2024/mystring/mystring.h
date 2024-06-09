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

		//���캯��
		Mystring(const char* str = "")
		{
			_size = (strlen(str));
			_capacity = _size == 0 ? 3 : _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//��������
		Mystring(const Mystring& s)
			//��ʼ���б�
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
				// ���newSize���ڵײ�ռ��С������Ҫ���¿��ٿռ�
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
			//׷��
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

			//Ų������
			size_t end = _size + len;
			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				--end;
			}

			//��������
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
				strcpy(_str + pos, _str + pos + len); //����Ҫ��������Ч�ַ�������Ҫɾ������Ч�ַ�
				_size -= len; //size����
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

		//������ҵ�һ��ƥ����ַ�
		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size); //����±�ĺϷ���
			for (size_t i = pos; i < _size; i++) //��posλ�ÿ�ʼ���Ѱ��Ŀ���ַ�
			{
				if (_str[i] == ch)
				{
					return i; //�ҵ�Ŀ���ַ����������±�
				}
			}
			return string::npos; //û���ҵ�Ŀ���ַ�������npos
		}

		//������ҵ�һ��ƥ����ַ�
		size_t rfind(char ch, size_t pos = string::npos)
		{
			Mystring tmp(*this); //�����������tmp
			reverse(tmp.begin(), tmp.end()); //����reverse���ö���tmp��C�ַ���
			if (pos >= _size) //����pos�����ַ�����Ч����
			{
				pos = _size - 1; //��������posΪ�ַ������һ���ַ����±�
			}
			pos = _size - 1 - pos; //��pos��Ϊ����Գƺ��λ��
			size_t ret = tmp.find(ch, pos); //����find����
			if (ret != string::npos)
				return _size - 1 - ret; //�ҵ��ˣ�����ret����Գƺ��λ��
			else
				return string::npos; //û�ҵ�������npos
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

		//>���������
		bool operator>(const Mystring& s)const
		{
			return strcmp(_str, s._str) > 0;
		}
		//==���������
		bool operator==(const Mystring& s)const
		{
			return strcmp(_str, s._str) == 0;
		}

		//>=���������
		bool operator>=(const Mystring& s)const
		{
			return (*this > s) || (*this == s);
		}
		//<���������
		bool operator<(const Mystring& s)const
		{
			return !(*this >= s);
		}
		//<=���������
		bool operator<=(const Mystring& s)const
		{
			return !(*this > s);
		}
		//!=���������
		bool operator!=(const Mystring& s)const
		{
			return !(*this == s);
		}

		//��ȡһ�к��пո���ַ���
		istream& getline(istream& in, Mystring& s)
		{
			s.clear(); //����ַ���
			char ch = in.get(); //��ȡһ���ַ�
			while (ch != '\n') //����ȡ�����ַ�����'\n'��ʱ�������ȡ
			{
				s += ch; //����ȡ�����ַ�β�嵽�ַ�������
				ch = in.get(); //������ȡ�ַ�
			}
			return in;
		}


	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};

	//>>�����������
	istream& operator>>(istream& in, string& s)
	{
		s.clear(); //����ַ���
		char ch = in.get(); //��ȡһ���ַ�
		while (ch != ' ' && ch != '\n') //����ȡ�����ַ����ǿո��'\n'��ʱ�������ȡ
		{
			s += ch; //����ȡ�����ַ�β�嵽�ַ�������
			ch = in.get(); //������ȡ�ַ�
		}
		return in; //֧����������
	}

	//<<�����������
	ostream& operator<<(ostream& out, const string& s)
	{
		//ʹ�÷�Χfor�����ַ��������
		for (auto e : s)
		{
			cout << e;
		}
		return out; //֧���������
	}
}
