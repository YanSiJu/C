#include "stdafx.h"
#include"ShortestPathDIJ.h"
#include"MakePath.h"


int _tmain(int argc, _TCHAR* argv[])
{
	MGraph g;
	//二维数组，路径矩阵
	PathMatrix p;
	//一维数组，最短距离表
	ShortPathTable d;
	bool *path;

	int k = 0;
	/*createFromeFile(g,".txt",0);*/
	path = (bool *)malloc(g.vexnum * sizeof(bool));
	shortestPathDIJ(g,k,p,d);
	printf_s("最短路径数组p[i][j]：\n");
	for (int i = 0; i < g.vexnum; i++)
	{
		for (int j = 0; j < g.vexnum; j++)
		{
			printf_s("%d  ",p[i][j]);
		}
		printf_s("\n");
	}

	printf_s("%s到各顶点的最短路径长度和依次经过的顶点:\n",g.vexs[k].name);
	for (int i = 0; i < g.vexnum; i++)
	{
		if (i != k && d[i] < INFINITY)
		{
			printf_s("%s--->%s:%d",g.vexs[k].name,g.vexs[i].name,d[i]);
			printf_s("%s--->",g.vexs[k].name);
			for (int j = 0; j < g.vexnum; j++)
			{
				path[j] = p[i][j];
			}
			MakePath(g,path,k,i);
		}
	}
}