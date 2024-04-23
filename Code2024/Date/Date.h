#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

class Date
{
	//友元
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	//构造函数
	Date(int year = 1970, int month = 1, int day = 1);

	int GetMonthDay(int year, int month)const;

	//打印函数
	void Print()const;

	//运算符重载
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator>(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator>=(const Date& d)const;

	Date& operator+=(int day);
	Date& operator-=(int day);

	Date operator+(int day)const;

	//日期-天数 d1-100
	Date operator-(int day)const;
	//日期-日期 d1-d2
	int operator-(const Date& d)const;

	// ++d1
	Date& operator++();

	// d1++
	Date operator++(int);     //int占位，跟前置重载区分

	//前置--
	Date& operator--();

	//后置--
	Date operator--(int);
private:
	int _year;
	int _month;
	int _day;
};