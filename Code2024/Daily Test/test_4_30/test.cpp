#include <iostream>
#include <stack>
using namespace std;

//236. 二叉树的最近公共祖先


//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x)
		: val(x)
		, left(nullptr)
		, right(nullptr)
	{}
};

bool GetPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
{
	if (root == nullptr)
		return false;

	path.push(root);
	if (root == x)
		return true;

	if (GetPath(root->left, x, path))
		return true;

	if (GetPath(root->right, x, path))
		return true;

	path.pop();
	return false;
}

class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> pPath, qPath;
		GetPath(root, p, pPath);
		GetPath(root, q, qPath);

		while (pPath.size() != qPath.size())
		{
			if (pPath.size() > qPath.size())
			{
				pPath.pop();
			}
			else
			{
				qPath.pop();
			}
		}

		while (pPath.top() != qPath.top())
		{
			pPath.pop();
			qPath.pop();
		}

		return pPath.top();
	}
};

int main()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);

	Solution s;
	TreeNode* result = s.lowestCommonAncestor(root, root->left, root->right);
	cout << "Lowest common ancestor: " << result->val << endl;

	return 0;
}