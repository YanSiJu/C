#include"ALGraph.h"
//#include"MGraph.h"
#include"Queue.h"
#define Graph ALGraph


void DFSTraverse(Graph g,void (* visit)(VertexType));
void DFS(Graph g,int v);
void BFSTraverse(Graph g,void (* visit)(VertexType));
//访问标志数组
bool visited[MAX_VERTEX_NUM];
//访问函数变量
void (* visitFunc)(VertexType);


//深度优先遍历图G，对每个顶点调用函数visit()一次且仅一次
void DFSTraverse(Graph g,void (* visit)(VertexType))
{
	visitFunc = visit;
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
			//对尚未被访问的顶点v调用DFS()
			DFS(g,v);
		}
	}
	printf_s("\n");
}



void DFS(Graph g,int v)
{
	visited[v] = true;
	visitFunc(getVex(g,v));
	for (int w = firstAdjvex(g,v);w >= 0;w = nextAdjvex(g,v,w))
	{
		//邻接顶点w尚未被访问
		if (!visited[w])
		{
			////对尚未被访问的顶点w调用DFS()
			DFS(g,w);
		}
	}
}


//广度优先非递归遍历图G，对每个顶点调用函数visit()一次且仅一次
void BFSTraverse(Graph g,void (* visit)(VertexType))
{
	int u;
	LinkQueue q;
	//初始化辅助队列Q
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
			//设置访问标志为true
			visited[v] = true;
			//访问顶点v
			visit(getVex(g,v));
			//v入队列Q
			enQueue(&q,v);
			//队列Q非空
			while (!queueEmpty(q))
			{
				//队头元素出队并置为u
				deQueue(&q,&u);
				//从u的第一个邻接顶点w起
				for (int w = firstAdjvex(g,u);w>=0;w = nextAdjvex(g,u,w))
				{
					//w为u的尚未访问的顶点w
					if (!visited[w])
					{
						//访问标志置为true
						visited[w] = true;
						//访问顶点w
						visit(getVex(g,w));
						//w入队列q
						enQueue(&q,w);
					}
				}
			}
		}
	}
}