#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

//������ָ�룬����Ϊ��һ��ָ����Ҫ�޸�
void SListPrint(SListNode* phead);
void SListPushBack(SListNode** pphead, SListDataType x);
void SListPopBack(SListNode** pphead);
SListNode* CreatSListNode(SListDataType x);