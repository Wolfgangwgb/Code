#include <utility>
#include<iostream>
using namespace std;

template <class K,int M>
struct BTreeNode
{
	K _keyarray[M];//关键字   数量多一个
	BTreeNode<K, M>* _childarray[M + 1];//孩子
	BTreeNode<K, M>* _parent;//双亲
	size_t _size;//有效元素个数
	BTreeNode()
		:_parent(NULL)
		, _size(0)
	{
		for (size_t idx = 0; idx < M + 1; ++idx)
			_childarray[idx] = NULL;
	}
};

//插入：
//	1.空树
//	2.非空
//			1.判断插入key与结点中key的大小，寻找插入位置----->find
//			2.插入
//			3.判断_size和M的大小；小于插入正确返回true;等于进行分裂
//			4.分裂：1.找中间位置
//					2.创建新节点，将右半部分移至新节点
//					3.中间元素：1.双亲存在
//								2.双亲不存在 -->创建新节点，将中间元素移至新节点，更新孩子


template <class K,int M>
class BTree
{
	typedef BTreeNode<K, M> Node;
	typedef pair<Node*, int> Pair;
public:
	BTree()
		:_pRoot(NULL)
	{}

	bool Insert(const K& key)
	{
		if (NULL == _pRoot)
		{
			_pRoot = new Node;
			_pRoot->_keyarray[0] = key;
			_pRoot->_size = 1;
			return true;
		}
		else
		{
			pair<Node*,int> pCur = _Find(key);
			if (pCur.second > -1)
				return false;

			Node* pNode = pCur.first;
			K _k = key;
			Node* childarray = NULL;

			while (true)
			{
				_Insert(pNode, _k, childarray);


				if (pNode->_size < M)
					return true;
				//需要对节点进行分裂
				Node* pNewNode = new Node;
				size_t mid = M / 2;
				size_t index = 0;
				size_t idx = 0;

				//搬移元素和孩子指针到pNewNode
				for (idx = mid + 1; idx<pNode->_size; ++idx)
				{
					pNewNode->_keyarray[index] = pNode->_keyarray[idx];
					pNewNode->_childarray[index] = pNode->_childarray[idx];
					if (pNode->_childarray[idx])
					{
						pNode->_childarray[idx]->_parent = pNewNode->_childarray[index];
						pNode->_childarray[idx] = NULL;
					}
					pNewNode->_size++;
					pNode->_size--;
					index++;
				}

				pNewNode->_childarray[index] = pNode->_childarray[idx];
				if (pNode->_childarray[idx])
				{
					pNode->_childarray[idx]->_parent = pNewNode->_childarray[index];
					pNode->_childarray[idx] = NULL;
				}
				pNode->_size = pNode->_size - pNewNode->_size;

				//判断该节点是否为根节点
				if (pNode->_parent == NULL)
				{
					_pRoot = new Node;
					_pRoot->_keyarray[0] = pNode->_keyarray[mid];

					_pRoot->_childarray[0] = pNode;
					pNode->_parent = _pRoot;
					_pRoot->_childarray[1] = pNewNode;
					pNewNode->_parent = _pRoot;
					_pRoot->_size++;
					return true;
				}
				else
				{
					_k = pNode->_keyarray[mid];
					pNode = pNode->_parent;
					childarray = pNewNode;
				}
			}
		}
	}
private:
	Pair _Find(const K& key)
	{
		if (NULL == _pRoot)
			return Pair(NULL, -1);
		else
		{
			Node* pCur = _pRoot;
			Node* parent = NULL;
			while (pCur)
			{
				size_t i = 0;
				while (i < pCur->_size)
				{
					if (key < pCur->_keyarray[i])
					{
						break;
					}
					else if (key > pCur->_keyarray[i])
					{
						++i;
					}
					else
					{
						return Pair(pCur, i);
					}
				}
				parent = pCur;
				pCur = pCur->_childarray[i];
			}
			return Pair(parent , -1);
		}
	}
	void _Insert(Node*& pNode, const K& key, Node* pSub)
	{
		int end = pNode->_size - 1;
		while (end > -1)
		{
			if (pNode->_keyarray[end] > key)
			{
				pNode->_keyarray[end + 1] = pNode->_keyarray[end];
				pNode->_childarray[end + 2] = pNode->_childarray[end + 1];
			}
			else
				break;
			end--;
		}
		pNode->_keyarray[end + 1] = key;
		pNode->_childarray[end + 2] = pSub;
		if (pSub)
			pSub->_parent = pNode;
		pNode->_size++;
	}

private:
	Node* _pRoot;
};

void Test()
{
	int a[] = {53,75,139,49,145,36,101};

	BTree<int, 3> b;
	for (size_t index = 0; index < sizeof(a) / sizeof(a[0]); ++index)
	{
		b.Insert(a[index]);
	}

}