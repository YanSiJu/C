//Sample Input
//5
//green
//red
//blue
//red
//red
//3
//pink
//orange
//pink
//0
// 
//
//Sample Output
//red
//pink


#include<string.h>
#include"ResultList.h"

void outPut(LinkedList head);
void countBalloon();

void countBalloon()
{
	//���ڴ洢������ɫ
	char **colors;
	//�������
	int balloonNum = 0;
	scanf_s("%d",&balloonNum);
	while (balloonNum > 0 && balloonNum <= 1000)
	{
		*colors = (char *)malloc(sizeof(char)*balloonNum);
		for (int i = 0; i < balloonNum; i++)
		{
			scanf_s("%s",colors[i]);
		}
		LinkedList head = NULL,tail = NULL;
		for (int i = 0; i < balloonNum; i++)
		{
			if (0 == i)
			{
				insertElem(&head,&tail,colors[0],1);
			}
			LinkedList p = head;
			while (NULL != p)
			{
				if (0 == strcmp(colors[i],p->color))
				{
					p->count++;
					break;
				}
				p = p->next;
			}
			if (NULL == p)
			{
				insertElem(&head,&tail,colors[i],1);
			}
			//outPut(head);
		}
	}
}


void outPut(LinkedList head)
{
	LinkedList p = head;
	//�洢���ִ�������������ɫ�������
	LinkedList q = (LinkedList)malloc(sizeof(LNode));
	q->color = "";
	q->count = 0;
	q->next = NULL;
	while (NULL != p)
	{
		if (p->count > q->count)
		{
			q = p;
		}
		p = p->next;
	}
	printf_s("%s\n",q->color);
}