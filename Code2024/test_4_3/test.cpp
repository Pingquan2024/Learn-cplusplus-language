#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include <iostream>
using namespace std;

//C++方式实现，会发现struct中也可以定义函数。
//在C++中更喜欢用class来代替


//类和对象
class className
{
public:     //公有
	//类体
	//成员变量
	//成员函数

	//默认生成构造函数，对自定义类型成员，会调用它的默认构造函数 --（Init）
	//默认生成析构函数，对自定义类型成员，会调用它的默认析构函数 --（Destroy）

private:    //私有

	int _year = 0;
	//对内置类型可以给个缺省值，不是初始化（补丁）

protected:  //保护
};

//类的实例化

class Date
{
public:
	//Date()
	//{
	//	_year = 1;
	//	_month = 1;
	//	_day = 1;
	//}

	//构造函数
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//拷贝函数
	//日期类型不需要我们写拷贝构造
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}


	//this this指针的本质是一个指针常量：const Type* const pointer; 

	//他储存了调用他的对象的地址，并且不可被修改。这样成员函数才知道自己修改的成员变量是哪个对象的。
	// 
	//void date(int year = 2024, int month = 4, int day = 2)
	//{
	//	this->_year = year;
	//	this->_month = month;
	//	this->_day = day;
	//}

	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}

	//运算符重载
	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator<(const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year && _month < d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day < d._day)
		{
			return true;
		}
		else
			return false;
	}

	//bool operator<(const Date& d)
	//{
	//	return _year < d._year
	//		|| _year < d._year && _month < d._month
	//		|| _year < d._year && _month < d._month && _day < d._day;
	//}

	// d1 <= d2
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	// d1 > d2
	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	// d1 >= d2
	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	// d1 != d2
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	//返回值为了支持连续赋值，保持运算符的特性
	// d3 = d2 = d1
	//d1=d2
	 
	//赋值重载 
	Date& operator=(const Date& d)
	{
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

//int main()
//{
//	Date d1;
//	Date d2(2024, 4, 3);
//
//	Date d3(d2);   //将d2的值拷贝给d3
//	d1.Print();
//	d2.Print();
//	return 0;
//}

//类定义了一个新的作用域，类的所有成员都在类的作用域中。在类体外定义成员时，需要使用::作用域操作符指明成员属于哪个类域。



int main()
{
	//Date d3;

	//Date d4(2024,4,4);
	//d4.Print();

	//Date d5 = d4;   
	//d5.Print();

	Date d1(2023, 2, 4);
	Date d2(2024, 2, 2);
	Date d3(2025, 3, 2);

	d3 = d2 = d1; //d1.operator=(d2)

	cout << (d1 < d2) << endl;
	cout << (d2 < d3) << endl;
	d3.Print();

	return 0;
}

