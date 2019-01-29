#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define OK 1
#define ERROR -1

typedef int ElemType;
typedef int Status;

typedef struct DuNode
{
	ElemType data;
	struct DuNode *prior;
	struct DuNode *next;
}DuNode,*DuLinkedList;


Status  createListF(DuLinkedList *head,DuLinkedList *tail,int len);
Status  createListR(DuLinkedList *head,DuLinkedList *tail,int len);
Status  deleteElem(DuLinkedList *head,DuLinkedList *tail,int locate,ElemType *e);
Status  insertElem(DuLinkedList *head,DuLinkedList *tail,int locate,ElemType e);
void destroyList(DuLinkedList *head);
int length(DuLinkedList head);
void printList(DuLinkedList head);
void clearList(DuLinkedList *head);
void listTraverse(DuLinkedList head);
void visit(DuNode *p);


int  _tmain(int argc, _TCHAR* argv[])
{	
	system("title 双链表操作");
	
	int len = 12;

	printf("创建链表\n");
	DuLinkedList head = NULL,tail = NULL;
	createListR(&head,&tail,len);
	printf_s("链表的长度：%d\n",length(head));
	printList(head);

	ElemType e = 0;
	srand((unsigned int)time(NULL));

	/*插入元素*/
	/*
	  第1个测试用例：
	  在位置3插入元素
   */
	//插入的元素的位置
	int locate = 4;
	e = rand()%200+1;
	insertElem(&head,&tail,locate,e);
	printf("在%d处插入元素%d后，长度为：%d\n",locate,e,length(head));
	printList(head);


	/*第2个测试用例：在表头插入元素*/
	locate = 1;
	e = rand()%88+1;
	insertElem(&head,&tail,locate,e);
	printf("在%d处插入元素%d后，长度为：%d\n",locate,e,length(head));
	printList(head);

	/*第3个测试用例：在表尾插入元素*/
	locate = length(head);
	e = rand()%100+1;
	insertElem(&head,&tail,locate,e);
	printf("在%d处插入元素%d后，长度为：%d\n",locate,e,length(head));
	printList(head);


	/*第4个测试用例：在-1处插入元素*/
	locate = -1;
	e = rand()%100+1;
	insertElem(&head,&tail,locate,e);
	printf("在%d处插入元素%d后，长度为：%d\n",locate,e,length(head));
	printList(head);

	/*第5个测试用例：在length(head)+1插入元素*/
	locate = length(head)+1;
	e = rand()%100+1;
	insertElem(&head,&tail,locate,e);
	printf("在%d处插入元素%d后，长度为：%d\n",locate,e,length(head));
	printList(head);

	/*第6个测试用例：在length(head)+2处插入元素*/
	locate = length(head)+2;
	e = rand()%100+1;
	insertElem(&head,&tail,locate,e);
	printf("在%d处插入元素%d后，长度为：%d\n",locate,e,length(head));
	printList(head);

	/*第7个测试用例：在0处插入元素*/
	locate = 0;
	e = rand()%100+1;
	insertElem(&head,&tail,locate,e);
	printf("在%d处插入元素%d后，长度为：%d\n",locate,e,length(head));
	printList(head);

	///*删除元素*/
	///*
	//  第1个测试用例：
	//  删除位置3的元素
 //  */
	////删除的元素的位置
	//int locate = 3;
	//deleteElem(&head,&tail,locate,&e);
	//printf("删除位置%d处的元素后，长度为：%d\n",locate,length(head));
	//printList(head);


	///*第2个测试用例：删除头指针*/
	//locate = 1;
	//deleteElem(&head,&tail,locate,&e);
	//printf("删除位置%d处的元素后，长度为：%d\n",locate,length(head));
	//printList(head);

	///*第3个测试用例：删除尾指针*/
	//locate = length(head);
	//deleteElem(&head,&tail,locate,&e);
	//printf("删除位置%d处的元素后，长度为：%d\n",locate,length(head));
	//printList(head);


	///*第4个测试用例：删除位置-1的元素*/
	//locate = -1;
	//deleteElem(&head,&tail,locate,&e);
	//printf("删除位置%d处的元素后，长度为：%d\n",locate,length(head));
	//printList(head);

	///*第5个测试用例：删除位置length(hwad)+1的元素*/
	//locate = length(head)+1;
	//deleteElem(&head,&tail,locate,&e);
	//printf("删除位置%d处的元素后，长度为：%d\n",locate,length(head));
	//printList(head);

	///*第6个测试用例：删除位置length(hwad)+2的元素*/
	//locate = length(head)+2;
	//deleteElem(&head,&tail,locate,&e);
	//printf("删除位置%d处的元素后，长度为：%d\n",locate,length(head));
	//printList(head);

	///*第7个测试用例：删除位置0的元素*/
	//locate = 0;
	//deleteElem(&head,&tail,locate,&e);
	//printf("删除位置%d处的元素后，长度为：%d\n",locate,length(head));
	//printList(head);

	printf("清空链表\n");
	clearList(&head);
	listTraverse(head);

	printf("销毁链表\n");
	destroyList(&head);
	listTraverse(head);


	//srand((unsigned int)time(NULL));
	//for (int i = 0; i < 10; i++)
	//{
	//	/*createListF(&head,&tail,len);*/
	//	createListR(&head,&tail,len);
	//	printf_s("链表的长度：%d\n",length(head));
	//	printList(head);
	//	destroyList(&head);
	//}

	system("pause");
	return 0;
}



