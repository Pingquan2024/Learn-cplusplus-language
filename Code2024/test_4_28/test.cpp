#include <iostream>
#include <string>

using namespace std;

///////////////////////////////////////////////////////////////////
// 函数模板的实例，返回两个数种的最大值：
//函数模板
template <typename T>
inline T const& Max(T const& a, T const& b)
{
    return a < b ? b : a;
}
void test1()
{

    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;

}

///////////////////////////////////////////////////////////////////
//实例定义了类 Stack<>，并实现了泛型方法来对元素进行入栈出栈操作
//类模板
#include <vector>
#include <cstdlib>
#include <stdexcept>

template <class T>
class Stack
{
public:
    void push(T const& elem);  //入栈
    void pop();           //出栈
    T top()const;         //返回栈顶元素
    bool empty()const
    {
        return elems.empty();  //如果为空则返回真
    }

private:
    vector<T> elems;   //元素
};

template<class T>
void Stack<T>::push(T const& elem)   //elem是一个泛型类型T的对象
{
    //尾插
    elems.push_back(elem);
}

template<class T>
void Stack<T>::pop()
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::pop():empty stack");
    }
    //删除栈顶数据
    elems.pop_back();
}

template<class T>
T Stack<T>::top()const
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::top():empty stack");
    }
    //返回栈顶数据
    return elems.back();
}

int main()
{
    //test1();
    try
    {
        Stack<int> intStack;    //int类型的栈
        Stack<string> stringStack;  //string类型的栈

        //操作int类型的栈
        intStack.push(7);
        cout << intStack.top() << endl;
        stringStack.push("hello");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const& ex)
    {
        cerr << "Exception：" << ex.what() << endl;
        return -1;
    }
}