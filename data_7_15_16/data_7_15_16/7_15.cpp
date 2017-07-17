#include"7_15.h"

void InitList(PPNode pHead) // 初始化单链表
{
	*pHead = NULL;
}
Node* BuyNode(DataType data)      // 构建一个新节点
{
	PNode _node = (PNode)malloc(sizeof(Node));
	if (NULL == _node)
		exit(-1);
	_node->_data = data;
	_node->_pNext = NULL;
	return _node;
}
void PushBack(PPNode pHead, DataType data)          // 在单链表的尾部插入一个节点
{
	assert(pHead);
	if (NULL == *pHead)
	{
		*pHead = BuyNode(data);
	}
	else
	{
		PNode pnode = *pHead;
		while (pnode->_pNext)
		{
			pnode = pnode->_pNext;
		}
		pnode->_pNext = BuyNode(data);
	}
}

void PopBack(PPNode pHead)    // 删除单链表的最后一个节点
{
	assert(pHead);
	if (NULL == *pHead)
	{
		return;
	}
	else
	{
		PNode pnode = *pHead;
		while (pnode->_pNext->_pNext)
		{
			pnode = pnode->_pNext;
		}
		free(pnode->_pNext);
		pnode->_pNext = NULL;
	}
}
void PushFront(PPNode pHead, DataType data)      // 在单链表的头部插入值为data的结点
{
	assert(pHead);
	if (NULL == *pHead)
	{
		*pHead = BuyNode(data);
	}
	else
	{
		PNode pnode = BuyNode(data);
		pnode->_pNext = *pHead;
		*pHead = pnode;
	}
}
void PopFront(PPNode pHead)         // 删除单链表的第一个结点
{
	assert(pHead);
	if (NULL == *pHead)
	{
		return;
	}
	else
	{
		PNode pnode = (*pHead)->_pNext;
		free(*pHead);
		*pHead = pnode;
	}

}
Node* Find(PNode pHead, DataType data)     // 在单链表中查找值为data的结点，找到了返回该结点的地址，否则返回NULL
{
	//if (NULL != pHead)
	//{
	//	PNode pnode = pHead;
	//	while (pnode)
	//	{
	//		if (pnode->_data == data)
	//			return pnode;
	//		pnode = pnode->_pNext;
	//	}
	//}
	//return NULL;

	if (NULL != pHead)
	{
		PNode pnode = Find(pHead->_pNext, data);
		if (pnode)
			return pnode;
		if (pHead->_data == data)
			return pHead;
	}
	return NULL;
}
void Insert(PPNode pHead, PNode pos, DataType data)     // 在单链表pos位置后插入值为data的结点
{
	assert(pHead);
	PNode pnode = *pHead;
	PNode _pnode = NULL;
	if (NULL == *pHead || NULL == pos)
		return;
	while (pnode != pos)
		pnode = pnode->_pNext;
	_pnode = BuyNode(data);
	_pnode->_pNext = pnode->_pNext;
	pnode->_pNext = _pnode;
}
void Erase(PPNode pHead, PNode pos)   // 在单链表中删除位置为pos的结点
{
	assert(pHead);
	PNode pnode = *pHead;
	if (NULL == *pHead || NULL == pos)
		return;
	while (pnode != pos)
		pnode = pnode->_pNext;
	PNode _pnode = pnode->_pNext->_pNext;
	pnode->_data = pnode->_pNext->_data;
	free(pnode->_pNext);
	pnode->_pNext = _pnode;
}
void Remove(PPNode pHead, DataType data)      // 移除单链表中第一个值为data的结点
{
	assert(pHead);
	Erase(pHead, Find(*pHead, data));
}
void RemoveAll(PPNode pHead, DataType data)     // 移除单链表中所有值为data的结点
{
	assert(pHead);
	PNode pnode = NULL;
	if (NULL == *pHead)
		return;
	pnode = *pHead;
	while (pnode->_pNext)
	{
		if (pnode->_data == data)
		{
			Erase(&pnode, pnode);
		}
		else
		{
			pnode = pnode->_pNext;
		}
	}
}
size_t Size(PNode pHead)              // 获取单链表总结点的总个数
{
	size_t count = 0;
	if (NULL == pHead)
		return 0;
	while (pHead)
	{
		++count;
		pHead = pHead->_pNext;
	}
	return count;
}
int Empty(PNode pHead)        // 判断链表是否为空
{
	if (NULL == pHead)
		return 0;
	else
		return -1;
}
PNode Back(PNode pHead)          // 返回单链表的最后一个结点的位置
{
	if (NULL == pHead)
		return NULL;
	while (pHead->_pNext)
		pHead = pHead->_pNext;
	return pHead;
}
PNode Front(PNode pHead)       // 返回单链表的第一个结点的位置
{
	if (NULL == pHead)
		return NULL;
	return pHead;
}

void PrintList(PNode pHead)      // 正向打印单链表
{
	while (NULL != pHead)
	{
		printf("%d ", pHead->_data);
		pHead = pHead->_pNext;
	}
	printf("\n");
}


void PrintFromTail2Head(PNode pHead)//递归逆序打印单链表
{
	if (NULL != pHead)
	{
		if (pHead->_pNext != NULL)
		{
			PrintFromTail2Head(pHead->_pNext);
		}
	}
	printf("%d ", pHead->_data);
}

