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