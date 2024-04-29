#include "BSTree.h"

void testBSTree()
{
	int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> t1;
	for (auto e : arr)
	{
		t1.Insert(e);
	}

	t1.InOrder();

	t1.Erase(8);
	t1.InOrder();

}

int main()
{
	testBSTree();
	return 0;
}