#include <Windows.h>
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include<stdlib.h>


typedef int DataType;

#include<stdio.h>

typedef int DataType;

typedef struct Node
{
	DataType _data;
	struct Node* _pNext;
}Node, *PNode, **PPNode;



void InitList(PPNode pHead);                             // 初始化单链表
void PushBack(PPNode pHead, DataType data);           // 在单链表的尾部插入一个节点
void PopBack(PPNode pHead);                  // 删除单链表的最后一个节点
void PushFront(PPNode pHead, DataType data);      // 在单链表的头部插入值为data的结点
void PopFront(PPNode pHead);           // 删除单链表的第一个结点
Node* Find(PNode pHead, DataType data);     // 在单链表中查找值为data的结点，找到了返回该结点的地址，否则返回NULL
void Insert(PPNode pHead, PNode pos, DataType data);     // 在单链表pos位置后插入值为data的结点
void Erase(PPNode pHead, PNode pos);     // 在单链表中删除位置为pos的结点
void Remove(PPNode pHead, DataType data);      // 移除单链表中第一个值为data的结点
void RemoveAll(PPNode pHead, DataType data);     // 移除单链表中所有值为data的结点
size_t Size(PNode pHead);               // 获取单链表总结点的总个数
int Empty(PNode pHead);         // 判断结点是否为空
PNode Back(PNode pHead);          // 返回单链表的最后一个结点的位置
PNode Front(PNode pHead);       // 返回单链表的第一个结点的位置
Node* BuyNode(DataType data);      // 构建一个新节点
void PrintList(PNode pHead);      // 正向打印单链表
void DelFromTail2Head(PPNode pHead);//逆向销毁单链表


///////////////面试题//////////////////////////////
void PrintFromTail2Head(PNode pHead);       // 逆序打印单链表
void DeleteNotTailNode(PNode pos);         // 删除单链表的非尾结点(不能遍历单链表)

void PrintFromTail2Head(PNode pHead);   // 使用递归实现从尾到头打印单链表


void InsertNotHeadNode(PNode pos, DataType data);   // 在单链表非头结点前插入结点data
PNode FindMidNode(PNode pHead);     // 查找单链表的中间结点，要求只便利一次链表
PNode FindLastKNode(PNode pHead, size_t k);   // 查找单链表的倒数第K个结点，要求只遍历一次链表
void BubbleSort(PNode pHead);    // 使用冒泡排序对单链表进行排序
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
bool IsListCross(PNode L1, PNode L2);   // 判断两个单链表是否相交(链表不带环)
PNode CrossPoint(PNode L1, PNode L2);//不带环求交点
PNode CrossPointLoop(PNode L1, PNode L2);//带环求交点

bool Isexistloop(PNode pHead);//判断是否带环
size_t Looplength(PNode pHead);//环的长度
PNode Loopport(PNode PHead);//求环的交点



