#define _CRT_SECURE_NO_WARNINGS 1
#include "mystring.h"
#include <string>

void test_string1()
{

//string();  //构造一个空字符串

//string(const char* s);  //复制s所指的字符序列

//string(const char* s, size_t n);  //复制s所指字符序列的前n个字符

//string(size_t n, char c);  //生成n个c字符的字符串

//string(const string & str);  //生成str的复制品

//string(const string & str, size_t pos, size_t len = npos);  //复制str中从字符位置pos开始并跨越len个字符的部分
															  //如果第三个参数超过字符串长度，则取完结束（有多少取多少）
	                                                          //未给出第三个参数，取到结尾

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
	//也可以用+=完成。
	cout << s1 << endl;

	/*insert pos位置插入*/
//string insert(size_t pos, const string& str);   //从pos位置插入，此函数的第二个参数是一个string类型的对象，表示要插入的字符串内容。

//string insert(size_t pos, const char* s);       //在pos位置插入，此函数的第二个参数是一个字符数组指针，表示要插入的字符串内容。

//iterator insert(iterator p, char c);            //用迭代器插入字符c

	string s("c");
	string st = "s";
	s.insert(1, st);

	const char* toInsert = "d";
	//s.insert(2, "d");
	s.insert(2, toInsert);

	s.insert(s.end(), 'n');
	cout << s <<" ";

	/*append拼接*/
//string append(const string & str);              //将两个string对象进行拼接
	
//string append(const char* s);                   //string对象和字符串s的拼接
	
//string append(size_t n, char c);                //将n个字符char拼接到string对象后面

	string st1("hello ");
	string st2("C/");
	st1.append(st2);
	st1.append("C");
	st1.append(2, '+');
	cout << st1 << endl;

/*pop_back删除*/
//void pop_back();                               //删除string对象中的最后一个元素

	st1.pop_back();
	st1.pop_back();
	st1.pop_back();
	st1.pop_back();
	st1.pop_back();
	cout << st1 << endl;

	/*erase删除*/
//string erase(size_t pos = 0, size_t len = npos);   //删除pos位置的n个字符，不给n则删除后边所有字符
 
//iterator erase(iterator p);                        //删除迭代器给定位置的字符

//iterator erase(iterator first, iterator last);     //删除first到last区间上的所有字符

	string str("I like C++!!!");
	str.erase(10,3);
	str.erase(str.end() - 1);
	str.erase(str.begin() + 6, str.end());           //I like
	cout << str << endl;
}

void test_string2()
{
	/*string的查找find*/
//size_t find(const string & str, size_t pos = 0)const;       //pos为零意味着搜索整个字符串

//size_t find(const char* s, size_t pos = 0)const;

//size_t find(char c, size_t pos = 0)const;

	string s1("https://legacy.cplusplus.com/reference/string/string/?kw=string");
	string s2("cplusplus");
	size_t pos1 = s1.find(s2);     
	cout << pos1 << endl;          //15

	char str[] = { "string" };     //正向搜索与字符串string所匹配的第一个位置
	size_t pos2 = s1.find(str);
	cout << pos2 << endl;          //39

	size_t pos3 = s1.find(":");
	cout << pos3 << endl;          //5

	size_t pos4 = s1.find("?",52); //从53后边开始查找？号
	cout << pos4 << endl;          //第53个位置就是？号

	/*string中rfind查找*/
//size_t rfind(const string & str, size_t pos = npos)const;
//size_t rfind(const char* s, size_t pos = npos)const;
//size_t rfind(char c, size_t pos = npos)const;

	string s3("http://www.cplusplus.com/reference/string/string/find/");
	string s4("find");
	size_t pos5 = s3.rfind(s4);             //查找最后一次出现的位置
	cout << pos5 << endl;
	size_t pos6 = s3.rfind("cplus");
	cout << pos6 << endl;
	size_t pos7 = s3.rfind('d', 55);       //55之前的位置去查找
	cout << pos7 << endl;
}

void test_string3()
{
	//vs中1.5倍扩容
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	cout << "capacity changed: " << sz << '\n';
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_string4()
{

//int compare(const string & str)const;
//int compare(size_t pos, size_t len, const string & str)const;
//int compare(size_t pos, size_t len, const string & str, size_t subpos, size_t sublen)const;

	string s1("world");
	string s2("word");
	cout << "s1和s2比较：" << s1.compare(s2) << endl;
	cout << "s1的前三个字符和s2比较：" << s1.compare(0, 3, s2) << endl;
	cout << "s1的前三个字符和s2的前三个比较：" << s1.compare(0, 3, s2, 0, 3) << endl;

	//string replace(const string)
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
	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	//Test_mystring();

	return 0;
}
