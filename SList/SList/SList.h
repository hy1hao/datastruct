#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef int SListDataType;

typedef struct SLsitNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

void SListNodePrint(SListNode* phead);

void SListNodePushBack(SListNode** pphead, SListDataType x);

void SListNodePopBack(SListNode** pphead);

void SListNodePushFront(SListNode** pphead, SListDataType x);

void SListNodePopFront(SListNode** pphead);

SListNode* SListNodeFind(SListNode* phead, SListDataType x);

void SListNodeInsert(SListNode* pos, SListDataType x);