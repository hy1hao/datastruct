#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

//传二级指针，是因为第一个指针需要修改
void SListPrint(SListNode* phead);
void SListPushBack(SListNode** pphead, SListDataType x);
void SListPopBack(SListNode** pphead);
SListNode* CreatSListNode(SListDataType x);