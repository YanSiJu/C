// Queue.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Queue.h"
#define N 10


int _tmain(int argc, _TCHAR* argv[])
{
	LinkQueue q;
	q.front = q.rear = NULL;
	srand((unsigned int)time(NULL));
	initQueue(&q);
	printf_s("��ʼ�����к�front:%p   rear:%p \n ���пշ�(0�� 1��):%d   ���еĳ��ȣ�%d\n",q.front,q.rear,queueEmpty(q),queueLength(q));
	for (int i = 0; i < N; i++)
	{
		enQueue(&q,rand()%100+1);
	}
	queueTraverse(q);
	printf_s("��Ӻ�front:%p   rear:%p  ���пշ�(0�� 1��):%d   ���еĳ��ȣ�%d\n",q.front,q.rear,queueEmpty(q),queueLength(q));
	
	QElemType e;
	getHead(q,&e);
	printf_s("��ͷԪ�أ�%d\n",e);
	deQueue(&q,&e);
	printf_s("���Ӻ󣬶�ͷԪ�أ�%d\n",e);
	queueTraverse(q);
	clearQueue(&q);
	printf_s("��ն��к�front:%p   rear:%p   ���пշ�(0�� 1��):%d   ���еĳ��ȣ�%d\n",q.front,q.rear,queueEmpty(q),queueLength(q));
	destroyQueue(&q);
	printf_s("���ٶ��к�front:%p   rear:%p   ���пշ�(0�� 1��):%d   ���еĳ��ȣ�%d\n",q.front,q.rear,queueEmpty(q),queueLength(q));


	printf_s("\n���³�ʼ������......\n");
	initQueue(&q);
	for (int i = 0; i < N; i++)
	{
		enQueue(&q,rand()%100+1);
	}
	for (int i = 0; i < N; i++)
	{
		deQueue(&q,&e);
	}
	printf_s("��������Ԫ��......");
	queueTraverse(q);

	system("pause");
	return 0;
}

