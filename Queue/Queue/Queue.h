#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1

typedef int QElemType;
typedef int Status;

typedef struct  QNode
{
	QElemType data;
	struct QNode *next;
}QNode;

typedef struct LinkQueue
{
	QNode *front;
	QNode *rear;
}LinkQueue;



Status initQueue(LinkQueue *q);
void clearQueue(LinkQueue *q);
void destroyQueue(LinkQueue *q);
int queueLength(LinkQueue q);
Status queueEmpty(LinkQueue q);
Status getHead(LinkQueue q,QElemType *e);
Status deQueue(LinkQueue *q,QElemType *e);
Status enQueue(LinkQueue *q,QElemType e);
void queueTraverse(LinkQueue q);
void visit(QNode qNode);


void queueTraverse(LinkQueue q)
{
	QNode *p = q.front->next;
	while (p)
	{
		visit(*p);
		p = p->next;
	}
	printf_s("\n");
}



void visit(QNode q)
{
	printf_s("%d  ",q.data);
}



Status initQueue(LinkQueue *q)
{
	(*q).front = (*q).rear = (QNode *)malloc(sizeof(QNode));
	if (!(*q).front)
	{
		return ERROR;
	}
	(*q).front->next = NULL;
	return OK;
}



void clearQueue(LinkQueue *q)
{
	QNode *p = (*q).front?(*q).front->next:NULL;
	QNode *node = NULL;
	while (p)
	{
		node = p;
		p = p->next;
		free(node);
	}
	(*q).front->next = NULL;
	(*q).rear = (*q).front;
}



void destroyQueue(LinkQueue *q)
{
	QNode *p = (*q).front?(*q).front->next:NULL;
	QNode *node = NULL;
	while (p)
	{
		node = p;
		p = p->next;
		free(node);
	}
	(*q).front->next = NULL;
	(*q).rear = (*q).front = NULL;
}




int queueLength(LinkQueue q)
{
	QNode *p = q.front?q.front->next:NULL;
	int count = 0;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}



Status queueEmpty(LinkQueue q)
{
	return q.front == q.rear;
}



Status getHead(LinkQueue q,QElemType *e)
{
	if (q.front && q.front->next)
	{
		*e = q.front->next->data;
		return OK;
	}
	return ERROR;
}


Status deQueue(LinkQueue *q,QElemType *e)
{
	if (!queueEmpty(*q))
	{
		QNode *p = (*q).front->next;
		*e = p->data;
		(*q).front->next = p->next;
		if (p == (*q).rear)
		{
			(*q).rear = (*q).front;
		}
		free(p);
		return OK;
	}
	return ERROR;
}



Status enQueue(LinkQueue *q,QElemType e)
{
	if (!(*q).front || !(*q).rear)
	{
		return ERROR;
	}
	QNode *pnew = (QNode *)malloc(sizeof(QNode));
	if (!pnew)
	{
		return ERROR;
	}
	pnew->data = e;
	pnew->next = NULL;
	(*q).rear->next = pnew;
	(*q).rear = pnew;
	return OK;
}


