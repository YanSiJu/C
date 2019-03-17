#include"MGraph.h"

//·������
typedef bool PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//��̾������
typedef VRType DistanceMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

void shortestPathFloyd(MGraph g,PathMatrix p,DistanceMatrix D);


void shortestPathFloyd(MGraph g,PathMatrix p,DistanceMatrix D)
{
	/*int u,v,w;*/
	//���Զ���֮���ʼ����֪·��������
	for (int v = 0;v < g.vexnum; v++)
	{
		//��ʼ������
		int w = 0;
		for (; w < g.vexnum; w++)
		{
			D[v][w] = g.arcs[v][w].adj;
			//��ʼ��·������
			for (int u = 0; u < g.vexnum; u++)
			{
				p[v][w][u] = false;
			}
			//��v��w��ֱ��·����v->w
			if (D[v][w] < INFINITY)
			{
				p[v][w][v] = p[v][w][w] = true;
			}
		}
	}

	for (int u = 0; u < g.vexnum; u++)
	{
		for (int v = 0; v < g.vexnum; v++)
		{
			for (int w = 0; w < g.vexnum; w++)
			{
				//��v��u��w��·������
				if (v != w && v != u && w != u &&
					D[v][u]<INFINITY &&  D[u][w]< INFINITY && D[v][u]+D[u][w] < D[v][w])
				{
					//�������·��
					D[v][w] = D[v][u]+D[u][w];
					//��v��w��·��������v��u��u��w������·��
					for (int i = 0; i < g.vexnum; i++)
					{
						p[v][w][i] = p[v][u][i] || p[u][w][i];
					}
				}
			}
		}
	}
}


