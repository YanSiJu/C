// Graph.cpp : �������̨Ӧ�ó������ڵ㡣
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
	printf_s("%d  %d  %d  %d %d\n",DG,DN,UDG,UDN,errno);
	int a = 25;
	printf_s("�޸�ǰ��a��%d\n",a);
	modify(a);
	printf_s("�޸ĺ�a��%d\n",a);

	int *p = NULL;
	printf_s("\n�޸�ǰ��p��%p\n",p);
	pointmodify(&p);
	printf_s("�޸ĺ�p��%p\n",p);

	printf_s("\n%d   %d\n",INT_MAX,INT_MIN);

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