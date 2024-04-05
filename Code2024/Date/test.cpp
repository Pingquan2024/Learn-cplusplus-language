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

int main()
{
	//TestDate1();
	TestDate2();
}



