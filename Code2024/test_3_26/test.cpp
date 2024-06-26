#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权


#include <iostream>

//1.namespace用来解决C语言命名冲突

//namespace--命名空间--->命名空间域
//cout<< 流插入
//cin<<  流输出
//::     作用域限定符

//写法一：
//using namespace std;
//
//int main()
//{
//	cout << "hello fpq" << endl;
//}

//写法二：
//int main()
//{
//	std::cout << "hello fpq" << std::endl;
//}

//c++兼容c;

//适用于日常练习使用，公开全部
using namespace std;

namespace fpq
{
	int Sub(int a, int b)
	{
		int z = a - b;
		return z;
	}

	struct Node
	{
		struct Node* next;
		int val;
	};
}

//部分公开
using std::cout;
using fpq::Sub;

struct fpq::Node;

#include<iostream>

// #include<iostream.h>

// std是C++标准库的命名空间

using std::cout;
using std::endl;


//int main()
//{
//	// << 流插入运算符
//	cout << "hello world" << endl;
//	cout << "hello world" << '\n';
//	cout << "hello world" << endl;
//
//	// 流提取
//	int i = 0;
//	std::cin >> i;
//
//	return 0;
//}


// 缺省参数
//void Func(int a = 1)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	Func(2);
//
//	Func();
//
//	return 0;
//}

// 全缺省
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	Func();
//
//	// 显示传参，从左往右显示传参
//	Func(1);
//	Func(1,2);
//	Func(1, 2, 3);
//
//	return 0;
//}

// 半缺省 -- 必须从右往左，给缺省值
void Func(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}


// C语言不允许同名函数
// CPP可以，但是要求构成函数重载
// 函数名相同，参数不同

int Add(int left, int right)
{
	cout << "int Add(int left, int right)" << endl;

	return left + right;
}

double Add(double left, double right)
{
	cout << "double Add(double left, double right)" << endl;

	return left + right;
}

void Swap(int* p1, int* p2)
{
	//...
}

void Swap(double* p1, double* p2)
{
	//...
}

void f(int a, char b)
{
	cout << "f(int a,char b)" << endl;
}

void f(char a, int b)
{
	cout << "f(int a,char b)" << endl;
}

// 返回值不同不能构成重载
//int f(char a, int b)
//{
//	cout << "f(int a,char b)" << endl;
//}

//namespace fpq
//{
//	void func(int x)
//	{}
//}
//
//namespace fpq
//{
//	void func(double x)
//	{}
//}

//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(1.1, 2.2) << endl;
//
//	int i = 1, j = 2;
//	double k = 1.1, l = 2.2;
//	Swap(&i, &j);
//	Swap(&k, &l);
//	//cout << i;
//	//cout << k;
//
//	return 0;
//}

// 构成函数重载
void func(int a)
{
	cout << "void func(int a)" << endl;
}

void func(int a, int b = 1)
{
	cout << "void func(int a, int b)" << endl;
}

int main()
{
	func(1, 2);

	// 调用存在歧义，不知道调用哪个  linux中 —- Z3Addii
	// func(1);


	return 0;
}