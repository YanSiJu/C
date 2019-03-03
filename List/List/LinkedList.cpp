// ConsoleApplication.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef int ElementType;
typedef int Status;

typedef struct LNode
{
     ElementType  data;
     struct LNode * next;
}LNode,* LinkedList;


        /* 函数定义 */
Status insertElemR(LinkedList * head,LinkedList * tail,ElementType e);
Status insertElem(LinkedList * head,LinkedList * tail,int locate,ElementType e);
Status deleteElem(LinkedList * head,LinkedList * tail,int locate,ElementType *e);
Status destroyList(LinkedList * head,LinkedList * tail);
int length(LinkedList head);
Status  createListR(LinkedList *head,LinkedList *tail,int n);
Status  createListF(LinkedList *head,LinkedList *tail,int n);
void printList(LinkedList head);
int mergeList(LinkedList headA,LinkedList *headB,LinkedList  *headC);

//int  main()
//{
//	system("title 单链表操作");
//	
//	int len = 8;
//
//	printf("创建链表\n");
//	LinkedList head = NULL,tail = NULL;
//	createListF(&head,&tail,len);
//	printf_s("链表的长度：%d\n",length(head));
//	printList(head);
//
//	/*在链表尾部插入元素*/
//	ElementType  e = 22;
//	printf("在链表尾部插入元素%d\n",e);
//	insertElemR(&head,&tail,e);
//	printf_s("第1次插入元素后，链表的长度：%d\n",length(head));
//	printList(head);
//
//	/*在链表指定位置插入元素*/
//	int locate = length(head)+1;
//	e = 17;
//	printf("在链表位置%d插入元素%d\n",locate,e);
//	insertElem(&head,&tail,locate,e);
//	printf_s("第2次插入元素后，链表的长度：%d\n",length(head));
//	printList(head);
//
//	/*删除元素*/
//	/*第1个测试用例：删除位置3的元素*/
//	locate = 3;
//	printf("删除位置%d处的元素\n",locate);
//	deleteElem(&head,&tail,locate,&e);
//	printList(head);
//
//
//	/*第2个测试用例：删除头指针*/
//	locate = 1;
//	printf("删除位置%d处的元素\n",locate);
//	deleteElem(&head,&tail,locate,&e);
//	printList(head);
//
//	/*第3个测试用例：删除尾指针*/
//	locate = length(head);
//	printf("删除位置%d处的元素\n",locate);
//	deleteElem(&head,&tail,locate,&e);
//	printList(head);
//
//
//	/*第4个测试用例：删除位置-1的元素*/
//	locate = -1;
//	printf("删除位置%d处的元素\n",locate);
//	deleteElem(&head,&tail,locate,&e);
//	printList(head);
//
//	/*第5个测试用例：删除位置length(hwad)+1的元素*/
//	locate = length(head)+1;
//	printf("删除位置%d处的元素\n",locate);
//	deleteElem(&head,&tail,locate,&e);
//	printList(head);
//
//	/*第6个测试用例：删除位置length(hwad)+2的元素*/
//	locate = length(head)+2;
//	printf("删除位置%d处的元素\n",locate);
//	deleteElem(&head,&tail,locate,&e);
//	printList(head);
//
//	printf("销毁链表\n");
//	destroyList(&head,&tail);
//	printList(head);
//
//	printf("创建链表A\n");
//	LinkedList headA = NULL,tailA = NULL;
//	createListR(&headA,&tailA,len);
//	printList(headA);
//
//	LinkedList headB = NULL,tailB = NULL;
//	printf("创建链表B\n");
//	createListR(&headB,&tailB,len);
//	printList(headB);
//
//	LinkedList headC = NULL;
//	printf("合并链表A和B\n");
//	mergeList(headA,&headB,&headC);
//	printList(headC);
//
//	system("pause");
//	return 0;
//}



			//打印链表
void printList(LinkedList head)
{
    LinkedList p = head;
    while(p)
    {
        printf("%d ",p?p->data:-1);
        p = p->next;
    }
    printf("\n\n");
}

int length(LinkedList head)
{
    LinkedList p = head;
    int count = 0;
    while(p)
    {
        p = p->next;
        count++;
    }
    return count;
}


int mergeList(LinkedList headA,LinkedList *headB,LinkedList  *headC)
{
	LinkedList a = headA;
	LinkedList b = *headB;
	*headC = (LinkedList)malloc(sizeof(	LNode));
	if (!(*headC))
	{
		return -1;
	}
	(*headC)->next = NULL;
	//(*headC)->data = headA->data < (*headB)->data ?headA->data:(*headB)->data;
	if (a->data <= b->data)
	{
		(*headC)->data = a->data;
		LinkedList p = a;
		a = a->next;
		free(p);
		p = NULL;
	}else
	{
		(*headC)->data = b->data;
		LinkedList p = b;
		b = b->next;
		free(p);
		p = NULL;
	}
	LinkedList pc = *headC;
	while (a && b)
	{
		if (a->data <= b->data)
		{
			pc->next = a;
			pc = a;
			a = a->next;	
		}else
		{
			pc->next = b;
			pc = b;
			b = b->next;
		}
	}
	if (a)
	{
		pc->next = a;
	}
	if (b)
	{
		pc->next = b;
	}
	//free(*headB);
	return 1;
}

