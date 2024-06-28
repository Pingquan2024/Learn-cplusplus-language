#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

// ����ָ���ǹ���̬������ڴ�ģ�������������Զ��ͷ�new�������ڴ棬�Ӷ������ڴ�й©��
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

		// ����Ȩת��
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

	*ap1 = 1; // ����Ȩת���Ժ���ap1���գ����ܷ���
	*ap2 = 1;
}

class Test
{
public:
	Test()
	{
		cout << "Test���캯��" << endl;
	}

	~Test()
	{
		cout << "Test��������" << endl;
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

	auto_ptr<Test> t1(new Test);		// auto_ptr ��������ָ��
	cout << "Test->debug" << t1->getDebug() << endl;
	cout << "(*test).debug" << (*t1).getDebug() << endl;
	return 0;
}