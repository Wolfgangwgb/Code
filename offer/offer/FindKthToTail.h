#pragma once

#include<iostream>
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode* p = pListHead;
	for (unsigned int i = 0; i != k; i++)
	{
		if (p == NULL){
			return NULL;
		}
		else{
			p = p->next;
		}
	}
	while (p)
	{
		p = p->next;
		pListHead = pListHead->next;
	}
	return pListHead;
}