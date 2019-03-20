#include"MGraph.h"

//路径矩阵
typedef bool PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//最短距离矩阵
typedef VRType DistanceMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

void shortestPathFloyd(MGraph g,PathMatrix p,DistanceMatrix D);


//用Floyd算法求有向网中各对顶点v和w之间的最短路径p[v][w][]及其带权路径长度D[v][w]
//若p[v][w][u]为true，则u是从v到w当前求得最短路径上的顶点
void shortestPathFloyd(MGraph g,PathMatrix p,DistanceMatrix D)
{
	//各对顶点之间初始化已知路径及距离
	for (int v = 0;v < g.vexnum; v++)
	{
		//初始化距离
		for (int w = 0;w < g.vexnum; w++)
		{
			//顶点v到顶点w的直接距离
			D[v][w] = g.arcs[v][w].adj;
			//初始化路径矩阵
			for (int u = 0; u < g.vexnum; u++)
			{
				p[v][w][u] = false;
			}
			//从v到w有直接路径：v->w
			if (D[v][w] < INFINITY)
			{
				//由v到w的路径经过v和w两点
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
				//从v经u到w的一条路径更短
				if (v != w && v != u && w != u &&
					D[v][u]<INFINITY &&  D[u][w]< INFINITY && D[v][u]+D[u][w] < D[v][w])
				{
					//更新最短距离
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