void printList(DuLinkedList head)
{
    DuLinkedList p = head;
    while(p)
    {
        printf("%d ",p?p->data:-1);
        p = p->next;
    }
    printf("\n\n");
}



int length(DuLinkedList head)
{
	DuLinkedList p = head;
	int count = 0;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}



void listTraverse(DuLinkedList head)
{
	DuLinkedList p = head;
	while (p)
	{
		visit(p);
		p = p->next;
	}
	printf_s("\n");
}



void visit(DuNode *p)
{
	printf_s("%d ",p->data);		
}



Status  createListF(DuLinkedList *head,DuLinkedList *tail,int len)
{
	DuLinkedList p = NULL;
	ElemType data;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
	{
		data = rand()%100+1;
		if (NULL == (*head))
		{
			*head = (DuLinkedList)malloc(sizeof(DuNode));
			if (!(*head))
			{
				return ERROR;
			}
			(*head)->data = data;
			(*head)->next = (*head)->prior = NULL;
			*tail = *head;
		}else
		{
			/*此处可传入函数指针，调用函数完成操作*/
			p = (DuLinkedList)malloc(sizeof(DuNode));
			if (!p)
			{
				return ERROR;
			}
			p->data = data;
			p->next = *head;
			(*head)->prior = p;
			*head = p;
		}
	}
	return OK;
}



Status  createListR(DuLinkedList *head,DuLinkedList *tail,int len)
{
	DuLinkedList p = NULL;
	ElemType data;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
	{
		data = rand()%100+1;
		if (NULL == (*head))
		{
			*head = (DuLinkedList)malloc(sizeof(DuNode));
			if (!(*head))
			{
				return ERROR;
			}
			(*head)->data = data;
			(*head)->next = (*head)->prior = NULL;
			*tail = *head;
		}else
		{
			p = (DuLinkedList)malloc(sizeof(DuNode));
			if (!p)
			{
				return ERROR;
			}
			p->data = data;
			p->next = NULL;
			p->prior = *tail;
			(*tail)->next = p;
			*tail = p;
		}
	}
	return OK;
}

Status  insertElem(DuLinkedList *head,DuLinkedList *tail,int locate,ElemType e)
{
	int count = 1;
	DuLinkedList p = *head;
	DuLinkedList pnew = NULL;
	if (locate < 1 || locate > length(*head)+1)
	{
		return ERROR;
	}
	if (1 == locate)
	{
		pnew = (DuLinkedList)malloc(sizeof(DuNode));
		if (!pnew)
		{
			return ERROR;
		}
		pnew->data = e;
		pnew->prior = NULL;
		pnew->next = *head;
		(*head)->prior = pnew;
		*head = pnew;
		return OK;
	}
	while (p && count < locate-1)
	{
		p = p->next;
		count++;
	}
	if (!p || count > locate-1)
	{
		/*if (1 == locate)
		{
			printf_s("count:%d  locate-1:%d  p->data:%d\n",count,locate-1,p->data);
		}*/
		return ERROR;
	}
	pnew = (DuLinkedList)malloc(sizeof(DuNode));
	if (!pnew)
	{
		return ERROR;
	}
	pnew->data = e;
	pnew->prior = p;
	pnew->next = p->next;
	if (p->next)
	{
		p->next->prior = pnew;
	}
	p->next = pnew;
	return OK;
}

Status  deleteElem(DuLinkedList *head,DuLinkedList *tail,int locate,ElemType *e)
{
	int count = 1;
	DuLinkedList p = *head;
	if (locate < 1 || locate > length(*head))
	{
		return ERROR;
	}
	if (1 == locate)
	{
		*e = (*head)->data;
		DuLinkedList q = *head;
		*head = (*head)->next;
		(*head)->prior = NULL;
		free(q);
		return OK;
	}
	while (p && count < locate-1)
	{
		p = p->next;
		count++;
	}
	if (!p || count > locate-1)
	{
		return ERROR;
	}
	DuLinkedList q = p->next;
	p->next = q->next;
	if (q->next)
	{
		q->next->prior = p;
	}free(q);
	q = NULL;
	return OK;
}


void clearList(DuLinkedList *head)
{
	DuLinkedList p = *head;
	destroyList(&(p->next));
	(*head)->next = NULL;
}



void destroyList(DuLinkedList *head)
{
	DuLinkedList p = *head,q = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	*head = NULL;
}