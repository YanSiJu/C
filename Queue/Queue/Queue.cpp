// Queue.cpp : 定义控制台应用程序的入口点。
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
	printf_s("初始化队列后，front:%p   rear:%p \n 队列空否？(0否 1是):%d   队列的长度：%d\n",q.front,q.rear,queueEmpty(q),queueLength(q));
	for (int i = 0; i < N; i++)
	{
		enQueue(&q,rand()%100+1);
	}
	queueTraverse(q);
	printf_s("入队后，front:%p   rear:%p  队列空否？(0否 1是):%d   队列的长度：%d\n",q.front,q.rear,queueEmpty(q),queueLength(q));
	
	QElemType e;
	getHead(q,&e);
	printf_s("队头元素：%d\n",e);
	deQueue(&q,&e);
	printf_s("出队后，队头元素：%d\n",e);
	queueTraverse(q);
	clearQueue(&q);
	printf_s("清空队列后，front:%p   rear:%p   队列空否？(0否 1是):%d   队列的长度：%d\n",q.front,q.rear,queueEmpty(q),queueLength(q));
	destroyQueue(&q);
	printf_s("销毁队列后，front:%p   rear:%p   队列空否？(0否 1是):%d   队列的长度：%d\n",q.front,q.rear,queueEmpty(q),queueLength(q));


	printf_s("\n重新初始化队列......\n");
	initQueue(&q);
	for (int i = 0; i < N; i++)
	{
		enQueue(&q,rand()%100+1);
	}
	for (int i = 0; i < N; i++)
	{
		deQueue(&q,&e);
	}
	printf_s("遍历队列元素......");
	queueTraverse(q);

	system("pause");
	return 0;
}

