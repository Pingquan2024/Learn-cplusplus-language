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
	//左旋
	void RotateL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;

		parent->_right = SubRL;
		if(SubRL)
			SubRL->_parent = parent;

		Node* pparent = parent->_parent;

		SubR->_left = parent;
		parent->_parent = SubR;

		if (pparent == nullptr)
		{
			_root = SubR;
			SubR->_parent = nullptr;
		}
		else
		{
			//不是整棵树调整
			//parent可能是pparentd的左边，也可能是右边
			if (pparent->_left == parent)
			{
				pparent->_left = SubR;
			}
			else if (pparent->_right == parent)
			{
				pparent->_right = SubR;
			}
		}

		parent->_bf = SubR->bf = 0;
	}

	//右旋
	void RotateR(Node* parent) 
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		
		SubL->_right = parent;
		parent->_left = SubLR;
		
		if(SubLR)
			SubLR->_parent = parent;

		Node* ppnode = parent->_parent;

		parent->_parent = SubL;

		if (ppnode == nullptr)
		{
			_root = SubL;
			SubL->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = SubL;
			}
			else
			{
				ppnode->_right = SubL;
			}
			SubL->_parent = parent;
		}

		SubL->_bf = parent->_bf = 0;
	}

	Node* _root = nullptr;
};