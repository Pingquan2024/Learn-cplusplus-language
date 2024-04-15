#include "mystring.h"

void test_mystring()
{
	std::string s1;
	s1 = "hello world\0";
	cout << s1.size() << endl;
	cout << s1.length() << endl;
}

int main()
{
	test_mystring();
}