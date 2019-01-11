#include<stdio.h>
#include<stdlib.h>

typedef int Status;
typedef int ElementType;

typedef struct DuNode
{
        ElementType data;
        struct DuNode *pre;
        struct DuNode *next;
}DuNode,* DuLinkedList;


        //β�巨
Status addElem(DuLinkedList * head,DuLinkedList * tail,ElementType e);
        //��Ԫ�ز���ָ��λ��
Status insertElem(DuLinkedList * head,DuLinkedList * tail,int locate,ElementType e);
        //ɾ��ָ��λ�õ�Ԫ��
Status deleteElem(DuLinkedList * head,DuLinkedList * tail,int locate,ElementType *e);
        //��������
Status destroyList(DuLinkedList * head,DuLinkedList * tail);


int main()
{

    system("title ˫������");
    DuLinkedList head,tail;
    for(int i=0; i<10; i++)
    {
        addElem(&head,&tail,i+1);
    }
    return 0;
}


Status addElem(DuLinkedList * head,DuLinkedList * tail,ElementType e)
{
    DuLinkedList p = *head,pnew;
    if(!(*head))
    {
        *head = (DuLinkedList)malloc(sizeof(DuNode));
        if(!(*head))
        {
            return -1;
        }
        (*head)->next = (*head)->pre = NULL;
        (*head)->data = e;
        *tail = *head;
        return 1;
    }
    pnew = (DuLinkedList)malloc(sizeof(DuNode));
    if(!pnew)
    {
        return -1;
    }
    pnew->next = NULL;
    pnew->pre = *tail;
    pnew->data = e;
    (*tail)->next = pnew;
    *tail = pnew;
    return 1;
}



Status insertElem(DuLinkedList * head,DuLinkedList * tail,int locate,ElementType e)
{
        int count = 1;
        DuLinkedList p = *head,q;
        if(!p)
        {
            return -1;
        }
        //�������ڱ�ͷ
        if(locate == 1)
        {
            DuLinkedList pnew = (LinkedList)malloc(sizeof(LNode));
            if(!pnew)
            {
                return -1;
            }
            pnew->next = *head;
            pnew->pre = NULL;
            (*head)->pre = pnew;
            *head = pnew;
            return 1;
        }
        while(p->next && count < locate-1)
        {
            p = p->next;
            count++;
        }
        if(!(p->next) || count > locate-1)
        {
            return -1;
        }
        q = p->next;
        DuLinkedList pnew = (LinkedList)malloc(sizeof(LNode));
        if(!pnew)
        {
            return -1;
        }
        p->next = pnew;
        pnew->pre = p;
        pnew->next = q;
        q->pre = pnew;
        return 1;
}


Status deleteElem(DuLinkedList * head,DuLinkedList * tail,int locate,ElementType *e)
{

    int count = 1;
        DuLinkedList p = *head,q;
        if(!p)
        {
            return -1;
        }
        //ɾ��ͷ���
        if(locate == 1)
        {
            *head = (*head)->next;
            (*head)->pre = NULL;
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
        q->next->pre = p;
        *e = q->data;
        free(q);
        return 1;
}


Status destroyList(LinkedList * head,LinkedList * tail)
{

    return 1;
}
