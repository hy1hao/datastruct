#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void SListPrint(SListNode* phead)
{
	//����Ҫ����Ϊֱ�Ӵ�ӡ
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
		//�½����ĵ�ַҪע����Ϊ��ָ��
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
	//����Կ�ָ���������ɵķǷ�����
	if (*pphead == NULL)
	{
		*pphead = CreatSListNode(x);
	}
	else
	{
		//���޽��ʱ��tailΪ��ָ�룬�޷������ã��Ƿ�����
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
	//1.��Ԫ��
	//2.һ��Ԫ��
	//3.һ������
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
		//��ֻ��һ�����ʱ��prevΪ��ָ�룬�����û���ɷǷ�����
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
