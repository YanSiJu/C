// Graph.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include"MGraph.h"
#include"ShortestPathDIJ.h"
#include"MakePath.h"
#define Graph MGraph

//#include"ALGraph.h"
//#define Graph ALGraph

void modify(int &n);
void pointmodify(int **p);
void input(char **info);
//void copyString(char src[],char *dest);

int _tmain(int argc, _TCHAR* argv[])
{
	//enum GraphKind{DG,DN,UDG,UDN};
	/*printf_s("%d  %d  %d  %d %d\n",DG,DN,UDG,UDN,errno);
	int a = 25;
	printf_s("�޸�ǰ��a��%d\n",a);
	modify(a);
	printf_s("�޸ĺ�a��%d\n",a);

	int *p = NULL;
	printf_s("\n�޸�ǰ��p��%p\n",p);
	pointmodify(&p);
	printf_s("�޸ĺ�p��%p\n",p);

	printf_s("\n%d   %d\n",INT_MAX,INT_MIN);*/

	/*printf_s("%d %d  %d  %d\n\n",DG,DN,UDG,UDN);*/

	system("title Graph");
	/*char  *info = "Good!!";
	input(&info);
	printf_s("--->%s   %p\n",info,info);*/

	

	/*char s[12];
	char str[12];
	scanf_s("%s%s",s,sizeof(s),str,sizeof(str));
	for(int i=0; i<10;i++)
	{
		printf_s("%c",s[i]);
	}
	printf_s("\n");
	for(int i=0; i<10;i++)
	{
		printf_s("%c",str[i]);
	}
	printf_s("\n");*/

	//int  j,n;
	//char s[3] = "��";
	//Graph g;
	//VertexType v1,v2;
	//printf_s("������ѡ�� ����ͼ��������������ͼ��������\n");
	//for (int i = 0; i < 4; i++)
	//{
	//	createGraph(&g);
	//	display(g);
	//	printf_s("�����¶��㣬�������¶����ֵ��");
	//	inputVex(&v1);
	//	//��ͼ�в����¶���v1
	//	insertVex(&g,v1);
	//	if (g.kind < 2)
	//	{
	//		strcpy_s(s,"��");
	//	}
	//	printf_s("�������¶����йص�%s,������%s����",s,s);
	//	scanf_s("%d",&n);
	//	for (int k = 0; k < n; k++)
	//	{
	//		printf_s("��������һ��������ƣ�");
	//		scanf_s("%s",v2.name,sizeof(v2.name));
	//		//����
	//		if (g.kind <= 1)
	//		{
	//			printf_s("��������һ����ķ���0����ͷ  1����β��:");
	//			scanf_s("%d%*c",&j);
	//			//v2�ǻ�β
	//			if (j)
	//			{
	//				insertArc(&g,v2,v1);
	//			}
	//			//v2�ǻ�ͷ
	//			else
	//			{
	//				insertArc(&g,v1,v2);
	//			}
	//		}
	//		//����
	//		else
	//		{
	//			insertArc(&g,v1,v2);
	//		}
	//	}
	//	//���ͼG
	//	display(g);
	//	printf_s("ɾ�����㼰��ص�%s���������ɾ����������ƣ�",s);
	//	scanf_s("%s",v1.name,sizeof(v1.name));
	//	//��ͼG��ɾ������v1
	//	deleteVex(&g,v1);
	//	//���ͼG
	//	display(g);
	//	//�������һ�����������������º���
	//	if (3 == i)
	//	{
	//		printf_s("�޸Ķ����ֵ����������޸Ķ������� ��ֵ��");
	//		//������޸Ķ������ƣ��Բ��Ҵ��޸ĵĶ���
	//		scanf_s("%s",v1.name,sizeof(v1.name));
	//		//���붥�����ֵ�������ԭֵ
	//		inputVex(&v2);
	//		//��ͼG�ж���V1��ֵ��ΪV2
	//		putVex(&g,v1,v2);
	//		if (g.kind < 2)
	//		{
	//			printf_s("ɾ��һ��%s���������ɾ��%s�Ļ�β ��ͷ��",s,s);
	//		}else
	//		{
	//			printf_s("ɾ��һ��%s���������ɾ��%s�Ķ���1 ����2��",s,s);
	//		}
	//		//�����ɾ������2�����������
	//		scanf_s("%s%s",v1.name,sizeof(v1.name),v2.name,sizeof(v2.name));
	//		//ɾ��ͼG���ɶ���v1ָ��v2�Ļ�
	//		deleteArc(&g,v1,v2);
	//		//���ͼG
	//		display(g);
	//	}
	//	//����ͼG
	//	destroyGraph(&g);
	//}





	//DIJ�㷨

    MGraph g;
	//��ά���飬·������
	PathMatrix p;
	//һά���飬��̾����
	ShortPathTable d;
	bool *path;

	int k = 0;
	createFromFile(&g,"graph.txt",0);
	path = (bool *)malloc(g.vexnum * sizeof(bool));
	display(g);
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
			printf_s("%s--->%s:%d  ",g.vexs[k].name,g.vexs[i].name,d[i]);
			printf_s("%s--->",g.vexs[k].name);
			for (int j = 0; j < g.vexnum; j++)
			{
				path[j] = p[i][j];
			}
			MakePath(g,path,k,i);
		}
	}
	system("pause");
	return 0;
}



void modify(int &n)
{
	n = 64;
}


void input(char **info)
{
	char s[MAX_INFO];
	scanf_s("%s",s,sizeof(s));
	*info = (char *)malloc(strlen(s)*sizeof(char));
	copyString(s,*info);
	printf_s("%p\n",*info);
}


//void copyString(char src[],char *dest)
//{
//	int i;
//	for (i = 0; src[i] != '\0'; i++)
//	{
//		*(dest+i) = src[i];
//	}
//	*(dest+i) = '\0';
//}



void pointmodify(int **p)
{
	*p = (int *)malloc(sizeof(int));
}