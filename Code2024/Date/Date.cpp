#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include "Date.h"

void Date::Print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

int Date::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);
	int MonthArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month==2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
	{
		return 29;
	}
	else
	{
		return MonthArr[month];
	}
}


Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	if (month > 0 && month < 13 && (day > 0 && day <= GetMonthDay(year, month)))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "日期非法" << endl;
	}
}


bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}
	else
		return false;
}

bool Date::operator>=(const Date& d)
{
	return *this == d || *this > d;
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

bool Date::operator<(const Date& d)
{
	return !(*this <= d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}


Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month == 13)
		{
			++tmp._year;
			tmp._month = 1;
		}
	}
	return tmp;
}

//Date Date::operator+(int day)
//{
//	Date tmp(*this);
//	tmp += day;
//
//	return tmp;
//}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}