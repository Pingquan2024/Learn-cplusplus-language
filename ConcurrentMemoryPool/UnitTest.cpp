#include "ObjectPool.h"
#include "ConcurrentAlloc.h"

void Alloc1()
{
	for (int i = 0; i < 5; i++)
	{
		void* ptr = ConcurrentAlloc(6);
	}
}

void Alloc2()
{
	for (int i = 0; i < 5; i++)
	{
		void* ptr = ConcurrentAlloc(15);
	}
}

void TLSTest()
{
	// ���Ը�Lambda���ʽ �º��� ��������
	std::thread t1(Alloc1);		// ������һ���߳�ȥִ���������
	t1.join();

	std::thread t2(Alloc2);
	t2.join();
}

void TestConcurrentAlloc()
{
	ConcurrentAlloc(6);
	ConcurrentAlloc(6);
	ConcurrentAlloc(6);
	ConcurrentAlloc(6);
}

int main()
{
	//TestObjectPool();
	//TLSTest();

	TestConcurrentAlloc();

	return 0;
}