#include"MGraph.h"

//路径矩阵
typedef bool PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//最短距离矩阵
typedef VRType DistanceMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

void shortestPathFloyd(MGraph g,PathMatrix p,DistanceMatrix D);


void shortestPathFloyd(MGraph g,PathMatrix p,DistanceMatrix D)
{
	/*int u,v,w;*/
	//各对顶点之间初始化已知路径及距离
	for (int v = 0;v < g.vexnum; v++)
	{
		//初始化距离
		int w = 0;
		for (; w < g.vexnum; w++)
		{
			D[v][w] = g.arcs[v][w].adj;
			//初始化路径矩阵
			for (int u = 0; u < g.vexnum; u++)
			{
				p[v][w][u] = false;
			}
			//从v到w有直接路径：v->w
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
				//从v经u到w的路径更短
				if (v != w && v != u && w != u &&
					D[v][u]<INFINITY &&  D[u][w]< INFINITY && D[v][u]+D[u][w] < D[v][w])
				{
					//更新最短路径
					D[v][w] = D[v][u]+D[u][w];
					//从v到w的路径经过从v到u和u到w的所有路径
					for (int i = 0; i < g.vexnum; i++)
					{
						p[v][w][i] = p[v][u][i] || p[u][w][i];
					}
				}
			}
		}
	}
}


