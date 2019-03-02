#include<stdio.h>
#include<stdlib.h>
//#include"result.h"



//typedef Result ElementType;
typedef int Status;

typedef struct LNode
{
     char *color;
	 int count;
     struct LNode * next;
}LNode,* LinkedList;



        /* 函数定义 */
Status insertElem(LinkedList * head,LinkedList * tail,char *color,int count);
void printList(LinkedList head);

		
void printList(LinkedList head)
{
    LinkedList p = head;
    while(p)
    {
        //printf("%d ",p?p->data:-1);
        p = p->next;
    }
    printf("\n\n");
}


		/*在单链表尾部插入元素*/
Status insertElem(LinkedList * head,LinkedList * tail,char *color,int count)
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
        (*head)->color = color;
		(*head)->count = count;
        *tail = *head;
        return 1;
    }
    pnew = (LinkedList)malloc(sizeof(LNode));
    if(!pnew)
    {
        return -1;
    }
    pnew->next = NULL;
    (*head)->color = color;
	(*head)->count = count;
    (*tail)->next = pnew;
    *tail = pnew;
    return 1;
}