 #ifndef HEAD_H_ 
#define HEAD_H_

void MakePath(MGraph g,bool p[],int i,int j);

//求由图G的起点[i]到终点[j]的最短路径沿途所经过的顶点
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
				//较小值顶点序号赋给minNum
				minNum = k;
				min = g.arcs[begin][k].adj;
			}
		}
		//起点[i]到终点[j]之间没有通路
		if (INFINITY == min)
		{
			//跳出while循环
			break;
		}
		printf_s("%s",g.vexs[minNum].name);
		//minNum不是终点
		if (minNum != j)
		{
			printf_s("->");
		}
		//缩短路径（不再往回找[minNum]）
		p[minNum] = false;
		//将经过的顶点赋值给begin，作为当前顶点继续查找
		begin = minNum;
	}
	printf_s("\n");
}

#endif