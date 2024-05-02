#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template<class K,class V>
class AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf;                      //balance factor(平衡因子)

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		,_kv(kv)
		,_bf(0)
	{ }
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	bool Insert(const pair<K,V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		//链接
		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->parent = parent;

		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent->_bf == 1 || parent->_bf == -1)
			{
				//继续更新
				parent = parent->_parent;
				cur = cur->_left;
			}
			else if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//旋转
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

private:
	Node* _root = nullptr;
};