void DelFromTail2Head(PPNode pHead)
{
	assert(pHead);
	PNode pnode = *pHead;
	if (NULL != pnode)
	{
		if (NULL != pnode->_pNext)
		{
			DelFromTail2Head(&(pnode->_pNext));
		}
		free(pnode);
		pnode = NULL;
	}
}



bool Isexistloop(PNode head)//判断链表是否带环
{
	assert(head);
	PNode fast = head;
	PNode slow = head;

	while (fast&&fast->_pNext)
	{
		fast = fast->_pNext->_pNext;
		slow = slow->_pNext;
		if (fast == slow)
			return true;
	}
	return false;
}

size_t Looplength(PNode head)
{
	assert(head);
	PNode fast = head;
	PNode slow = head;
	size_t length = 1;
	//找到交点
	while (fast&&fast->_pNext)
	{
		fast = fast->_pNext->_pNext;
		slow = slow->_pNext;
		if (fast == slow)
			break;
	}
	//从交点开始遍历
	PNode cur = fast->_pNext;
	while (cur != fast)
	{
		length++;
		cur = cur->_pNext;
	}
	return length;
}
PNode Loopport(PNode head)
{
	assert(head);
	PNode fast = head;
	PNode slow = head;
	
	while (fast&&fast->_pNext)
	{
		fast = fast->_pNext->_pNext;
		slow = slow->_pNext;
		if (fast == slow)
			break;
	}
	PNode cur = head;
	while (cur != fast)
	{
		cur = cur->_pNext;
		fast = fast->_pNext;
	}
	return cur;
}


bool IsListCross(PNode L1, PNode L2)//判断两个链表是否相交（不带环）
{
	if ((L1 == NULL) || (L2 == NULL))
		return false;
	while (L1->_pNext)
		L1 = L1->_pNext;
	while (L2->_pNext)
		L2 = L2->_pNext;
	return L1 == L2;
}

PNode CrossPoint(PNode L1, PNode L2)//不带环求交点
{
	//求两个环的长度
	int length = 0;
	int length1 = 0;
	int length2 = 0;
	PNode head1 = L1;
	PNode head2 = L2;
	while (head1)
	{
		length1++;
		head1 = head1->_pNext;
	}
	while (head2)
	{
		length2++;
		head2 = head2->_pNext;
	}
	//两环长度之差
	length = abs(length1-length2);
	//长环先走(差)步
	if (length1 > length2)
	{
		while (length--)
			L1 = L1->_pNext;
		//相遇点为交点
		while (L1 != L2)
		{
			L1 = L1->_pNext;
			L2 = L2->_pNext;
		}
		return L1;
	}
	else
	{
		while (length--)
			L2 = L2->_pNext;
		while (L1 != L2)
		{
			L1 = L1->_pNext;
			L2 = L2->_pNext;
		}
		return L2;
	}
}
PNode CrossPointLoop(PNode L1, PNode L2)//两个链表都带环，求交点
{
	//求两个链表入口点
	PNode CrossPortL1 = Loopport(L1);
	PNode CrossPortL2 = Loopport(L2);
	PNode Ret = NULL;
	
	//判断两个入口点是否相等
	if (CrossPortL1 == CrossPortL2)
	{
		//相等，变Y求交点，复原
		PNode Last = CrossPortL1->_pNext;
		CrossPortL1->_pNext = NULL;
		Ret = CrossPoint(L1,L2);
		CrossPortL1->_pNext = Last;
	}
	else
	{
		//不相等，遍历一个链表的环的长度看是否能遇到另外一个链表的入口点
		size_t len = Looplength(L1);
		PNode next = CrossPortL1->_pNext;
		while (len--)
		{
			if (next == CrossPortL2)
			{
				Ret = CrossPortL2;
				break;
			}
			next = next->_pNext;
		}
		if (len <= 0)
			return NULL;
	}
	return Ret;
}


void Test()
{
	PNode L1 = NULL;
	PNode L2 = NULL;
	PushBack(&L1, 1);
	PushBack(&L1, 2);
	PushBack(&L1, 3);
	PushBack(&L1, 4);
	PushBack(&L2, 5);
	PushBack(&L2, 6);
	PushBack(&L2, 7);
	PushBack(&L2, 8);
	PushBack(&L2, 9);
	
	size_t s1 = Size(L1);
	size_t s2 = Size(L2);
	size_t i = 2;
	PNode head1 = L1;
	PNode head2 = L2;
	while (i--)
		head1 = head1->_pNext;
	i = 2;
	while (i--)
		head2 = head2->_pNext;
	head1->_pNext = head2;
	PNode JJ = head2;
	while (head2->_pNext)
		head2 = head2->_pNext;
	head2->_pNext = JJ;


	//if (IsListCross(L1, L2))
	//	printf("Yes\n");
	//else
	//	printf("Not\n");
	if (Isexistloop(L1))
		printf("Yes\n");
	else
		printf("Not\n");
	//PNode ret = CrossPoint(L1,L2);
	PNode ret = CrossPointLoop(L1,L2);
	size_t oo = Looplength(L1);
	size_t oo1 = Looplength(L2);

}


int main()
{
	Test();
	return 0;
}