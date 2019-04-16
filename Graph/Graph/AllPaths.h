#include"MGraph.h"
#include"LinkedList.h"
#include"Queue.h"
#define Graph MGraph




void getPaths(Graph g,int src,int dest,LinkedList *list);
void DFS(Graph g,int v);
//���ʱ�־����
bool visited[MAX_VERTEX_NUM];
//���ڱ���ʱ�洢����
LinkQueue q;
//���ڴ洢���е�·��
LinkedList head = NULL;
//�洢·����
int pathNum = 0;
int start = 0;
int end = 0;

//������ȱ���ͼG����ÿ��������ú���visit()һ���ҽ�һ��
void getPaths(Graph g,int src,int dest,LinkedList *list)
{
	if ((src < 0 || src >= g.vexnum) || (dest < 0 || dest >= g.vexnum))
	{
		return;
	}	
	head = NULL;
	start = src;
	end = dest;
	initQueue(&q);
	for (int i = 0; i < g.vexnum; i++)
	{
		//��ʼ�����ʱ�־����
		visited[i] = false;
	}
	for (int v = 0; v < g.vexnum; v++)
	{
		//����v��δ������
		if (!visited[v])
		{
			enQueue(&q,v);
			//����δ�����ʵĶ���v����DFS()
			DFS(g,v);
		}
	}
	*list = head;
	destroyQueue(&q);
	//destroyList(&head);
	pathNum = 0;
	start = 0;
	end = 0;
}



void DFS(Graph g,int v)
{
	
	visited[v] = true;
	for (int w = firstAdjvex(g,v);w >= 0;w = nextAdjvex(g,v,w))
	{
		if (w == end)
		{
			int size = queueLength(q);
			int *path = (int *)malloc(size);
			if (path == NULL)
			{
				return;
			}
			//�洢��ǰ������Ԫ�أ���������һ��
			path[size-1] = end;
			int count = size-1;
			QNode *p = q.front->next;
			while (p)
			{
				path[--size] = p->data;
				p = p->next;
			}
			//������洢��path������
			insertElem(&head,++pathNum,path,size);
			return;
		}
		//�ڽӶ���w��δ������
		if (!visited[w])
		{
			enQueue(&q,w);
			////����δ�����ʵĶ���w����DFS()
			DFS(g,w);
		}
	}
	deQueue(&q,NULL);
}

