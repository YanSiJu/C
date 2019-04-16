#include"MGraph.h"
#include"LinkedList.h"
#include"Queue.h"
#define Graph MGraph




void getPaths(Graph g,int src,int dest,LinkedList *list);
void DFS(Graph g,int v);
//访问标志数组
bool visited[MAX_VERTEX_NUM];
//用于遍历时存储顶点
LinkQueue q;
//用于存储所有的路径
LinkedList head = NULL;
//存储路径数
int pathNum = 0;
int start = 0;
int end = 0;

//深度优先遍历图G，对每个顶点调用函数visit()一次且仅一次
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
		//初始化访问标志数组
		visited[i] = false;
	}
	for (int v = 0; v < g.vexnum; v++)
	{
		//顶点v尚未被访问
		if (!visited[v])
		{
			enQueue(&q,v);
			//对尚未被访问的顶点v调用DFS()
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
			//存储当前队列中元素，并返回上一层
			path[size-1] = end;
			int count = size-1;
			QNode *p = q.front->next;
			while (p)
			{
				path[--size] = p->data;
				p = p->next;
			}
			//将顶点存储到path数组中
			insertElem(&head,++pathNum,path,size);
			return;
		}
		//邻接顶点w尚未被访问
		if (!visited[w])
		{
			enQueue(&q,w);
			////对尚未被访问的顶点w调用DFS()
			DFS(g,w);
		}
	}
	deQueue(&q,NULL);
}

