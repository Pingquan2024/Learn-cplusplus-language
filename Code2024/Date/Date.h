#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

class Date
{
public:
	//���캯��
	Date(int year = 1970, int month = 1, int day = 1);

	int GetMonthDay(int year, int month);

	void Print();

	//���������
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator<(const Date& d);
	bool operator>(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);

	Date& operator+=(int day);

	Date operator+(int day);

	//d1-100
	Date operator-(int day);
	//d1-d2
	int operator-(const Date& d);

	// ++d1
	Date& operator++();

	// d1++
	Date operator++(int);     //intռλ����ǰ����������

private:
	int _year;
	int _month;
	int _day;
};