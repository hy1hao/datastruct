#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//增删打印功能的测试
//void Test1()
//{
//	//初始化链表，将链表头指针置零
//	SListNode* pList=NULL;
//	SListNodePushBack(&pList, 1);
//	SListNodePushBack(&pList, 2);
//	SListNodePushBack(&pList, 3);
//	SListNodePushBack(&pList, 4);
//	SListNodePrint(pList);
//	SListNodePopBack(&pList);
//	SListNodePopBack(&pList);
//	SListNodePopBack(&pList);
//	SListNodePopBack(&pList);
//	SListNodePopBack(&pList);
//	SListNodePrint(pList);
//	SListNodePushFront(&pList, 1);
//	SListNodePushFront(&pList, 2);
//	SListNodePushFront(&pList, 3);
//	SListNodePushFront(&pList, 4);
//	SListNodeFind(pList, 3);
//	SListNodePrint(pList);
//	SListNodePopFront(&pList);
//	SListNodePopFront(&pList);
//	SListNodePopFront(&pList);
//	SListNodePopFront(&pList);
//	SListNodePopFront(&pList);
//	SListNodePrint(pList);
//}

//查改和插入功能的测试
void Test2()
{
	SListNode* pList = NULL;
	SListNodePushFront(&pList, 1);
	SListNodePushFront(&pList, 2);
	SListNodePushFront(&pList, 3);
	SListNodePushFront(&pList, 4);
	SListNode* finded= SListNodeFind(pList, 3);
	finded->data = 30;
	SListNodePrint(pList);
	SListNodeInsert(SListNodeFind(pList, 30), 8);
	SListNodePrint(pList);
	SListNodeErase(SListNodeFind(pList, 30));
	SListNodePrint(pList);
}

int main()
{
	//Test1();
	Test2();
	return 0;
}