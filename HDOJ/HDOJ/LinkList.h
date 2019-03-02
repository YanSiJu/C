// ConsoleApplication.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>



typedef int ElementType;
typedef int Status;

typedef struct LNode
{
     ElementType  data;
     struct LNode * next;
}LNode,* LinkedList;



        /* �������� */
Status insertElem(LinkedList * head,LinkedList * tail,ElementType e);
void printList(LinkedList head);

		
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


		/*�ڵ�����β������Ԫ��*/
Status insertElem(LinkedList * head,LinkedList * tail,ElementType e)
{
    LinkedList p = *head,pnew;
    if(!(*head))
    {
        *head = (LinkedList)malloc(sizeof(LNode));
        if(!(*head))
        {
            return -1;
        }
		(*head)->next = NULL;
        (*head)->data = e;
        *tail = *head;
        return 1;
    }
    pnew = (LinkedList)malloc(sizeof(LNode));
    if(!pnew)
    {
        return -1;
    }
    pnew->next = NULL;
    pnew->data = e;
    (*tail)->next = pnew;
    *tail = pnew;
    return 1;
}