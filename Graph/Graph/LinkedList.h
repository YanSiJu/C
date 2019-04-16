// ConsoleApplication.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"


typedef int ElementType[MAX_VERTEX_NUM];
typedef int Status;

typedef struct LNode
{
	//·�����飬��¼·���ϵĽ��
	ElementType  data;
	//��¼��ǰ·���ж������
	int size;
	struct LNode * next;
}LNode,* LinkedList;


/* �������� */
Status insertElem(LinkedList *head,int locate,ElementType e,int len);
Status deleteElem(LinkedList * head,int locate,ElementType e);
Status destroyList(LinkedList * head);
int length(LinkedList head);
void printList(LinkedList head);




//��ӡ����
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



//��Ԫ�ز���ָ��λ��----->����headΪNULL�����
Status insertElem(LinkedList *head,int locate,ElementType e,int len)
{
	int count = 1;
	LinkedList p = *head,q;
	//����Ϊ��
	if( NULL ==  p)
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
		if(NULL == pnew)
		{
			return -1;
		}
		for (int i = 0; i < len; i++)
		{
			pnew->data[i] = e[i];
		}
		pnew->size = len;
		if (NULL == *head)
		{
			pnew->next = NULL;
			*head = pnew;
		}else
		{

			pnew->next = *head;
			*head = pnew;
		}
		return 1;
	}
	while(p && count < locate-1)
	{
		p = p->next;
		count++;
	}
	if(NULL == p || count > locate-1)
	{
		return -1;
	}
	q = p->next;
	LinkedList pnew = (LinkedList)malloc(sizeof(LNode));
	if(NULL == pnew)
	{
		return -1;
	}
	for (int i = 0; i < len; i++)
	{
		pnew->data[i] = e[i];
	}
	pnew->size = len;
	p->next = pnew;
	pnew->next = q;
	return 1;
}


//ɾ��ָ��λ�õ�Ԫ��
Status deleteElem(LinkedList * head,int locate,ElementType e)
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
		int size = (*head)->size;
		e = (int *)malloc(sizeof(int)*size);
		for (int i = 0; i < size; i++)
		{
			e[i] = (*head)->data[i];
		}
		*head = (*head)->next;
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
	int size = q->size;
	e = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
	{
		e[i] =q->data[i];
	}
	p->next = q->next;
	free(q);
	return 1;
}


Status destroyList(LinkedList * head)
{
	LinkedList p = *head,q;
	while(p)
	{
		q = p->next;
		free(p->data);
		free(p);
		p = q;
	}
	*head = NULL;
	return 1;
}