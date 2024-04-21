#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include "Date.h"

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

int main()
{
	//TestDate1();
	//TestDate3();
	TestDate4();
}



