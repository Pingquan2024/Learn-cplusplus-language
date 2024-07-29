#include <iostream>
using namespace std;

class person
{
public:
	void printperson();
private:
	char _name[20];
	char _gender[3];
	int _age;
};

// 这里需要指定PrintPersonInfo是属于Person这个类域
void person::printperson()
{
	cout << _name << "" << _gender << "" << _age << endl;
}


//计算类对象的大小
class A
{
public:
	void printA() 
	{
		cout << _a << endl;
	}

private:
	char _a;
};

//结构体内存对齐同C

//this指针
class Date
{
public:
	void Init(int year,int month,int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//void print()
	//{
	//	cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
	//}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//person._age = 100;  //err
	auto ret=sizeof(A);  //只保存成员变量，成员函数存放在公共的代码段

	Date d1, d2;
	d1.Init(2022, 1, 11);
	d1.Init(2024, 4, 9);

	d1.print();
	d2.print();

	return 0;
}