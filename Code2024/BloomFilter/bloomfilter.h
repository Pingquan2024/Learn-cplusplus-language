#pragma once

#include <iostream>
#include <vector>
#include <string>

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

		/*布隆过滤器*/

// N最多会插入key数据的个数
template<size_t N, class K = string, class Hash1 = BKDRHash, class Hash2 = APHash, class Hash3 = DJBHash>
class BloomFilter
{
public:
	void set(const K& key)
	{
		size_t len = N * _X;
		size_t hash1 = Hash1()(key) % len;
		_bs.set(hash1);

		size_t hash2 = Hash2()(key) % len;
		_bs.set(hash2);

		size_t hash3 = Hash3()(key) % len;
		_bs.set(hash3);
	}

	bool test(const K& key)
	{
		size_t len = N * _X;
		size_t hash1 = Hash1()(key) % len;
		if (!_bs.test(hash1))
		{
			return false;
		}

		size_t hash2 = Hash2()(key) % len;
		if (!_bs.test(hash2))
		{
			return false;
		}

		size_t hash3 = Hash3()(key) % len;
		if (!_bs.test(hash3))
		{
			return false;
		}

		//不在是准确的；
		return true;
	}

private:
	static const size_t _X = 6;
	bitset<N*_X> _bs;
};

struct BKDRHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
			hash *= 31;
		}
		return hash;
	}
};

struct APHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (long i = 0; i < s.size(); i++)
		{
			size_t ch = s[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct DJBHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 5381;
		for (auto ch : s)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};

void bloomfilter()
{
	BloomFilter<1000> bs;
	bs.set("hello");
	bs.set("world");
	bs.set("fpq");
	bs.set("hell");
	bs.set("holle");
	bs.set("test");
	bs.set("htseo");
	bs.set("tset");
	bs.set("ttso");
	bs.set("word");
	bs.set("sort");

	cout << bs.test("hello") << endl;
	cout << bs.test("fpq") << endl;
	cout << bs.test("ello") << endl;
	cout << bs.test("llost") << endl;
	cout << bs.test("test") << endl;
	cout << bs.test("sort") << endl;
}

void test_bloomfilter2()
{
	srand((unsigned int)time(0));
	const size_t N = 10000;
	BloomFilter<N> bf;

	vector<string> v1;
	string url = "https://www.cnblogs.com/-clq/archive/rshsrh.html";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + to_string(i));
	}

	for (auto& str : v1)
	{
		bf.set(str);
	}

	// v2跟v1是相似字符串集，但是不一样
	vector<string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		string url = "https://www.cnblogs.com/-clq/archive/hrt4yh56hgsf.html";
		url += to_string(999999 + i);
		v2.push_back(url);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.test(str))
		{
			++n2;
		}
	}
	cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

	// 不相似字符串集
	vector<string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		string url = "baidu.com";
		//string url = "https://www.cctalk.com/m/statistics/wrywyh5wuhy5.html";
		url += to_string(i + rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.test(str))
		{
			++n3;
		}
	}
	cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
}