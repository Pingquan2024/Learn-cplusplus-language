#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <functional>

using namespace std;

void test_auto() 
{
	int i = 10; 
	auto p = &i;
	auto pf = strcpy;

	cout << typeid(p).name() << endl; 
	cout << typeid(pf).name() << endl;

	map<string, string> dict = { {"sort", "排序"}, {"insert", "插入"} }; 
	//map<string, string>::iterator it = dict.begin(); 
	auto it = dict.begin();

	cout << typeid(dict).name() << endl << endl;
	cout << typeid(it).name() << endl;

}

class Solution1
{
public:
    bool detectCapitalUse(string word)
    {
		//word是一个vector容器，word.size() 在容器说明中 被定义为 : unsigned int 类型, 而i是int 类型  会出现不匹配"warning C4018: “<”: 有符号/无符号不匹配"
        unsigned int uc = 0;
        for (unsigned int i =0; i < word.size(); i++)
        {
            if (isupper(word[i]) && uc++ < i)
            {
                return false;
            }
        }

        return uc == word.size() || uc <= 1;
    }
};

void test_Solution1()
{
    Solution1 s;
    string s1 = "Leetcode";
    string s2 = "LEETCODE";
    string s3 = "LettcoDe";
    cout << s.detectCapitalUse(s1) << endl;
    cout << s.detectCapitalUse(s2) << endl;
    cout << s.detectCapitalUse(s3) << endl;
    
}

int sub(int x, int y)
{
	return x - y;
}

struct mul
{
	int operator()(int x, int y)
	{
		return x * y;
	}
};

class Sub
{
public:
	Sub(int rate)
		:_rate(rate)
	{}

	int func(int a, int b)
	{
		return (a - b) * _rate;
	}

private:
	int _rate;
};

class Solution2 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;
        map<string, function<int(int, int)>> opFuncMap = 
        {
           { "+",  [](int i, int j) {return i + j; } },         
           { "-",  [](int i, int j) {return i - j; } },         
           { "*",  [](int i, int j) {return i * j; } },   
           { "/",  [](int i, int j) {return i / j; } } };
        for (auto& str : tokens)
        {
            if (opFuncMap.find(str) != opFuncMap.end()) 
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(opFuncMap[str](left, right));
            }
            else
            {
                // 1、atoi  itoa
                // 2、sprintf scanf              
                // 3、stoi  to_string  c++11
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};

class Solution3
{
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> st;
		map<string, function<int(int, int)>> opFuncMap =
		{
			{"+",[](int i,int j) {return i + j; }},
			{"-",sub},
			{"*",mul()},
			{"&",bind(&Sub::func,Sub(3),placeholders::_1,placeholders::_2)}
		};

		for (auto& str : tokens)
		{
			if (opFuncMap.find(str) != opFuncMap.end())
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();

				st.push(opFuncMap[str](left, right));
			}
			return st.top();
		}
	}
private:

};

void Print(int a, int b)
{
	cout << a << " ";
	cout << b << endl;
}

// decltype的一些使用使用场景
template<class T1, class T2>
void F(T1 t1, T2 t2)
{
	decltype(t1 * t2) ret;
	cout << typeid(ret).name() << endl;
}

void test_decltype()
{
	const int x = 1;
	double y = 2.2;
	decltype(x * y) ret; // ret的类型是double 
	decltype(&x) p;      //p的类型是int*
	cout << typeid(ret).name() << endl;
	cout << typeid(p).name() << endl;
	F(1, 'a');
}

void test_bind()
{
	Print(1, 2);

	//调整参数
	// placeholders::_1  占位符
	//bind(Print, placeholders::_1, placeholders::_2);
	//auto RPrint = bind(Print, placeholders::_2, placeholders::_1);
	function<void(int, int)> RPrint = bind(Print, placeholders::_2, placeholders::_1);
	RPrint(10, 20);

	//绑定的调整参数个数
	function<int(Sub, int, int)> fSub = &Sub::func;
	cout << fSub(Sub(3), 10, 20) << endl;

	function<int(int, int)> fSub1 = bind(&Sub::func, Sub(3), placeholders::_1, placeholders::_2);
	cout << fSub1(10, 20) << endl;

	function<int(Sub, int)> fSub2 = bind(&Sub::func, placeholders::_1, 100, placeholders::_2);
	cout << fSub2(Sub(3), 20) << endl;

}

void main1()
{
	//test_auto();

	test_Solution1();

	//test_decltype();

	//test_bind();
}

