#pragma once
#include <string.h>

namespace mystring
{
	class string
	{
	public:
		string(const)
			:_size(strlen(s))
			,
		{
			_str = new char[1];
		 }

	private:
		char* _str;
		size_t _size;
		size_t capacity;
	};
}