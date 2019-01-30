#include"MGraph.h"

void MakePath(MGraph g,bool p[],int i,int j);

void MakePath(MGraph g,bool p[],int i,int j)
{
	int begin = i;
	//存储较小值顶点的序号
	int minNum;
	//存储最短路径
	VRType min;
	while (begin != j)
	{
		min = INFINITY;
		for (int k = 0; k < g.vexnum; k++)
		{
			if (g.arcs[begin][k].adj < min && p[k] )
			{
				minNum = k;
				min = g.arcs[begin][k].adj;
			}
		}
		//顶点i到j之间没有通路
		if (INFINITY == min)
		{
			break;
		}
		printf_s("%s",g.vexs[minNum].name);
		if (begin != j)
		{
			printf_s("->");
		}
		//缩短路径（不再往回找[minNum]）
		p[minNum] = false;
		//将经过的顶点赋值给begin，作为当前顶点继续查找
		begin = minNum;
	}
}