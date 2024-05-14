#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;


struct Point
{
	int _x;
	int _y;
};

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


//左值是一个数据的表达式（如变量名或解）

void test1()
{
	Point s;
	s._x;
	s._y;

	int arry1[] = { 0,1,2,4,3,45 };
	int arry2[] = { 0 };
	Point p = { 1,2 };

	//等号（=）可以不添加
	int arry3[]{ 0,1,2,4,3,45 };
	int arry4[]{ 0 };
	Point p1{ 1,2 };

	//c++11中列表初始化也可以适用于new表达式中
	int* pa = new int[4] {0};

	Date(2024, 5, 14);        //old style
	Date d2{ 2024,5,20 };
	Date d3 = { 2024,5,20 };

	// il为initializer_list
	auto il = { 0,10,20,30 };
	cout << typeid(il).name() << endl;

	vector<int> v = { 1,2,3,4 };
	list<int> lt = { 1,2 };

	// 这里{"sort","排序"}会先构造一个pair对象
	map<string, string> dict = { {"sort","排序"},{"insert","插入"} };
	//使用大括号对容器复制
	v = { 10,20,30 };
	
}

	/*让模拟实现的vector也支持{}初始化和赋值*/
namespace fpq
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;

		// vector (initializer_list<value_type> il, const allocator_type& alloc = allocator_type());
		vector(initializer_list<T> l)
		{
			_start = new T[l.size()];
			_finish = _start + l.size();
			_end_of_storage = _start + l.size();

			iterator vit = _start;
			typename initializer_list<T>::iterator lit = l.begin();
			while (lit != l.end())
			{
				*vit++ = *lit++;
			}
		}

		vector<T>& operator=(initializer_list<T> l)
		{
			vector<T> tmp(l);
			swap(_start, tmp._start);
			swap(_finish, tmp._finish);
			swap(_end_of_storage, tmp._storage);

			return *this;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}

void test2()
{

	fpq::vector<int> v{ 0,1,2,3 };

	int i = 10;
	auto p = &i;
	auto pf = strcpy;
	cout << typeid(p).name() << endl; 
	cout << typeid(pf).name() << endl;
	map<string, string> dict = { {"sort", "排序"}, {"insert", "插入"} }; 
	//map<string, string>::iterator it = dict.begin(); auto it = dict.begin();
}

int main()
{
	//test1();
	test2();
	return 0;
}
