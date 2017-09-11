#pragma once

#include<iostream>

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};


ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head != NULL){
		head->val = -1;
		head->next = pHead;
		ListNode* p = head;
		ListNode* q = head->next;
		while (q)
		{
			while (q->next && (q->val == q->next->val))//处理连续相同的结点
			{
				q = q->next;
			}
			if (p->next != q)//
			{
				q = q->next;
				p->next = q;
			}
			else
			{
				p = q;
				q = q->next;
			}
		}
	}
	return head->next;

}
