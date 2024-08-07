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
	// malloc�͵�ǰ�����ڴ�����ܶԱ�
	
	// ������ͷŵ��ִ�
	const size_t Rounds = 2;

	// ÿ�������ͷŵĴ���
	const size_t N = 2;

	std::vector<TreeNode*> v1;
	v1.reserve(N);	// Ԥ��N���洢�ռ��С

	// ����malloc������
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

		v1.clear();	// ��vector�е�������գ�size���㣬capacity����
	}
	size_t end1 = clock();

	std::vector<TreeNode*> v2;
	v2.reserve(N);

	// ���Զ����ڴ��
	ObjectPool<TreeNode> TPool;
	size_t begin2 = clock();
	for (size_t i = 0; i < Rounds; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			// �����ڴ��������ռ�
			v2.push_back(TPool.New());
		}
		for (size_t j = 0; j < N; j++)
		{
			// �����ڴ�ػ��տռ�
			TPool.Delete(v2[j]);
		}

		v2.clear();
	}
	size_t end2 = clock();

	cout << "malloc and free time:" << end1 - begin1 << endl;	// ��λms
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
//	// ���Ը�Lambda���ʽ �º��� ��������
//	std::thread t1(Alloc1);		// ������һ���߳�ȥִ���������
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