#include <iostream>

using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

class Date1
{
public:
	Date1(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};


class A
{
public:
	A(int a)
		:_a(a)
	{}

private:
	int _a;
};


class B
{
public:
	B(int a, int ref)
		:_aobj(a)
		, _ref(ref)
		, _n(10)
	{}

private:
	A _aobj;		//û��Ĭ�Ϲ��캯��
	int& _ref;		//����
	const int _n;	//const
};

//����ʹ�ó�ʼ���б��ʼ��

class Time
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}
private:
	int _hour;
};


class Date2
{
public:
	Date2(int day)
	{}
private:
	int _day;
	Time _t;
};


//��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳��
class A2
{
public:
	A2(int a)
		:_a1(a)
		,_a2(_a1)
	{}

	void Print()
	{
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a2;
	int _a1;
};

int main()
{
	Date2 d(1);

	A2 aa(1);
	aa.Print();
}