//
//struct TreeNode
//{
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//
//	TreeNode(int x)
//		: val(x)
//		, left(nullptr)
//		, right(nullptr)
//	{}
//};
//
//class Solution
//{
//public:
//	int BinarryTreeHeight(TreeNode* root)
//	{
//		if (root == nullptr)
//		{
//			return 0;
//		}
//		int ret1 = BinarryTreeHeight(root->left);
//		int ret2 = BinarryTreeHeight(root->right);
//
//		return ret1 > ret2 ? ret1 + 1 : ret2 + 1;
//	}
//
//	bool IsBalanced_Solution(TreeNode* pRoot)
//	{
//		if (pRoot == nullptr)
//		{
//			return true;
//		}
//
//		int rightHeight = BinarryTreeHeight(pRoot->right);
//		int leftHeight = BinarryTreeHeight(pRoot->left);
//		int ret = rightHeight - leftHeight;
//		if (ret > 1 || ret < -1)
//		{
//			return false;
//		}
//
//		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
//	}
//};
//
//int main()
//{
//	struct TreeNode tree(1);
//	TreeNode* left = new TreeNode(2);
//	TreeNode* right = new TreeNode(3);
//	tree.left = left;
//	tree.right = right;
//
//	Solution().IsBalanced_Solution(&tree);
//	return 0;
//}



//#include <iostream>
//
//using namespace std;
//
//int n;
//int arr[110][110];
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { -1,1,0,0 };
//
//bool bfs(int arr[][110], int i, int j)
//{
//    for (int k = 0; k < 4; k++)
//    {
//        int a = i + dx[k], b = j + dy[k];
//        if ()
//    }
//}
//
//int main()
//{
//    cin >> n;
//    bool hash[110][110] = { 0 };
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            cin >> arr[i][j];
//        }
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            hash[i][j] = true;
//            if (bfs(arr, i, j))
//            {
//
//            }
//        }
//    }
//}
