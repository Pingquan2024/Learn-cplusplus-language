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

int main()
{
	test_auto();

	auto_ptr<Test> t1(new Test);		// auto_ptr 定义智能指针
	cout << "Test->debug" << t1->getDebug() << endl;
	cout << "(*test).debug" << (*t1).getDebug() << endl;
	return 0;
}