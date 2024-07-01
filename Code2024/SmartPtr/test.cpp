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

void Test()
{
	//test_auto();

	//auto_ptr<Test> t1(new Test);		// auto_ptr ��������ָ��
	//cout << "Test->debug" << t1->getDebug() << endl;
	//cout << "(*test).debug" << (*t1).getDebug() << endl;

	// auto_ptr ��C++11��������Ҫԭ��
	auto_ptr<string> p1(new string(" Number1 !"));
	auto_ptr<string> p2(new string(" Number2 !"));

	cout << "p1��" << p1.get() << endl;
	cout << "p2��" << p2.get() << endl;

	// p2��ֵ��p1������p1���Ƚ��Լ�ԭ���йܵ�ָ���ͷŵ���Ȼ������й�p2���йܵ�ָ�룬
	// Ȼ��p2���йܵ�ָ����NULL��Ҳ����p1�й���p2�йܵ�ָ�룬��p2�������йܡ�
	p1 = p2;
	cout << "p1 = p2 ��ֵ��" << endl;
	cout << "p1��" << p1.get() << endl;
	cout << "p2��" << p2.get() << endl;

	// ���Զ�����delete [] ����ȥ�ͷ��ڴ�
	unique_ptr<int[]> array(new int[5]);	// ֧����������

	auto_ptr<string> p3;
	string* str = new string("����ָ����ڴ��������");
	p3.reset(str);	// p3�й�strָ��
	{
		auto_ptr<string> p4;
		p4.reset(str);	// p4�ӹ�strָ��ʱ������ȡ��p3���йܣ�Ȼ���ٶ�str���й�
	}

	// ��ʱp3�Ѿ�û���й�����ָ���ˣ�ΪNULL����ʹ�����ͻ��ڴ汨��
		// cout << "str��" << *p3 << endl;  // err

}

int main()
{
	Test();

	return 0;
}