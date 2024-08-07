#include <vector>
#include "ObjectPool.h"
//#include "ConcurrentAlloc.h"

# if 0
struct TreeNode
{
	TreeNode* _left;
	TreeNode* _right;
	int _val;

	TreeNode()
		:_val(0)
		,_left(nullptr)
		,_right(nullptr)
	{}
};

void TestObjectPool()
{
	// malloc和当前定长内存池性能对比
	
	// 申请和释放的轮次
	const size_t Rounds = 2;

	// 每轮申请释放的次数
	const size_t N = 2;

	std::vector<TreeNode*> v1;
	v1.reserve(N);	// 预留N个存储空间大小

	// 测试malloc的性能
	size_t begin1 = clock();
	for (size_t i = 0; i < Rounds; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			v1.push_back(new TreeNode);
		}
		for (size_t j = 0; j < N; i++)
		{
			delete v1[j];
		}

		v1.clear();	// 将vector中的内容清空，size置零，capacity不变
	}
	size_t end1 = clock();

	std::vector<TreeNode*> v2;
	v2.reserve(N);

	// 测试定长内存池
	ObjectPool<TreeNode> TPool;
	size_t begin2 = clock();
	for (size_t i = 0; i < Rounds; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			// 定长内存池中申请空间
			v2.push_back(TPool.New());
		}
		for (size_t j = 0; j < N; j++)
		{
			// 定长内存池回收空间
			TPool.Delete(v2[j]);
		}

		v2.clear();
	}
	size_t end2 = clock();

	cout << "malloc and free time:" << end1 - begin1 << endl;	// 单位ms
	cout << "object pool time:" << end2 - begin2 << endl;
}
#endif

//void Alloc1()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		void* ptr = ConcurrentAlloc(6);
//	}
//}
//
//void Alloc2()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		void* ptr = ConcurrentAlloc(15);
//	}
//}
//
//void TLSTest()
//{
//	// 可以给Lambda表达式 仿函数 函数对象
//	std::thread t1(Alloc1);		// 创建了一个线程去执行这个函数
//	t1.join();
//
//	std::thread t2(Alloc2);
//	t2.join();
//}
//
//void TestConcurrentAlloc()
//{
//	ConcurrentAlloc(6);
//	ConcurrentAlloc(6);
//	ConcurrentAlloc(6);
//	ConcurrentAlloc(6);
//}

int main()
{
	//TestObjectPool();
	//TLSTest();

	//TestConcurrentAlloc();

	return 0;
}