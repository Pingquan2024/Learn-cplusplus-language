#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

// 智能指针是管理动态分配的内存的，它会帮助我们自动释放new出来的内存，从而避免内存泄漏！
// RAII
namespace fpq
{

	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{ }
	
		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		// 管理权转移
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};

}

void test_auto()
{
	auto_ptr<int> ap1(new int(1));
	auto_ptr<int> ap2(ap1);

	*ap1 = 1; // 管理权转移以后导致ap1悬空，不能访问
	*ap2 = 1;
}

class Test
{
public:
	Test()
	{
		cout << "Test构造函数" << endl;
	}

	~Test()
	{
		cout << "Test析构函数" << endl;
	}

	int getDebug()
	{
		return this->debug;
	}

private:
	int debug = 22;
};

void Test()
{
	//test_auto();

	//auto_ptr<Test> t1(new Test);		// auto_ptr 定义智能指针
	//cout << "Test->debug" << t1->getDebug() << endl;
	//cout << "(*test).debug" << (*t1).getDebug() << endl;

	// auto_ptr 被C++11抛弃的主要原因
	auto_ptr<string> p1(new string(" Number1 !"));
	auto_ptr<string> p2(new string(" Number2 !"));

	cout << "p1：" << p1.get() << endl;
	cout << "p2：" << p2.get() << endl;

	// p2赋值给p1后，首先p1会先将自己原先托管的指针释放掉，然后接收托管p2所托管的指针，
	// 然后p2所托管的指针制NULL，也就是p1托管了p2托管的指针，而p2放弃了托管。
	p1 = p2;
	cout << "p1 = p2 赋值后：" << endl;
	cout << "p1：" << p1.get() << endl;
	cout << "p2：" << p2.get() << endl;

	// 会自动调用delete [] 函数去释放内存
	unique_ptr<int[]> array(new int[5]);	// 支持这样定义

	auto_ptr<string> p3;
	string* str = new string("智能指针的内存管理陷阱");
	p3.reset(str);	// p3托管str指针
	{
		auto_ptr<string> p4;
		p4.reset(str);	// p4接管str指针时，会先取消p3的托管，然后再对str的托管
	}

	// 此时p3已经没有托管内容指针了，为NULL，在使用它就会内存报错！
		// cout << "str：" << *p3 << endl;  // err

}

int main()
{
	Test();

	return 0;
}