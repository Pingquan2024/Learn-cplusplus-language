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

   /*c++ʵ�ֵ�stack*/
typedef int DataType;
class Stack
{
public:
	void Init()
	{
		_array = (DataType*)malloc(sizeof(DataType) * 3);
		if (NULL == _array)
		{
			perror("malloc����ռ�ʧ��!!!");
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
				perror("realloc����ռ�ʧ��!!!"); return;
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
//���캯�� �����ǿ��ռ䴴�����󣬶��ǳ�ʼ������
class Date
{
public:
	// 1. �޲ι��캯��
	Date()
	{}

	// 2. ���ι��캯��
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
	Date d1;                  //�����޲ι��캯��
	Date d2(2024, 5, 15);     //�����вι��캯��
	d1.Print();               //���ֵ
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
	//// �������ͣ��������ͣ�
	//int _year;
	//int _month;
	//int _day;

	// c++11  �������ͳ�Ա��������������ʱ���Ը�Ĭ��ֵ��
	int _year = 1970;
	int _month = 1;
	int _day = 1;

	// �Զ�������
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


	//ȫȱʡ�Ĺ��캯��
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
	//Date3 d;      //err �����غ����ĵ��ò���ȷ
	Date3 d(2024);  //��ȱʡ����
}


/////////////////////////////////////////////////////////////
	/*��������*/
// ����������ʱ���Զ�����������������ɶ�������Դ��������
typedef int DataType;
class Stack1 
{
public:
	Stack1(int capacity = 3)
	{
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (nullptr == _array)
		{
			perror("malloc����ռ�ʧ�ܣ�");
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