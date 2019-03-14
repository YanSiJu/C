#include"ALGraph.h"
//#include"MGraph.h"
#include"Queue.h"
#define Graph ALGraph


void DFSTraverse(Graph g,void (* visit)(VertexType));
void DFS(Graph g,int v);
void BFSTraverse(Graph g,void (* visit)(VertexType));
//���ʱ�־����
bool visited[MAX_VERTEX_NUM];
//���ʺ�������
void (* visitFunc)(VertexType);


//������ȱ���ͼG����ÿ��������ú���visit()һ���ҽ�һ��
void DFSTraverse(Graph g,void (* visit)(VertexType))
{
	visitFunc = visit;
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
			//����δ�����ʵĶ���v����DFS()
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
		//�ڽӶ���w��δ������
		if (!visited[w])
		{
			////����δ�����ʵĶ���w����DFS()
			DFS(g,w);
		}
	}
}


//������ȷǵݹ����ͼG����ÿ��������ú���visit()һ���ҽ�һ��
void BFSTraverse(Graph g,void (* visit)(VertexType))
{
	int u;
	LinkQueue q;
	//��ʼ����������Q
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
			//���÷��ʱ�־Ϊtrue
			visited[v] = true;
			//���ʶ���v
			visit(getVex(g,v));
			//v�����Q
			enQueue(&q,v);
			//����Q�ǿ�
			while (!queueEmpty(q))
			{
				//��ͷԪ�س��Ӳ���Ϊu
				deQueue(&q,&u);
				//��u�ĵ�һ���ڽӶ���w��
				for (int w = firstAdjvex(g,u);w>=0;w = nextAdjvex(g,u,w))
				{
					//wΪu����δ���ʵĶ���w
					if (!visited[w])
					{
						//���ʱ�־��Ϊtrue
						visited[w] = true;
						//���ʶ���w
						visit(getVex(g,w));
						//w�����q
						enQueue(&q,w);
					}
				}
			}
		}
	}
}