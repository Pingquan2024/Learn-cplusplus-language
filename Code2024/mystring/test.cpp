#define _CRT_SECURE_NO_WARNINGS 1
#include "mystring.h"

void test_mystring()
{
	std::string s1;
	s1 = "hello world\0";
	cout << s1.size() << endl;
	cout << s1.length() << endl;
}


void TestBitstring()
{
	mystring::Mystring s1("hello");
	s1.push_back(' ');
	s1.push_back('f');
	s1.push_back('p');
	s1 += 'q';
	//cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	// 利用迭代器打印string中的元素
	mystring::Mystring::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	// 这里可以看到一个类只要支持的基本的iterator，就支持范围for
	for (auto ch : s1)
		cout << ch;
	cout << endl;
}

int main()
{
	//test_mystring();
	TestBitstring();
}
