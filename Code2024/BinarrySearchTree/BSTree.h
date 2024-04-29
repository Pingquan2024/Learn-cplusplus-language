#pragma once

#include <iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	BSTreeNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{ }
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(key);
		//链接
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		return true;
	}

	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while ()
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//相等  --- 删除
				if (cur->_left == nullptr)  //左为空
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_left;
					}
				
					delete cur;
				}
				else if(cur->_right == nullptr)  //右为空
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_left;
					}

					delete cur;
				}
				else
				{
					// 找右树最小节点替代，也可以是左树最大节点替代
				}
				return true;
			}
		}
		return false;
	}

	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	//inorder traversal  中序遍历
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root = nullptr;
};