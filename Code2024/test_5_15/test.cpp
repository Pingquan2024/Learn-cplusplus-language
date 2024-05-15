#include <iostream>
using namespace std;

class A
{
public:
	void Print()
	{
		cout << "Print()" << endl;
	}

private:
	int _a;
};

void test1()
{
	A* p = nullptr;
	p->Print();
}

   /*c++实现的stack*/
typedef int DataType;
class Stack
{
public:
	void Init()
	{
		_array = (DataType*)malloc(sizeof(DataType) * 3);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		_capacity = 3;
		_size = 0;
	}

	void Push(DataType data)
	{
		CheckCapacity();
		_array[_size] = data;
		_size++;
	}

	void Pop()
	{
		if (Empty())
			return;
		_size--;
	}

	DataType Top()
	{
		return _array[_size - 1];
	}

	int Empty()
	{
		return 0 == _size;
	}

	int Size()
	{
		return _size;
	}

	void Destroy()
	{
		if (_array)
		{
			free(_array); 
			_array = NULL; 
			_capacity = _size = 0;
		}
	}

private:
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			int newcapacity = _capacity * 2; 
			DataType* temp = (DataType*)realloc(_array, newcapacity * sizeof(DataType));
			if (temp == NULL)
			{
				perror("realloc申请空间失败!!!"); return;
			} 
			_array = temp; 
			_capacity = newcapacity;
		}
	}

private: 
	DataType* _array;
	int _capacity;
	int _size;
};

void test2()
{
	Stack s1;
	s1.Init();
	s1.Push(12);
	s1.Push(20);
	s1.Push(3); 
	s1.Push(4);

	printf("%d\n", s1.Top());
	printf("%d\n", s1.Size());
	s1.Pop();
	s1.Pop();
	printf("%d\n", s1.Top());
	printf("%d\n", s1.Size());

	s1.Destroy();
}

/////////////////////////////////////////////////////////////
//构造函数 并不是开空间创建对象，而是初始化对象
class Date
{
public:
	// 1. 无参构造函数
	Date()
	{}

	// 2. 带参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
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

void testDate()
{
	Date d1;                  //调用无参构造函数
	Date d2(2024, 5, 15);     //调用有参构造函数
	d1.Print();               //随机值
	d2.Print();
}

class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date2
{
private:
	//// 基本类型（内置类型）
	//int _year;
	//int _month;
	//int _day;

	// c++11  内置类型成员变量在类中声明时可以给默认值。
	int _year = 1970;
	int _month = 1;
	int _day = 1;

	// 自定义类型
	Time _t;
};

void test3()
{
	Date2 d;
}

class Date3
{
public:

	Date3()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}


	//全缺省的构造函数
	Date3(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
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

void test4()
{
	//Date3 d;      //err 对重载函数的调用不明确
	Date3 d(2024);  //半缺省传参
}


/////////////////////////////////////////////////////////////
	/*析构函数*/
// 对象在销毁时会自动调用析构函数，完成对象中资源的清理工作
typedef int DataType;
class Stack1 
{
public:
	Stack1(int capacity = 3)
	{
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (nullptr == _array)
		{
			perror("malloc申请空间失败！");
			return;
		}

		_capacity = capacity;
		_size = 0;

		cout << "Stack()" << endl;
	}

	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}

	//  ...

	~Stack1()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = _size = 0;
		}

		cout << "~Stack()" << endl;
	}

private:
	DataType* _array;
	int _capacity;
	int _size;
};

void testStack1()
{
	Stack1 s;
	s.Push(1);
	s.Push(2);
}

int main()
{
	//test1();
	//test2();
	//testDate();
	//test3();
	//test4();
	testStack1();
	return 0;
}