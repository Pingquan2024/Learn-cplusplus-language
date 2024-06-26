#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include "Date.h"

Date::Date(int year, int month, int day)
	//初始化列表
	:_year(year)
	,_month(month)
	,_day(day)
{
	if (month > 0 && month < 13
		&& (day > 0 && day <= GetMonthDay(year, month)))
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

inline int Date::GetMonthDay(int year, int month)const
{
	assert(month > 0 && month < 13);
	static int MonthArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
	{
		return 29;
	}
	else
	{
		return MonthArr[month];
	}
}

void Date::Print() const
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

bool Date::operator==(const Date& d)const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator>(const Date& d)const
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

bool Date::operator>=(const Date& d)const
{
	return *this == d || *this > d;
}

bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}

bool Date::operator<(const Date& d)const
{
	return !(*this >= d);
}

bool Date::operator<=(const Date& d)const
{
	return !(*this > d);
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += -day;  
		return *this;
	}

	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}

		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		// 复用operator-=
		*this -= -day;
	}
	else
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
	}
	return *this;
}


Date Date::operator+(int day)const
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

Date Date::operator-(int day)const
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

// d1 - d2;
//思路：让较小日期的天数一直加1
int Date::operator-(const Date& d) const  
{
	Date max = *this;        //假设第一个日期较大
	Date min = d;            //假设第二个日期较小
	int flag = 1;            //此时结果应该为正值

	if (*this < d)
	{
		//假设错误，更正
		max = d;
		min = *this;
		flag = -1;           //此时结果应该为负值
	}

	int n = 0;               //记录所加的总天数
	while (min != max)
	{
		++min;               //较小的日期++
		++n;                 //总天数++
	}

	return n * flag;
}

//前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//后置++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

//前置--
Date& Date::operator--()
{
	//复用operator-=
	*this -= 1;
	return *this;
}

//后置--
Date Date::operator--(int)
{
	Date tmp(*this);  //拷贝构造tmp，用于返回
	//复用operator-=
	*this -= 1;
	return tmp;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}