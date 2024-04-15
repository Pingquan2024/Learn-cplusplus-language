#pragma once

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;
namespace mystring
{
	class Mystring
	{
	public:
		Mystring(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size == 0 ? 3 : _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~Mystring()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
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

	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
