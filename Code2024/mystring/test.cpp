#define _CRT_SECURE_NO_WARNINGS 1
#include "mystring.h"
#include <string>

void test_string1()
{

//string();  //����һ�����ַ���

//string(const char* s);  //����s��ָ���ַ�����

//string(const char* s, size_t n);  //����s��ָ�ַ����е�ǰn���ַ�

//string(size_t n, char c);  //����n��c�ַ����ַ���

//string(const string & str);  //����str�ĸ���Ʒ

//string(const string & str, size_t pos, size_t len = npos);  //����str�д��ַ�λ��pos��ʼ����Խlen���ַ��Ĳ���
															  //������������������ַ������ȣ���ȡ��������ж���ȡ���٣�
	                                                          //δ����������������ȡ����β

	string s1;                               //������ַ�����s1��һ��string���Ͷ��������
	string s2("hello string");               //���ơ�hello string��
	string s3("hello world", 3);             //���ơ�hello world����ǰ�����ַ�
	string s4(10, 'h');                     //����10����s�����ַ����ַ���
	string s5(s2);                           //����s2�ĸ���Ʒ
	string s6(s3, 0, 4);                     //s2�д��ַ�λ��0��ʼ����Խ4���ַ��Ĳ���
	
	/*push_back���в���*/
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
	//Ҳ������+=��ɡ�
	cout << s1 << endl;

	/*insert posλ�ò���*/
//string insert(size_t pos, const string& str);   //��posλ�ò��룬�˺����ĵڶ���������һ��string���͵Ķ��󣬱�ʾҪ������ַ������ݡ�

//string insert(size_t pos, const char* s);       //��posλ�ò��룬�˺����ĵڶ���������һ���ַ�����ָ�룬��ʾҪ������ַ������ݡ�

//iterator insert(iterator p, char c);            //�õ����������ַ�c

	string s("c");
	string st = "s";
	s.insert(1, st);

	const char* toInsert = "d";
	//s.insert(2, "d");
	s.insert(2, toInsert);

	s.insert(s.end(), 'n');
	cout << s <<" ";

	/*appendƴ��*/
//string append(const string & str);              //������string�������ƴ��
	
//string append(const char* s);                   //string������ַ���s��ƴ��
	
//string append(size_t n, char c);                //��n���ַ�charƴ�ӵ�string�������

	string st1("hello ");
	string st2("C/");
	st1.append(st2);
	st1.append("C");
	st1.append(2, '+');
	cout << st1 << endl;

/*pop_backɾ��*/
//void pop_back();                               //ɾ��string�����е����һ��Ԫ��

	st1.pop_back();
	st1.pop_back();
	st1.pop_back();
	st1.pop_back();
	st1.pop_back();
	cout << st1 << endl;

	/*eraseɾ��*/
//string erase(size_t pos = 0, size_t len = npos);   //ɾ��posλ�õ�n���ַ�������n��ɾ����������ַ�
 
//iterator erase(iterator p);                        //ɾ������������λ�õ��ַ�

//iterator erase(iterator first, iterator last);     //ɾ��first��last�����ϵ������ַ�

	string str("I like C++!!!");
	str.erase(10,3);
	str.erase(str.end() - 1);
	str.erase(str.begin() + 6, str.end());           //I like
	cout << str << endl;
}

void test_string2()
{
	/*string�Ĳ���find*/
//size_t find(const string & str, size_t pos = 0)const;       //posΪ����ζ�����������ַ���

//size_t find(const char* s, size_t pos = 0)const;

//size_t find(char c, size_t pos = 0)const;

	string s1("https://legacy.cplusplus.com/reference/string/string/?kw=string");
	string s2("cplusplus");
	size_t pos1 = s1.find(s2);     
	cout << pos1 << endl;          //15

	char str[] = { "string" };     //�����������ַ���string��ƥ��ĵ�һ��λ��
	size_t pos2 = s1.find(str);
	cout << pos2 << endl;          //39

	size_t pos3 = s1.find(":");
	cout << pos3 << endl;          //5

	size_t pos4 = s1.find("?",52); //��53��߿�ʼ���ң���
	cout << pos4 << endl;          //��53��λ�þ��ǣ���

	/*string��rfind����*/
//size_t rfind(const string & str, size_t pos = npos)const;
//size_t rfind(const char* s, size_t pos = npos)const;
//size_t rfind(char c, size_t pos = npos)const;

	string s3("http://www.cplusplus.com/reference/string/string/find/");
	string s4("find");
	size_t pos5 = s3.rfind(s4);             //�������һ�γ��ֵ�λ��
	cout << pos5 << endl;
	size_t pos6 = s3.rfind("cplus");
	cout << pos6 << endl;
	size_t pos7 = s3.rfind('d', 55);       //55֮ǰ��λ��ȥ����
	cout << pos7 << endl;
}

void test_string3()
{
	//vs��1.5������
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
	cout << "s1��s2�Ƚϣ�" << s1.compare(s2) << endl;
	cout << "s1��ǰ�����ַ���s2�Ƚϣ�" << s1.compare(0, 3, s2) << endl;
	cout << "s1��ǰ�����ַ���s2��ǰ�����Ƚϣ�" << s1.compare(0, 3, s2, 0, 3) << endl;

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

	// ���õ�������ӡstring�е�Ԫ��
	mystring::Mystring::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	// ������Կ���һ����ֻҪ֧�ֵĻ�����iterator����֧�ַ�Χfor
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
