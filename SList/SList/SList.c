#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//只打印时不需要改变值，不用传入二级指针
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
	//申请空间要检验是否成功
	if (NewNode==NULL)
	{
		exit(-1);
	}
	else
	{
		//改变结点数据，将结点指向的指针指空，并返回结点指针
		NewNode->data = x;
		NewNode->next = NULL;
		return NewNode;
	}
}

void SListNodePushBack(SListNode** pphead, SListDataType x)
{
	//创建结点
	SListNode* NewNode=CreatNewNode(x);
	//1.头指针为空
	if (*pphead == NULL)
	{
		*pphead = NewNode;
	}
	////2.只有一个结点时
	//else if ((*pphead)->next == NULL)
	//{
	//	(*pphead)->next = NewNode;
	//}
	////3.一个结点以上
	else
	{
		//2.3两种情况可以结合
		//找到尾指针
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
	//1.无结点
	//2.1个结点
	//3.1个结点以上
	//如果使用第二种情况，*pphead为空指针，解引用越界访问,所以
	//需要该第一种情况单独讨论
	if (*pphead == NULL)
	{
		return;
	}
	//如果使用第三种情况，tail->next为空指针，解引用越界访问，所以
	//需要该第二种情况单独讨论
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//还是需要找到尾指针进行空间释放
		//但同时还需要找到上个结点进行指针的置空
		SListNode* tail = *pphead;
		SListNode* prev = NULL;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
		//tail和prev不需要置空，出函数自动销毁
	}
}

void SListNodePushFront(SListNode** pphead, SListDataType x)
{
	SListNode* NewNode = CreatNewNode(x);
	//当为空链表时，对空指针解引用会越界访问，所以需讨论该情况
	if (*pphead==NULL)
	{
		*pphead = NewNode;
	}
	//注意赋值的先后顺序
	else
	{
		NewNode->next = (*pphead);
		*pphead = NewNode;
	}
}

void SListNodePopFront(SListNode** pphead)
{
	//不论先释放还是先改*phead,都会各自丢失指针值，需要临时指针存储数据
	//如果为空指针，解引用非非法访问
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

//在pos之后插入，因为单链表插前面需要链表首指针
void SListNodeInsert(SListNode* pos, SListDataType x)
{
	SListNode* NewNode=CreatNewNode(x);
	NewNode->next = pos->next;
	pos->next = NewNode;
}

void SListNodeErase(SListNode* pos)
{
	//可能会造成空指针的解引用
	if(pos->next!=NULL)
	{
		SListNode* next = pos->next;
		next = next->next;
		free(pos->next);
		pos->next = next;
	}
		return;
}