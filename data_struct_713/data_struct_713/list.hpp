#include<iostream>
using namespace std;
#define DATATYPE int
//7-13题目：
//1.【基础题】--合并两个有序链表，合并以后的链表依旧有序。//complete
//2.【附加题】--实现1 + 2 + 3... + n，要求不能使用乘除法、
//循环、条件判断、选择相关的关键字。（这个题有多种解法，
//大家可以尽量去思考，这个题最优的解法时间复杂度是O(1），
//大家可以去尝试实现）


//7-14题目
//1.【基础题】--逆置/反转单链表+查找单链表的倒数第k个节点，要求只能遍历一次链表 
//2.【附加题】--实现一个Add函数，让两个数相加，但是不能使用 + 、 - 、*、 / 
//等四则运算符。ps : 也不能用++、--等等


//需要复习知识点
//1.new/delete/new[]/delete[]/malloc/calloc/realloc/free
//2.顺序表、链表
//3.数据结构时间复杂度和空间复杂度计算
//4.struct、联合体、enum
//5.



struct Node
{
	DATATYPE data;
	struct Node* _next;
};


void push(struct Node** head, DATATYPE data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	if (new_node == NULL)
	{
		cout << "malloc" << endl;
	}

	new_node->data = data;
	new_node->_next = *head;

	*head = new_node;
	//free(new_node);
}

//递归合并

//合并单链表
/*
struct Node* SortedMerge(struct Node* head1, struct Node* head2)
{
	struct Node* end = NULL;
	struct Node* ret = NULL;
	//判断两个链表某一个是否为空
	if (head1 == NULL)
	{
		return head2;
	}
	else if (head2 == NULL)
	{
		return head1;
	}
	//end赋初值
	if (head1->data <= head2->data)
	{
		end = head2;
		head2 = head2->_next;
	}
	else
	{
		end = head1;
		head1 = head1->_next;
	}
	//遍历链表排序
	ret = end;
	while (head1&&head2)
	{
		
		//31  42
		if (head1->data <= head2->data)
		{
			end->_next = head2;
			head2 = head2->_next;
		}
		else
		{
			end->_next = head1;
			head1 = head1->_next;
		}
		end = end->_next;
	}
	//出循环后判断两个链表那个不为空就连接在后面
	if (head1)
	{
		end->_next = head1;
	}
	if (head2)
	{
		end->_next = head2;
	}
	return ret;
}
*/

//2
struct Node* SortedMerge(struct Node* head1, struct Node* head2)
{
	struct Node* ret = NULL;
	//判断两个链表某一个是否为空
	if (head1 == NULL)
	{
		return head2;
	}
	else if (head2 == NULL)
	{
		return head1;
	}
	//end赋初值
	if (head1->data <= head2->data)
	{
		ret = head2;
		ret->_next = SortedMerge(head1,head2->_next);
	}
	else
	{
		ret = head1;
		ret->_next = SortedMerge(head1->_next, head2);
	}
	return ret;
}

//逆置、翻转单链表
//1.头插法逆置
void Inverse1(struct Node** head)
{
	struct Node* head1 = *head;
	struct Node* ret = NULL;
	while (head1)
	{
		push(&ret,head1->data);
		head1 = head1->_next;
	}
	*head = ret;
}
//2.结点逆置
void Inverse2(struct Node** head)
{
	struct Node* Pre = NULL;
	struct Node* Cur = *head;
	struct Node* Next = NULL;

	while (Cur)
	{
		Next = Cur->_next;
		Cur->_next = Pre;
		Pre = Cur;
		Cur = Next;
	}
	*head = Pre;
}
//3.值逆置 not complete
void Inverse3(struct Node** head)
{
	struct Node* start = *head;
	struct Node* last = *head;
}

//查找单链表的倒数第k个结点
struct Node Find_k(struct Node* head,size_t k)
{
	size_t n = 0;
	size_t sep = 0;
	struct Node* first = head;
	struct Node ret ;
	while (first)
	{
		n++;
		first = first->_next;
	}
	//sep = n - k - 1;//从0开始
	sep = n - k;//从1开始
	while (sep--)
	{
		head = head->_next;
	}
	ret = *head;
	return ret;
}


void print(struct Node* head)
{
	//struct Node* _head = head;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->_next;
	}
	cout << endl;
}



void test()
{
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	struct Node* head3 = NULL;
	push(&head1,1);
	//push(&head1, 2);
	push(&head1, 3);
	//push(&head1, 4);
	print(head1);
	//push(&head2, 5);
	//push(&head2, 6);
	push(&head2, 2);
	push(&head2, 4);
	print(head2);

	head3 = SortedMerge(head1,head2);
	print(head3);
}

void test2()
{
	struct Node* head1 = NULL;
	struct Node ret;
	push(&head1, 1);
	push(&head1, 2);
	push(&head1, 3);
	push(&head1, 4);
	push(&head1, 5);
	print(head1);
	//Inverse1(&head1);
	ret = Find_k(head1,2);
	cout << ret.data << endl;
}


int Add(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	int first = a^b;
	int second = a&b;
	return Add(first,second);
}



