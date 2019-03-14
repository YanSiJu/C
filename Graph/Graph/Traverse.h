#include"ALGraph.h"
//#include"MGraph.h"
#include"Queue.h"
#define Graph ALGraph


void DFSTraverse(Graph g,Status(* visit)(VertexType));
void DFS(Graph g,int v);
void BFSTraverse(Graph g,Status(* visit)(VertexType));
//访问标志数组
bool visited[MAX_VERTEX_NUM];
//访问函数变量
Status (* visitFunc)(VertexType);



void DFSTraverse(Graph g,Status(* visit)(VertexType))
{
	visitFunc = visit;
	for (int i = 0; i < g.vexnum; i++)
	{
		visited[i] = false;
	}
	for (int j = 0; j < g.vexnum; j++)
	{
		if (!visited[j])
		{
			DFS(g,j);
		}
	}
}



void DFS(Graph g,int v)
{
	visited[v] = true;
	visitFunc(getVex(g,v));
	for (int w = firstAdjvex(g,v);w >= 0;w = nextAdjvex(g,v,w))
	{
		if (!visited[w])
		{
			DFS(g,w);
		}
	}
}



void BFSTraverse(Graph g,Status(* visit)(VertexType))
{
	int u,v,w;
	LinkQueue q;
	initQueue(&q);
	for (int i = 0; i < g.vexnum; i++)
	{
		visited[i] = false;
	}
	for (v = 0; v < g.vexnum; v++)
	{
		if (!visited[v])
		{
			visit(getVex(g,v));
			visited[v] = true;
			enQueue(&q,v);
			while (!queueEmpty(q))
			{
				deQueue(&q,&u);
				for (w = firstAdjvex(g,u);w>=0;w = nextAdjvex(g,u,w))
				{
					if (!visited[w])
					{
						visit(getVex(g,w));
						visited[w] = true;
						enQueue(&q,w);
					}
				}
			}
		}
	}
}