#include "stdafx.h"
#include"ShortestPathDIJ.h"
#include"MakePath.h"


int _tmain(int argc, _TCHAR* argv[])
{
	MGraph g;
	//��ά���飬·������
	PathMatrix p;
	//һά���飬��̾����
	ShortPathTable d;
	bool *path;

	int k = 0;
	/*createFromeFile(g,".txt",0);*/
	path = (bool *)malloc(g.vexnum * sizeof(bool));
	shortestPathDIJ(g,k,p,d);
	printf_s("���·������p[i][j]��\n");
	for (int i = 0; i < g.vexnum; i++)
	{
		for (int j = 0; j < g.vexnum; j++)
		{
			printf_s("%d  ",p[i][j]);
		}
		printf_s("\n");
	}

	printf_s("%s������������·�����Ⱥ����ξ����Ķ���:\n",g.vexs[k].name);
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