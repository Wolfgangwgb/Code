#include<iostream>
using namespace std;
#define DATATYPE int

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
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	struct Node* result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	if (a->data <= b->data)
	{
		result = a;
		result->_next = SortedMerge(a->_next, b);
	}
	else
	{
		result = b;
		result->_next = SortedMerge(a, b->_next);
	}
	return (result);
}





void print(struct Node* head)
{
	struct Node* _head = head;
	while (_head != NULL)
	{
		cout << _head->data << " ";
		_head = _head->_next;
	}
	cout << endl;
}
void test()
{
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	struct Node* head3 = NULL;
	push(&head1,1);
	push(&head1, 2);
	push(&head1, 3);
	push(&head1, 4);
	print(head1);
	push(&head2, 5);
	push(&head2, 6);
	push(&head2, 7);
	push(&head2, 8);
	print(head2);

	head3 = SortedMerge(head1,head2);
	print(head3);
}