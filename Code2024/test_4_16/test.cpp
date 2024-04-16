#include <iostream>
#include <vector>
using namespace std;

#include<time.h>

void test_vector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> copy(v);

	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector2()
{
	vector<int> v1(10, 1);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v2(v1.begin(), v1.end());
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	string s1("hello world");
	vector<char> v3(s1.begin() + 3, --s1.end());
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//vector<int>::reverse_iterator rit = v.rbegin();
	auto rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	//cout << v.max_size() << endl;
}

void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	const size_t n = 10000000;

	size_t begin = clock();
	//v.reserve(n);
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < n; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			//cout << "capacity changed: " << sz << '\n';
		}
	}
	size_t end = clock();
	cout << "消耗：" << end - begin << endl;
}

int main()
{
	test_vector2();

	//TestVectorExpand();

	return 0;
}