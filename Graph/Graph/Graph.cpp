// Graph.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"MGraph.h"
#define Graph MGraph
//#include"ALGraph.h"
//#define Graph ALGraph

void modify(int &n);
void pointmodify(int **p);


int _tmain(int argc, _TCHAR* argv[])
{
	//enum GraphKind{DG,DN,UDG,UDN};
	/*printf_s("%d  %d  %d  %d %d\n",DG,DN,UDG,UDN,errno);
	int a = 25;
	printf_s("修改前，a：%d\n",a);
	modify(a);
	printf_s("修改后，a：%d\n",a);

	int *p = NULL;
	printf_s("\n修改前，p：%p\n",p);
	pointmodify(&p);
	printf_s("修改后，p：%p\n",p);

	printf_s("\n%d   %d\n",INT_MAX,INT_MIN);*/



	int  j,n;
	char s[3] = "边";
	Graph g;
	VertexType v1,v2;
	printf_s("请依次选择 有向图，有向网，无向图，无向网\n");
	for (int i = 0; i < 4; i++)
	{
		createGraph(&g);
		display(g);
		printf_s("插入新顶点，请输入新顶点的值：");
		inputVex(&v1);
		insertVex(&g,v1);
		if (g.kind < 2)
		{
			strcpy_s(s,"弧");
		}
		printf_s("插入与新顶点有关的%s,请输入%s数",s,s);
		scanf_s("%d",&n);
		for (int k = 0; k < n; k++)
		{
			printf_s("请输入另一顶点的名称：");
			scanf_s("%s",v2.name);
			//有向
			if (g.kind <= 1)
			{
				printf_s("");
				scanf_s("%s",&j);
				if (j)
				{
					insertArc(&g,v2,v1);
				}
				else
				{
					insertArc(&g,v1,v2);
				}
			}
			//无向
			else
			{
				insertArc(&g,v1,v2);
			}
		}
		display(g);
		printf_s("删除顶点及相关的%s，请输入带删除顶点的名称：",s);
		scanf_s("%s",v1.name);
		deleteVex(&g,v1);
		display(g);
		if (3 == i)
		{
			printf_s("修改顶点的值，请输入待修改顶点名称 新值：");
			scanf_s("%s",v1.name);
			inputVex(&v2);
			putVex(&g,v1,v2);
			if (g.kind < 2)
			{
				printf_s("删除一条%s，请输入待删除%s的弧尾 弧头",s,s);
			}else
			{
				printf_s("删除一条%s，请输入待删除%s的顶点1 顶点2",s,s);
			}
			scanf_s("%s%s",v1.name,v2.name);
			deleteArc(&g,v1,v2);
			display(g);
		}
		destroyGraph(&g);
	}
	system("pause");
	return 0;
}



void modify(int &n)
{
	n = 64;
}



void pointmodify(int **p)
{
	*p = (int *)malloc(sizeof(int));
}