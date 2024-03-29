#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include <iostream>
using namespace std;

//test.cpp
//预处理 头文件展开/宏替换/去掉注释/条件编译

//test.i
//编译 检查语法，生成汇编代码（指令级代码）

//test.s
//汇编  将汇编代码生成二进制机器码

//test.o
//链接 合并链接，生成可执行程序


//1.函数重载


//2.引用
//输出型参数

int func()
{
	int a = 0;

	return a;  //有一个临时变量返回
}

int main()
{
	int ret = func();
	cout << ret << endl;
	return 0;
}

//int main()
//{
//	int& ret = func();  //err
//	return 0;
//}

//内联函数
inline int Sub(int x, int y)
{

}

//类
class className
{
	//类体：有成员函数和成员变量组成
};  //注意分号


class Person
{
public:
	void ShowInfo()
	{
		cout << _name << "-" <<_sex << "-" << _age << endl;
	}

	char* _name;
	char* _sex;
	int _age;
};