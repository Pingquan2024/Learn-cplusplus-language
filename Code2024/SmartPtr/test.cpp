#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

namespace fpq
{

	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{
			
		}
	
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

int main()
{
	test_auto();
	return 0;
}