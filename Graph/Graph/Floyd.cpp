#include "stdafx.h"
#include"ShortestPathFloyd.h"
#include"MakePath.h"


int _tmain(int argc, _TCHAR* argv[])
{
	MGraph g;
	//��ά����
	PathMatrix p;
	//��ά����
	DistanceMatrix d;
	bool *path;
	/*createFromeFile(g,"1.txt",0);*/
	for (int i = 0; i < g.vexnum; i++)
	{
		g.arcs[i][i].adj = 0;
	}
	//���������G
	display(g);
	shortestPathFloyd(g,p,d);
	printf_s("d����\n");
	for (int i = 0; i < g.vexnum; i++)
	{
		for (int j = 0; j < g.vexnum; j++)
		{
			if (INFINITY == d[i][j])
			{
				printf_s("��");
			}else
			{
				printf_s("%4d",d[i][j]);
			}
		}
		printf_s("\n");
	}
	path = (bool *)malloc(g.vexnum*sizeof(bool));
	for (int i = 0; i < g.vexnum; i++)
	{
		for (int j = 0; j < g.vexnum; j++)
		{
			if (i != j)
			{
				printf_s("%s-->%s:p[%d][%d]=",g.vexs[i].name,g.vexs[j].name,i,j);
				for (int k = 0; k < g.vexnum; k++)
				{
					printf_s("%2d",p[i][j][k]);
					path[k] = p[i][j][k];
				}
				printf_s("��̾��� = %2d",d[i][j]);
				printf_s("�����Ķ��㣺");
				MakePath(g,path,i,j);
			}
		}
	}
}