#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include "Date.h"
//  // const 修饰 *this
//	// this的类型变成 const A*
//	// 内部不改变成员变量的成员函数
//	// 最好加上const，const对象和普通对象都可以调用

void TestDate1()
{
	Date d1(2023, 2, 4);
	d1.Print();

	Date d2 = d1 + 100;
	d2.Print();

	Date d3 = d1 + 50000;
	d3.Print();
}

void TestDate2()
{
	Date d1(2023, 2, 4);
	d1.Print();

	d1++;          //d1.operator++()
	d1.Print();

	++d1;          //d1.operator++(1)
	d1.Print();
}

void TestDate3()
{
	Date d1;               //调用默认构造
	d1.Print();
	Date d2(d1);           //拷贝构造
	d2.Print();

	Date d3(2024, 4, 21);
	d3.Print();

	Date d4;
	d4 += 20;
	d4.Print();

	d4 = d3;
	d3.Print();
}

void TestDate4()
{
	Date d1(2023, 2, 4);
	d1.Print();

	d1 -= 100;
	d1.Print();

	Date d2(2023, 2, 7);
	d2.Print();
	d2 += -100;
	d2.Print();

	Date d3(2023, 2, 7);
	d3.Print();
	d3 -= -200;
	d3.Print();
}

void TestDate5()
{
	Date d1;
	d1.Print();

	Date d2(2024, 4, 24);
	d2.Print();

	
	Date d3 = d2 = d1;
	d3.Print();
	cout << (d2 == d3) << endl;

	d3 += 100;
	d3.Print();
	cout << (d2 != d3) << endl;
	d3 -= 250;
	d3.Print();

	cout << (d2 < d3) << endl;
	cout << (d2 > d3) << endl;
	cout << (d2 <= d3) << endl;

	Date d4(2024, 4, 22);
	d4.Print();
	d4 -= -100;
	d4.Print();

	Date d5(2023, 2, 7);
	d5.Print();
	d5 += -200;
	d5.Print();
	cout << d4 - d5 << endl;

	int i = 1;
	double d = 1.11;

	// 运算符重载+函数重载
	cout << i << " "; // cout.operator<<(i) // int
	cout << d << " "; // cout.operator<<(d) // double
}

int main()
{
	//TestDate1();
	//TestDate3();
	//TestDate4();
	TestDate5();

	return 0;
}



