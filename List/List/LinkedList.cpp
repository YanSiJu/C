// ConsoleApplication.cpp : �������̨Ӧ�ó������ڵ㡣
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


        /* �������� */
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
//	system("title ���������");
//	
//	int len = 8;
//
//	printf("��������\n");
//	LinkedList head = NULL,tail = NULL;
//	createListF(&head,&tail,len);
//	printf_s("����ĳ��ȣ�%d\n",length(head));
//	printList(head);
//
//	/*������β������Ԫ��*/
//	ElementType  e = 22;
//	printf("������β������Ԫ��%d\n",e);
//	insertElemR(&head,&tail,e);
//	printf_s("��1�β���Ԫ�غ�����ĳ��ȣ�%d\n",length(head));
//	printList(head);
//
//	/*������ָ��λ�ò���Ԫ��*/
//	int locate = length(head)+1;
//	e = 17;
//	printf("������λ��%d����Ԫ��%d\n",locate,e);
//	insertElem(&head,&tail,locate,e);
//	printf_s("��2�β���Ԫ�غ�����ĳ��ȣ�%d\n",length(head));
//	printList(head);
//
//	/*ɾ��Ԫ��*/
//	/*��1������������ɾ��λ��3��Ԫ��*/
//	locate = 3;
//	printf("ɾ��λ��%d����Ԫ��\n",locate);
//	deleteElem(&head,&tail,locate,&e);
//	printList(head);
//
//
//	/*��2������������ɾ��ͷָ��*/
//	locate = 1;
//	printf("ɾ��λ��%d����Ԫ��\n",locate);
//	deleteElem(&head,&tail,locate,&e);
//	printList(head);
//
//	/*��3������������ɾ��βָ��*/
//	locate = length(head);
//	printf("ɾ��λ��%d����Ԫ��\n",locate);
//	deleteElem(&head,&tail,locate,&e);
//	printList(head);
//
//
//	/*��4������������ɾ��λ��-1��Ԫ��*/
//	locate = -1;
//	printf("ɾ��λ��%d����Ԫ��\n",locate);
//	deleteElem(&head,&tail,locate,&e);
//	printList(head);
//
//	/*��5������������ɾ��λ��length(hwad)+1��Ԫ��*/
//	locate = length(head)+1;
//	printf("ɾ��λ��%d����Ԫ��\n",locate);
//	deleteElem(&head,&tail,locate,&e);
//	printList(head);
//
//	/*��6������������ɾ��λ��length(hwad)+2��Ԫ��*/
//	locate = length(head)+2;
//	printf("ɾ��λ��%d����Ԫ��\n",locate);
//	deleteElem(&head,&tail,locate,&e);
//	printList(head);
//
//	printf("��������\n");
//	destroyList(&head,&tail);
//	printList(head);
//
//	printf("��������A\n");
//	LinkedList headA = NULL,tailA = NULL;
//	createListR(&headA,&tailA,len);
//	printList(headA);
//
//	LinkedList headB = NULL,tailB = NULL;
//	printf("��������B\n");
//	createListR(&headB,&tailB,len);
//	printList(headB);
//
//	LinkedList headC = NULL;
//	printf("�ϲ�����A��B\n");
//	mergeList(headA,&headB,&headC);
//	printList(headC);
//
//	system("pause");
//	return 0;
//}



			//��ӡ����
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



            //β�巨����Ԫ��
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


				//β�巨����������
Status  createListR(LinkedList *head,LinkedList *tail,int n)
{
		//printf("������%d������",n);
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


  /*ʹ��ͷ�巨����������*/
Status  createListF(LinkedList *head,LinkedList *tail,int length)
{
		printf("������%d������",length);
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


            //��Ԫ�ز���ָ��λ��
Status insertElem(LinkedList * head,LinkedList * tail,int locate,ElementType e)
{
        int count = 1;
        LinkedList p = *head,q;
		//����Ϊ��
        if(!p)
        {
            return -1;
        }
		//�����λ�÷Ƿ�
		if (locate < 1 || locate > length(*head)+1)
		{
			return -1;
		}
        //�������ڱ�ͷ
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


            //ɾ��ָ��λ�õ�Ԫ��
Status deleteElem(LinkedList * head,LinkedList * tail,int locate,ElementType *e)
{
        int count = 1;
        LinkedList p = *head,q;
		/*����Ϊ��*/
        if(!p)
        {
            return -1;
        }
		/*ɾ����λ�÷Ƿ�*/
		if (locate < 1 || locate > length(*head))
		{
			return -1;
		}
        //ɾ��ͷ���
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
