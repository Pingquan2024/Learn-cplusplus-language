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
	// 可以给Lambda表达式 仿函数 函数对象
	std::thread t1(Alloc1);		// 创建了一个线程去执行这个函数
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