#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef int ElementType;
typedef int Status;

typedef struct LNode
{
     ElementType  data;
     struct LNode * next;
}LNode,* LinkedList;


        /* �������� */
Status initList(LinkedList * head,LinkedList * tail);
        //β�巨
Status addElem(LinkedList * head,LinkedList * tail,ElementType e);
        //��Ԫ�ز���ָ��λ��
Status insertElem(LinkedList * head,LinkedList * tail,int locate,ElementType e);
        //ɾ��ָ��λ�õ�Ԫ��
Status deleteElem(LinkedList * head,LinkedList * tail,int locate,ElementType *e);
        //��������
Status destroyList(LinkedList * head,LinkedList * tail);
        //����������
int length(LinkedList head);


int main()
{


    system("title ˫������");
    LinkedList head,tail;
    int i = 0;
    for(i<10; i<10;i++)
    {
        addElem(&head,&tail,i+1);
    }
    printf("length:%d",length(head));


    //����Ԫ�ز���
    int locate = 5;
    ElementType e = 20;
    insertElem(&head,&tail,locate,e);
    locate = 7;
    e = 30;
    insertElem(&head,&tail,locate,e);
    printList(head);

    locate = 10;
    e = 70;
    insertElem(&head,&tail,locate,e);
    printList(head);


    locate = length(head);
    e = 70;
    insertElem(&head,&tail,locate,e);
    printList(head);


        //ɾ������
    ElementType *data;
    locate = 3;
    deleteElem(&head,&tail,locate,data);
    printList(head);

    locate = 1;
    deleteElem(&head,&tail,locate,data);
    printList(head);

    locate = length(head);
    deleteElem(&head,&tail,locate,data);
    printList(head);


    return 0;
}

void printList(LinkedList head)
{
    LinkedList p = head;
    while(p)
    {
        printf("%d  ",p->data);
        p = p->next;
    }
    printf("\n\n");
}

int length(LinkedList head)
{
    LinkedList p = head;
    int count = 1;
    while(p)
    {
        p = p->next;
        count++;
    }
    return count;
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



            //β�巨
Status addElem(LinkedList * head,LinkedList * tail,ElementType e)
{
        LinkedList p;
        if((*head) ==  NULL)
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


            //��Ԫ�ز���ָ��λ��
Status insertElem(LinkedList * head,LinkedList * tail,int locate,ElementType e)
{
        int count = 1;
        LinkedList p = *head,q;
        if(!p)
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
        p->next = pnew;
        pnew->next = q;
        return 1;
}


            //ɾ��ָ��λ�õ�Ԫ��
Status deleteElem(LinkedList * head,LinkedList * tail,int locate,ElementType *e)
{
        int count = 1;
        LinkedList p = *head,q;
        if(!p)
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
