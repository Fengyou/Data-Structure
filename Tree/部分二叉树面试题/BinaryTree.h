#pragma once 
#include<iostream>
#include<assert.h>
#include<queue>
#include<list>

using namespace std;

template<class T>
struct Node
{
	T _data;
	Node<T>* _left;
	Node<T>* _right;

	Node(const T& x)
		:_data(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

template<class T>
class Tree
{
	typedef Node<T> Node;
public:
	Tree()
		:_root(NULL)
	{}
	//3.前序+中序---->Tree
	Tree(T *Prev,int size1,T *In,int size2)
	{
		assert(Prev);
		assert(In);
		if (Prev == NULL || In == NULL || size1 != size2)
			return; 
		else if (size1 == 1 && *Prev == *In)
			_root = new Node(*Prev);
		else
			_root = _CreateTree(Prev, Prev+size1-1, In,In+size2-1 );
	}
	~Tree()
	{
		//_Destroy(_root);
	}
public:
	//1.二叉树中两个节点的最近公共祖先节点
	Node* GetNearestGandfather(Node* child1, Node* child2)
	{
		Node* ret = _GetNearestGandfather(_root, child1, child2);
		cout << "GetNearestGandfather()?" << ret->_data << endl;
		return ret;
	}
	//2.二叉树中最远两个节点的距离
	int GetFarthest()
	{
		return _GetFarthest(_root);
	}
	//4.判断是不是完全二叉:只有最下面的两层结点度能够小于2，并且最下面一层的结点都集中在该层最左边的若干位置的二叉树
	bool IsComplete()
	{
		if (_root == NULL)       //空树    是
			return true;
		else if (_root->_left == NULL && _root->_right == NULL)       //只有一个节点   是
			return true;
		else
			return _IsComplete(_root);
	}
	//5.将二叉(搜索)树转换成一个(排序)的双向链表
	Node* Transform()
	{
		Node* ret = Convert(_root);
		cout << "头的值："<<ret->_data<<endl;
		return ret;
	}
	Node* Find(T& x)
	{
		Node* ret=_Find(_root, x);
		cout << "Find()?"<<ret->_data << endl;
		return ret;
	}
	void Print()
	{
		//_PrintPrev(_root);
		_PrintPost(_root);
		cout << endl;
	}
protected:
	void _Destroy(Node* root)
	{
		if (root)
		{
			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
		}
	}
	Node* _CreateTree(T* SPrev,T* EPrev,T* SIn,T* EIn)
	{
		Node* root = new Node(SPrev[0]);//前序的第一个为根
		T* rootIn = SIn;
		//中序中找到根节点
		while (rootIn <= EIn && root->_data != *rootIn)
			++rootIn;
		int leftLen = rootIn - SIn;
		T* leftPrevEnd = SPrev + leftLen;
		if (leftLen > 0)
			//左子树
			root->_left = _CreateTree(SPrev + 1, leftPrevEnd, SIn, rootIn - 1);
		if (leftLen < EPrev - SPrev)
			//右子树
			root->_right = _CreateTree(leftPrevEnd + 1, EPrev, rootIn+1, EIn);

		return root;
	}
	Node* _Find(Node* root, T& x)
	{
		if (root == NULL)
			return NULL;
		if (root->_data == x)
			return root;
		else
		{
			Node* l = _Find(root->_left, x);
			Node* r = _Find(root->_right, x);
			if (l != NULL)
				return l;
			if (r != NULL)
				return r;
		}
	}
	Node* _GetNearestGandfather(Node* root, Node* n1, Node* n2)
	{
		if (root == NULL)
			return NULL;
		if (root == n1 || root == n2)
			return root;
		int count = _countMatch(root->_left, n1, n2);//左子树包含n1和n2的个数  
		if (count == 1)
			return root;//左子树一个，右子树肯定也有一个  
		else if (count == 2)//都在左子树  
			return _GetNearestGandfather(root->_left, n1, n2);
		else//都在右子树  
			return _GetNearestGandfather(root->_right, n1, n2);
	}
	//计算当前结点包含n1、n2个数  
	int _countMatch(Node *current, Node* n1, Node* n2)
	{
		if (current == NULL)
			return 0;
		int count = _countMatch(current->_left, n1, n2) + _countMatch(current->_right, n1, n2);
		if (current == n1 || current == n2)
			return 1 + count;
		return count;
	}
	bool _IsComplete(Node* root)
	{
		//队列 层序遍历    
		queue<Node*> q;
		q.push(root);
		while (!q.empty())
		{
			Node* Front = q.front();
			q.pop();
			if (Front->_left)
			{
				q.push(Front->_left);
				if (Front->_right)       
					q.push(Front->_right);
				else                       //当某节点节点只有左孩子，则之后的节点都能为叶子        是
				{
					while (!q.empty())
					{
						Front = q.front();
						if (Front->_left == NULL && Front->_right == NULL)
							q.pop();
						else
							return false;
					}
				}
			}
			else                        //当某节点是叶子，则之后的节点都是叶子            是
			{
				while (!q.empty())
				{
					Front = q.front();
					if (Front->_left == NULL && Front->_right == NULL)
						q.pop();
					else
						return false;
				}
			}
		}
		return true;
	}
	int _GetFarthest(Node* root)
	{
		if (root == NULL)
			return 0;
		Node* curL = root;
		Node* curR = root;
		int countL = 0;
		int countR = 0;
		while (curL->_left || curL->_right)
		{
			while (curL->_left)
			{
				countL++;
				curL = curL->_left;
			}
			if (curL->_right)
			{
				countL++;
				curL = curL->_right;
			}
		}
		while (curR->_right || curR->_left)
		{
			while (curR->_right)
			{
				countR++;
				curR = curR->_right;
			}
			if (curR->_left)
			{
				countR++;
				curR = curR->_left;
			}
		}
		return countL + countR;
	}
	Node* Convert(Node* root)
	{
		Node* pLastNodeInList = NULL;
		ConvertNode(root, &pLastNodeInList);

		Node* pHeadOfList = pLastNodeInList;
		while (pHeadOfList != NULL && pHeadOfList->_left != NULL)
			pHeadOfList = pHeadOfList->_left;

		return pHeadOfList;
	}
	void ConvertNode(Node *root, Node** pLastNodeList)
	{
		if (root == NULL)
			return;
		Node* cur = root;
		if (cur->_left != NULL)
			ConvertNode(cur->_left, pLastNodeList);
		
		cur->_left = *pLastNodeList;
		if (*pLastNodeList != NULL)
				(*pLastNodeList)->_right = cur;

		*pLastNodeList = cur;
		if (cur->_right != NULL)
			ConvertNode(cur->_right, pLastNodeList);
	}

	void _PrintPrev(Node* root)
	{
		if (root)
		{
			cout << root->_data<<" ";
			_PrintPrev(root->_left);
			_PrintPrev(root->_right);
		}
	}
	void _PrintPost(Node* root)
	{
		if (root)
		{
			_PrintPost(root->_left);
			_PrintPost(root->_right);
			cout << root->_data<<" ";
		}
	}
	

private:
	Node* _root;
}; 