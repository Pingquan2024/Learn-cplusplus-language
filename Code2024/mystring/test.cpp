#define _CRT_SECURE_NO_WARNINGS 1
#include "mystring.h"

void test_string()
{
	std::string s;
	s = "hello world";
	cout << s.size() << endl;
	cout << s.length() << endl;

//string();  //����һ�����ַ���

//string(const char* s);  //����s��ָ���ַ�����

//string(const char* s, size_t n);  //����s��ָ�ַ����е�ǰn���ַ�

//string(size_t n, char c);  //����n��c�ַ����ַ���

//string(const string & str);  //����str�ĸ���Ʒ

//string(const string & str, size_t pos, size_t len = npos);  //����str�д��ַ�λ��pos��ʼ����Խlen���ַ��Ĳ���

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
	test_string();
	//Test_mystring();

	return 0;
}
