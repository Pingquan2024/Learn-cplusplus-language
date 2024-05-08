#define _CRT_SECURE_NO_WARNINGS 1
#include "mystring.h"

void test_string()
{
	std::string s;
	s = "hello world";
	cout << s.size() << endl;
	cout << s.length() << endl;

//string();  //构造一个空字符串

//string(const char* s);  //复制s所指的字符序列

//string(const char* s, size_t n);  //复制s所指字符序列的前n个字符

//string(size_t n, char c);  //生成n个c字符的字符串

//string(const string & str);  //生成str的复制品

//string(const string & str, size_t pos, size_t len = npos);  //复制str中从字符位置pos开始并跨越len个字符的部分

	string s1;                               //构造空字符串，s1是一个string类型对象的名字
	string s2("hello string");               //复制“hello string”
	string s3("hello world", 3);             //复制“hello world”的前三个字符
	string s4(10, 'h');                     //生成10个‘s’的字符的字符串
	string s5(s2);                           //生成s2的复制品
	string s6(s3, 0, 4);                     //s2中从字符位置0开始并跨越4个字符的部分
	
	/*push_back进行插入*/
	s1.push_back('V');
	s1.push_back('i');
	s1.push_back('s');
	s1.push_back('u');
	s1.push_back('a');
	s1.push_back('l');
	s1.push_back(' ');
	s1.push_back('S');
	s1.push_back('t');
	s1.push_back('u');
	s1.push_back('d');
	s1.push_back('i');
	s1.push_back('o');
	cout << s1 << endl;


}


void Test_mystring1()
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
	test_string();
	//Test_mystring();

	return 0;
}
