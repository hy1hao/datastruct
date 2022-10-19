#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void SListPrint(SListNode* phead)
{
	//不需要，因为直接打印
	//if (phead == NULL)
	//{
	//	printf("NULL\n");
	//}
		SListNode* cur = phead;
		while (cur != NULL)
		{
			printf("%d->", cur->data);
			cur = cur->next;
		}
		printf("NULL\n");
}

SListNode* CreatSListNode(SListDataType x)
{
	SListNode* newNode =(SListNode*)malloc(sizeof(SListNode));
	if (newNode != NULL)
	{
		newNode->data = x;
		//新建结点的地址要注意置为空指针
		newNode->next = NULL;
		return newNode;
	}
	else
	{
		exit(-1);
	}
}

void SListPushBack(SListNode** pphead, SListDataType x)
{
	//避免对空指针解引用造成的非法访问
	if (*pphead == NULL)
	{
		*pphead = CreatSListNode(x);
	}
	else
	{
		//当无结点时，tail为空指针，无法解引用，非法访问
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = CreatSListNode(x);
	}
}

void SListPopBack(SListNode** pphead)
{
	//1.无元素
	//2.一个元素
	//3.一个以上
	if (*pphead == NULL)
	{
		return;
	}
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//当只有一个结点时，prev为空指针，解引用会造成非法访问
		SListNode* tail = *pphead;
		SListNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