//Status initList(LinkedList * head,LinkedList * tail)
//{
//        *head = (LinkedList)malloc(sizeof(LNode));
//        if(!(*head)){
//            return -1;
//        }
//        (*head)->next = NULL;
//        (*head)->data = 132;
//        *tail = *head;
//        return 1;
//}



            //尾插法插入元素
Status insertElemR(LinkedList * head,LinkedList * tail,ElementType e)
{
        LinkedList p;
        if(NULL == (*head))
        {
            *head = (LinkedList)malloc(sizeof(LNode));
            if(!(*head))
            {
                return -1;
            }
            (*head)->data = e;
            (*head)->next = NULL;
            *tail = *head;
            return 1;
        }
        p = (LinkedList)malloc(sizeof(LNode));
        if(!p)
        {
            return -1;
        }
        p->data = e;
        p->next = NULL;
        (*tail)->next = p;
        *tail = p;
        return 1;
}


				//尾插法创建单链表
Status  createListR(LinkedList *head,LinkedList *tail,int n)
{
		//printf("请输入%d个数：",n);
		ElementType data = 0;
		LinkedList p = NULL;
		srand((unsigned int)time(NULL));
		for (int i = 0; i < n; i++)
		{
			data = rand()%100+1;
			/*scanf_s("%d",&data);*/
			if (NULL == (*head))
			{
				*head = (LinkedList)malloc(sizeof(LNode));
				(*head)->next = NULL;
				(*head)->data = data;
				*tail = *head;
			}else
			{
				p = (LinkedList)malloc(sizeof(LNode));
				if (!p)
				{
					return -1;
				}
				p->data = data;
				p->next = NULL;
				(*tail)->next = p;
				*tail = p;
			}
		}
		return 1;
}


  /*使用头插法创建单链表*/
Status  createListF(LinkedList *head,LinkedList *tail,int length)
{
		printf("请输入%d个数：",length);
		ElementType data = 0;
		LinkedList p = NULL;
		for (int i = 0; i < length; i++)
		{
			scanf_s("%d",&data);
			if ((*head) == NULL)
			{
				*head = (LinkedList)malloc(sizeof(LNode));
				(*head)->next = NULL;
				(*head)->data = data;
				*tail = *head;
			}else
			{
				p = (LinkedList)malloc(sizeof(LNode));
				if (!p)
				{
					return -1;
				}
				p->data = data;
				p->next = *head;
				*head = p;
			}
		}
		return 1;
}


            //将元素插在指定位置
Status insertElem(LinkedList * head,LinkedList * tail,int locate,ElementType e)
{
        int count = 1;
        LinkedList p = *head,q;
		//链表为空
        if(!p)
        {
            return -1;
        }
		//插入的位置非法
		if (locate < 1 || locate > length(*head)+1)
		{
			return -1;
		}
        //将结点插在表头
        if(locate == 1)
        {
            LinkedList pnew = (LinkedList)malloc(sizeof(LNode));
            if(!pnew)
            {
                return -1;
            }
			pnew->data = e;
            pnew->next = *head;
            *head = pnew;
            return 1;
        }
        while(p && count < locate-1)
        {
            p = p->next;
            count++;
        }
        if(!(p) || count > locate-1)
        {
            return -1;
        }
        q = p->next;
        LinkedList pnew = (LinkedList)malloc(sizeof(LNode));
        if(!pnew)
        {
            return -1;
        }
		pnew->data = e;
        p->next = pnew;
        pnew->next = q;
        return 1;
}


            //删除指定位置的元素
Status deleteElem(LinkedList * head,LinkedList * tail,int locate,ElementType *e)
{
        int count = 1;
        LinkedList p = *head,q;
		/*链表为空*/
        if(!p)
        {
            return -1;
        }
		/*删除的位置非法*/
		if (locate < 1 || locate > length(*head))
		{
			return -1;
		}
        //删除头结点
        if(locate == 1)
        {
            *head = (*head)->next;
            *e = (*head)->data;
            free(p);
            return 1;
        }
        while(p->next &&  count < locate-1)
        {
            p = p->next;
            count++;
        }
        if(!(p->next)  ||  count > locate-1)
        {
            return -1;
        }
        q = p->next;
        p->next = q->next;
        *e = q->data;
        free(q);
        return 1;
}


Status destroyList(LinkedList * head,LinkedList * tail)
{
    LinkedList p = *head,q;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    *head = *tail = NULL;
    return 1;
}
