#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<size_t N>
class bitset
{
public:
	bitset()
	{
		_bits.resize(N / 8 + 1, 0);
	}

	void set(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		_bits[i] |= (1 << j);
	}

	void reset(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		_bits[i] &= ~(1 << j);
	}

	bool test(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		return _bits[i] & (1 << j);
	}

private:
	vector<char> _bits;
};

void test_bitset()
{
	bitset<100> bs;
	bs.set(10);
	bs.set(11);
	bs.set(15);

	bs.test(10);
	cout << bs.test(10) << endl;
}

template<size_t N>
class twobitset
{
public:
	void set(size_t x)
	{
		if (_bs1.test(x) == false && _bs2.test(x) == false)
		{
			//00 -> 01
			_bs2.set(x);
		}
		else if (_bs1.test(x) == false && _bs2.test(x) == true)
		{
			//01 -> 10
			_bs1.set(x);
			_bs2.reset(x);
		}
			// 10   1ртио
	}

	void Print()
	{
		for (size_t i = 0; i < N; i++)
		{
			if (_bs2.test(i))
			{
				cout << i << endl;
			}
		}
	}

public:
	bitset<N> _bs1;
	bitset<N> _bs2;
};

void test_twobitset2()
{
	int a[] = { 15,45,78,12,45,15,45,121,125,152,154,154 };
	twobitset<1000> bs;
	for (auto e : a)
	{
		bs.set(e);
	}

	bs.Print();
}


