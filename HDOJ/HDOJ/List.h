#include<stdio.h>
#include<stdlib.h>


typedef int ElementType;
typedef int Status;

typedef struct LNode
{
     ElementType  a;
	 ElementType  b;
     struct LNode * next;
}LNode,* LinkedList;



        /* 函数定义 */
Status insertElem(LinkedList * head,LinkedList * tail,ElementType a,ElementType  b);
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
Status insertElem(LinkedList * head,LinkedList * tail,ElementType a,ElementType  b)
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
        (*head)->a = a;
		(*head)->b = b;
        *tail = *head;
        return 1;
    }
    pnew = (LinkedList)malloc(sizeof(LNode));
    if(!pnew)
    {
        return -1;
    }
    pnew->next = NULL;
    (*head)->a = a;
	(*head)->b = b;
    (*tail)->next = pnew;
    *tail = pnew;
    return 1;
}