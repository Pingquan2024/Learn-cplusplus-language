#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////
	/*拷贝构造*/
//用已存在的类类型对象创建新对象 -- 由编译器自动调用
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// 使用传值方式编译器直接报错，因为会引发无穷递归调用。
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;

	}
private:
	int _year;
	int _month;
	int _day;
};

void test_Date()
{
	Date d1;
	Date d2(d1);
	d2.Print();
}

class Time
{
public:
	Time()
	{
		_hour = 1;
		_minute = 1;
		_second = 1;
	}

	Time(const Time& t)
	{
		_hour = t._hour;
		_minute = t._minute;
		_second = t._second;

		cout << "Time(const Time& t)" << endl;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date1
{
private:
	//基本类型
	int _year = 1970;
	int _month = 1;
	int _day = 1;

	//自定义类型
	Time _t;

};

void test_Date1()
{
	Date1 d1;

	// Date类并没有显式定义拷贝构造函数，则编译器会给Date类生成一个默认的拷贝构造函数
	Date1 d2(d1);
}

typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 10)
	{
		_array = (DataType*)malloc(capacity * sizeof(DataType));
		if (nullptr == _array)
		{
			perror("malloc申请空间失败"); return;
		}
		_size = 0;
		_capacity = capacity;
	}

	void Push(const DataType& data)
	{
		// CheckCapacity(); _array[_size] = data; _size++;
	}

	~Stack()
	{
		if (_array)
		{
			free(_array); _array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};

void test_Stack1()
{
	Stack s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	//Stack s2(s1);          ///err 浅拷贝
}

class Date2
{
public:
	Date2(int year, int month, int day)
	{
		cout << "Date2(int,int,int):" << this << endl;
	}

	Date2(const Date2& d)
	{
		cout << "Date2(const Date& d):" << this << endl;
	}

	~Date2()
	{
		cout << "~Date2():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

Date2 Test(Date2 d)
{
	Date2 temp(d);
	return temp;
}

void test_Date2()
{
	Date2 d1(2022, 1, 13);
	Test(d1);
}

/*运算符重载*/
class Date3
{
public:
	Date3(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//private:
	int _year;
	int _month;
	int _day;
};

// bool operator==(const Date3& d2)     //左操作是this，指向调用函数的对象
bool operator==(const Date3& d1, const Date3& d2)
{
	return d1._year == d2._year
		&& d1._month == d2._month
		&& d1._day == d2._day;
}
// operator==重载成全局的话，若成员变量私有则需要借助友元

void test_Date3()
{
	Date3 d1(2018, 9, 26);
	Date3 d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
}

/*赋值运算符重载*/
class Date4
{
public:
	Date4(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		cout << "Date4(int year = 1970, int month = 1, int day =1)" << endl;
	}

	Date4(const Date4& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date4(const Date4& d)" << endl;
	}

	// 赋值运算符只能重载成类的成员函数不能重载成全局函数。
	Date4& operator=(const Date4& d)
	{
		cout << "Date4& operator=(const Date4& d)" << endl;

		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

private:
	int _year;
	int _month;
	int _day;
};

//// 重载成全局函数没有this指针，需要两个参数
//Date4& operator=(Date4& d1, const Date4& d2)
//{
//	if (&d1 != &d2)
//	{
//		d1._year = d2._year;
//		d1._month = d2._month;
//		d1._day = d2._day;
//	}
//	return d1;
//}

void test_Date4()
{
	Date4 d1;
	Date4 d2(2024, 2, 14);
	Date4 d3(d2);
	d1 = d2 = d3;
}

class Time1
{
public:
	Time1()
	{
		_hour = 1;
		_minute = 1;
		_second = 1;

		cout << "Time1" << endl;
	}

	Time1& operator=(const Time1& t)
	{
		cout << "Time1& operator=(const Time1& t)" << endl;
		if (this != &t)
		{
			_hour = t._hour;
			_minute = t._minute;
			_second = t._second;
		}
		return *this;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date5
{
private:
	// 基本类型(内置类型)
	int _year = 1970;
	int _month = 1;
	int _day = 1;

	// 自定义类型
	Time1 _t;
};

void test_Date5()
{
	Date5 d1;
	Date5 d2;
	d1 = d2;
}

/*const成员*/
class Date6
{
public:
	Date6(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << "Print()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
	void Print() const
	{
		cout << "Print()const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}

private:
	int _year;    // 年
	int _month;   // 月
	int _day;     // 日
};

void test_Date6()
{
	Date6 d1(2022, 1, 13);
	d1.Print();
	const Date6 d2(2022, 1, 13);
	d2.Print();
}

/*取地址及const取地址操作符重载*/
//两个默认成员函数一般不用重新定义，编译器默认会生成。
class Date7
{
public:
	Date7* operator&()
	{
		return this;
	}

	const Date7* operator&()const
	{
		return this;
	}

private:
	int _year;   // 年
	int _month; // 月
	int _day;   // 日
};

int main()
{
	//test_Date();
	//test_Date1();
	//test_Stack1();
	//test_Date2();
	//test_Date3();
	//test_Date4();
	//test_Date5();
	test_Date6();
	return 0;
}