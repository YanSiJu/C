#include"MGraph.h"

void MakePath(MGraph g,bool p[],int i,int j);

void MakePath(MGraph g,bool p[],int i,int j)
{
	int begin = i;
	//�洢��Сֵ��������
	int minNum;
	//�洢���·��
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
		//����i��j֮��û��ͨ·
		if (INFINITY == min)
		{
			break;
		}
		printf_s("%s",g.vexs[minNum].name);
		if (begin != j)
		{
			printf_s("->");
		}
		//����·��������������[minNum]��
		p[minNum] = false;
		//�������Ķ��㸳ֵ��begin����Ϊ��ǰ�����������
		begin = minNum;
	}
}