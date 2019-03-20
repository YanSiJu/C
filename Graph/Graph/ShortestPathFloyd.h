#include"MGraph.h"

//·������
typedef bool PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//��̾������
typedef VRType DistanceMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

void shortestPathFloyd(MGraph g,PathMatrix p,DistanceMatrix D);


//��Floyd�㷨���������и��Զ���v��w֮������·��p[v][w][]�����Ȩ·������D[v][w]
//��p[v][w][u]Ϊtrue����u�Ǵ�v��w��ǰ������·���ϵĶ���
void shortestPathFloyd(MGraph g,PathMatrix p,DistanceMatrix D)
{
	//���Զ���֮���ʼ����֪·��������
	for (int v = 0;v < g.vexnum; v++)
	{
		//��ʼ������
		for (int w = 0;w < g.vexnum; w++)
		{
			//����v������w��ֱ�Ӿ���
			D[v][w] = g.arcs[v][w].adj;
			//��ʼ��·������
			for (int u = 0; u < g.vexnum; u++)
			{
				p[v][w][u] = false;
			}
			//��v��w��ֱ��·����v->w
			if (D[v][w] < INFINITY)
			{
				//��v��w��·������v��w����
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
				//��v��u��w��һ��·������
				if (v != w && v != u && w != u &&
					D[v][u]<INFINITY &&  D[u][w]< INFINITY && D[v][u]+D[u][w] < D[v][w])
				{
					//������̾���
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


