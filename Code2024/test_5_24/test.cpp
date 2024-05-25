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
	A _aobj;		//没有默认构造函数
	int& _ref;		//引用
	const int _n;	//const
};

//尽量使用初始化列表初始化

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


//成员变量在类中声明次序就是其在初始化列表中的初始化顺序
class A2
{
public:
	A2(int a)
		:_a1(a)
		, _a2(_a1)
	{}

	void Print()
	{
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a2;
	int _a1;
};

class Date3
{
public:
	//单参构造函数具有类型转换的作用
	/*Date3(int year)
		:_year(year)
	{}*/

	Date3(int year, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	//explicit Date3(int year, int month=1, int day=1)
	//	:_year(year)
	//	,_month(month)
	//	,_day(day)
	//{}

	/*explicit具有禁止类型转换的作用*/

	Date3& operator=(const Date3& d)
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

void test()
{
	Date3 d1(2022);

	//实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
	d1 = 2023;
}

class A3
{
public:
	A3()
	{
		++_scount;
		cout << "A3()" << endl;
	}

	A3(const A3& t)
	{
		++_scount;
		cout << "A3(const A3& t)" << endl;
	}

	~A3()
	{
		--_scount;
		cout << "~A3()" << endl;
	}

	static int GetACount()
	{
		cout << "static int GetACount()" << endl;

		return _scount;
	}

private:
	static int _scount;  //声明
};

int A3::_scount = 0;     //定义

void testA3()
{
	cout << A3::GetACount() << endl;
	A3 a1, a2;
	A3 a3(a1);
	cout << A3::GetACount() << endl;
	cout << a3.GetACount() << endl;

	A3* ptr = nullptr;
	cout << ptr->GetACount() << endl;
}

class Date4
{
	friend ostream& operator<<(ostream& _cout, const Date4& d);
	friend istream& operator>>(istream& _cin, Date4& d);

public:
	Date4(int year = 1970, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	//// d1 << cout; -> d1.operator<<(&d1, cout);  不符合常规调用// 因为成员函数第一个参数一定是隐藏的this，所以d1必须放在<<的左侧
	//ostream& operator<<(ostream& _cout)
	//{
	//	_cout << _year << "-" << _month << "-" << _day << endl;      return _cout;
	//}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date4& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

istream& operator>>(istream& _cin, Date4& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;

	return _cin;
}

void test_Date4()
{
	//Date4 d1(2024, 2, 14);
	//d1.operator<<()

	Date4 d;
	cin >> d;
	cout << d << endl;
}

class Sum
{
public:
	Sum()
	{
		_sum += _n;
		++_n;
	}

	static int getSum()
	{
		return _sum;
	}

private:
	static int _n;
	static int _sum;
};

int Sum::_n = 1;
int Sum::_sum = 0;

class Solution
{
public:
	int Sum_Solution(int n)
	{
		//Sum arr[n];
		Sum* ptr = new Sum[n];
		return Sum::getSum();
	}
};

A func()
{
	int n;
	cin >> n;
	int ret = Solution().Sum_Solution(n);

	//A retA(ret);
	//return retA;

	return A(ret);    //匿名对象  ret去构造
}

void test_Solution()
{
	Solution s;
	cout << s.Sum_Solution(10) << endl;

	Sum();
	//Solution() 匿名对象 生命周期只在这一行
	cout << Solution().Sum_Solution(20) << endl;
}

class Time1
{
	friend class Date5;
	//声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量

public:
	Time1(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
};


class Date5		//Date5为Time的友元
{
public:
	Date5(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}

private:
	int _year;
	int _month;
	int _day;
	Time1 _t;
};


//内部类
class Outclass
{
public:
	Outclass(int A = 21, int B = 12)
		:_A(A)
		, _B(B)
	{
		cout << "Outclass(int A, int B)" << endl;
	}

	void FUNC()
	{
		//cout << _a + 1 << endl;
		cout << _A + 1 << endl;
		cout << _A + 1 << endl;
		cout << _B + 1 << endl;
		cout << _C + 1 << endl;		//静态成员为所有类对象所共享
	}

	class Innerclass		//Innerclass天生就是Outclass的友元
	{
	public:

		Innerclass(int a = 10)
			:_a(a)
		{}

		//void func()
		//{
		//	cout << _a + 1 << endl;
		//	cout << _c + 1 << endl;
		//	//cout << _A + 1 << endl;
		//	//cout << _B + 1 << endl;
		//	cout << _C + 1 << endl;		//静态成员为所有类对象所共享
		//}

		void func(const Outclass& a)
		{
			cout << _a + 1 << endl;
			cout << _c + 1 << endl;
			cout << a._A << endl;
			cout << a._B + 1 << endl;
			cout << _C + 1 << endl;		//静态成员为所有类对象所共享
		}

	private:
		int _a;
		static int _c;
	};

private:
	int _A;
	int _B;
	static int _C;
};

int Outclass::_C = 1;
int Outclass::Innerclass::_c = 2;

void test_inner()
{
	Outclass().FUNC();

	Outclass::Innerclass t1;
	t1.func(Outclass());

	Outclass t2;
	cout << func << " func" << endl;

	//cout << &Outclass::FUNC << " FUNC" << endl;   ?
}


//拷贝对象时的一些编译器优化

class C
{
public:
	C(int a = 0)
		:_a(a)
	{
		cout << "C(int a)" << endl;
	}

	C(const C& aa) :_a(aa._a)
	{
		cout << "C(const A& aa)" << endl;
	}

	C& operator=(const C& aa)
	{
		cout << "C& operator=(const C& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}

	~C()
	{
		cout << "~C()" << endl;
	}
private:
	int _a;

};

void f1(C aa)
{}

C f2() 
{
	C aa; 
	return aa;
}

void test_Copy_optimization()
{
	// 传值传参
	C aa1;
	f1(aa1);
	cout << endl;

	// 传值返回
	f2();
	cout << endl;


	// 隐式类型，连续构造+拷贝构造->优化为直接构造
	f1(1);
	// 一个表达式中，连续构造+拷贝构造->优化为一个构造
	f1(C(2));
	cout << endl;

	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
	C aa2 = f2();
	cout << endl;
	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
	aa1 = f2();
	cout << endl;
}

int main()
{
	//Date2 d(1);

	//A2 aa(1);
	//aa.Print();

	//test();
	//testA3();

	//test_Solution();
	//test_Date4();

	//test_inner();

	test_Copy_optimization();
}