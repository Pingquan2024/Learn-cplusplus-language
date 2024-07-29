#include <iostream>
#include <string>

using namespace std;

///////////////////////////////////////////////////////////////////
// ����ģ���ʵ���������������ֵ����ֵ��
//����ģ��
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
//ʵ���������� Stack<>����ʵ���˷��ͷ�������Ԫ�ؽ�����ջ��ջ����
//��ģ��
#include <vector>
#include <cstdlib>
#include <stdexcept>

template <class T>
class Stack
{
public:
    void push(T const& elem);  //��ջ
    void pop();           //��ջ
    T top()const;         //����ջ��Ԫ��
    bool empty()const
    {
        return elems.empty();  //���Ϊ���򷵻���
    }

private:
    vector<T> elems;   //Ԫ��
};

template<class T>
void Stack<T>::push(T const& elem)   //elem��һ����������T�Ķ���
{
    //β��
    elems.push_back(elem);
}

template<class T>
void Stack<T>::pop()
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::pop():empty stack");
    }
    //ɾ��ջ������
    elems.pop_back();
}

template<class T>
T Stack<T>::top()const
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::top():empty stack");
    }
    //����ջ������
    return elems.back();
}

int main()
{
    //test1();
    try
    {
        Stack<int> intStack;    //int���͵�ջ
        Stack<string> stringStack;  //string���͵�ջ

        //����int���͵�ջ
        intStack.push(7);
        cout << intStack.top() << endl;
        stringStack.push("hello");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const& ex)
    {
        cerr << "Exception��" << ex.what() << endl;
        return -1;
    }
}