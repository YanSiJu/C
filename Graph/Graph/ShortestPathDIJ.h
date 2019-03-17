#include"MGraph.h"


//路径矩阵，二维数组
typedef bool PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//最短距离表 一维数组
typedef VRType ShortPathTable[MAX_VERTEX_NUM];


void shortestPathDIJ(MGraph g,int v,PathMatrix p,ShortPathTable d);



void shortestPathDIJ(MGraph g,int u,PathMatrix p,ShortPathTable D)
{
	VRType min;
	//辅助矩阵
	bool final[MAX_VERTEX_NUM];
	for (int v = 0; v < g.vexnum; v++)
	{
		//D[]存放u到v的最短距离，初值为u到v的直接距离
		D[v] = g.arcs[u][v].adj;
		for (int w = 0; w < g.vexnum; w++)
		{
			//设p[][]初值为false，没有路径
			p[v][w] = false;
		}
		//u到v有直接路径
		if (D[v] < INFINITY)
		{
			p[v][u] = p[v][v] = true;
		}
	}
	int v;
	//u到u距离为0
	D[u] = 0;
	//将u并入s集
	final[u] = true;
	//主循环：对于其余g.vexnum-1个顶点，每次求得u到某个顶点v的最短距离，并将顶点v并入S集
	for (int i = 1; i < g.vexnum; i++)
	{
		min = INFINITY;
		for (int w = 0; w < g.vexnum; w++)
		{
			if (!final[w] && D[w] < min)
			{
				v = w;
				min = D[w];
			}
		}
		//将v并入s集
		final[v] = true;
		//根据新并入的顶点，更新不在s集的顶点到u的距离和路径数组
		for (int w = 0; w < g.vexnum; w++)
		{
			//w不属于s集，且u->v->w的距离 < 目前u->...w的距离
			//min：从u到v的距离
			if (!final[w] && g.arcs[v][w].adj < INFINITY 
				&& min < INFINITY && g.arcs[v][w].adj + min < D[w])
			{
				D[w] = g.arcs[v][w].adj + min;
				//更新从u到w的路径
				for (int j = 0; j < g.vexnum; j++)
				{
					//修改p[w]，从u到w经过的顶点包括从u到v经过的所有顶点加上w
					p[w][j] = p[v][j];
				}
				p[w][w] = true;
			}
		}
	}

}