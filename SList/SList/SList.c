#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//ֻ��ӡʱ����Ҫ�ı�ֵ�����ô������ָ��
void SListNodePrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SListNode* CreatNewNode(SListDataType x)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	//����ռ�Ҫ�����Ƿ�ɹ�
	if (NewNode==NULL)
	{
		exit(-1);
	}
	else
	{
		//�ı������ݣ������ָ���ָ��ָ�գ������ؽ��ָ��
		NewNode->data = x;
		NewNode->next = NULL;
		return NewNode;
	}
}

void SListNodePushBack(SListNode** pphead, SListDataType x)
{
	//�������
	SListNode* NewNode=CreatNewNode(x);
	//1.ͷָ��Ϊ��
	if (*pphead == NULL)
	{
		*pphead = NewNode;
	}
	////2.ֻ��һ�����ʱ
	//else if ((*pphead)->next == NULL)
	//{
	//	(*pphead)->next = NewNode;
	//}
	////3.һ���������
	else
	{
		//2.3����������Խ��
		//�ҵ�βָ��
		SListNode* tail = NULL;
		tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = NewNode;
	}
}

void SListNodePopBack(SListNode** pphead)
{
	//1.�޽��
	//2.1�����
	//3.1���������
	//���ʹ�õڶ��������*ppheadΪ��ָ�룬������Խ�����,����
	//��Ҫ�õ�һ�������������
	if (*pphead == NULL)
	{
		return;
	}
	//���ʹ�õ����������tail->nextΪ��ָ�룬������Խ����ʣ�����
	//��Ҫ�õڶ��������������
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//������Ҫ�ҵ�βָ����пռ��ͷ�
		//��ͬʱ����Ҫ�ҵ��ϸ�������ָ����ÿ�
		SListNode* tail = *pphead;
		SListNode* prev = NULL;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
		//tail��prev����Ҫ�ÿգ��������Զ�����
	}
}

void SListNodePushFront(SListNode** pphead, SListDataType x)
{
	SListNode* NewNode = CreatNewNode(x);
	//��Ϊ������ʱ���Կ�ָ������û�Խ����ʣ����������۸����
	if (*pphead==NULL)
	{
		*pphead = NewNode;
	}
	//ע�⸳ֵ���Ⱥ�˳��
	else
	{
		NewNode->next = (*pphead);
		*pphead = NewNode;
	}
}

void SListNodePopFront(SListNode** pphead)
{
	//�������ͷŻ����ȸ�*phead,������Զ�ʧָ��ֵ����Ҫ��ʱָ��洢����
	//���Ϊ��ָ�룬�����÷ǷǷ�����
	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		SListNode* tmp = NULL;
		tmp=(*pphead)->next;
		free(*pphead);
		*pphead = tmp;
	}
}
SListNode* SListNodeFind(SListNode* phead, SListDataType x)
{
	SListNode* Find = phead;
	while (Find)
	{
		if (Find->data == x)
		{
			return Find;
		}
		Find = Find->next;
	}
	return NULL;
}

//��pos֮����룬��Ϊ�������ǰ����Ҫ������ָ��
void SListNodeInsert(SListNode* pos, SListDataType x)
{
	SListNode* NewNode=CreatNewNode(x);
	NewNode->next = pos->next;
	pos->next = NewNode;
}

void SListNodeErase(SListNode* pos)
{
	//���ܻ���ɿ�ָ��Ľ�����
	if(pos->next!=NULL)
	{
		SListNode* next = pos->next;
		next = next->next;
		free(pos->next);
		pos->next = next;
	}
		return;
}