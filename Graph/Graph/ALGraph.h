#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_VERTEX_NUM 10
#define MAX_NAME 10
#define OK 1
#define ERROR -1
#include"Queue.h"



//ͼ������  {����ͼ��������������ͼ��������}
enum GraphKind{DG,DN,UDG,UDN};
//Ȩֵ����
typedef int VRTYPE;
typedef int Status;


//������Ϣ����
typedef struct VertexType
{
	//��������
	char name[MAX_NAME];
}VertexType;


//������Ϣ����
typedef struct  InfoType
{
	//Ȩֵ
	VRTYPE weight;
}InfoType;


//���㣬�洢������Ϣ
typedef struct  ArcNode
{
	//����ָ��Ķ����λ��
	int adjvex;
	//������Ϣ
	InfoType *info;
	//ָ����һ������ָ��
	struct ArcNode *nextArc;
}ArcNode;



//����
typedef struct  VNode
{
	VertexType data;
	ArcNode *firstArc;
}VNode,AdjList[MAX_VERTEX_NUM];



//�ڽӱ�洢�ṹ
typedef	struct  ALGraph
{
	//���㼯��
	AdjList vertices;
	//��ǰ������Ŀ
	int arcnum;
	//��ǰ������Ŀ
	int vexnum;
	//ͼ������
	GraphKind kind;
}ALGraph;



void createGraph(ALGraph *g);
void destroyGraph(ALGraph *g);
int locateVex(ALGraph g,VertexType u);
VertexType getVex(ALGraph g,int v);
Status putVex(ALGraph *g,VertexType v,VertexType value);
int firstAdjvex(ALGraph g,int v);
int nextAdjvex(ALGraph g,int v,int w);
bool equalVex(ArcNode a,ArcNode b);
void insertVex(ALGraph *g,VertexType v);
Status insertArc(ALGraph *g,VertexType v,VertexType w);
Status deleteArc(ALGraph *g,VertexType v,VertexType w);
Status deleteVex(ALGraph *g,VertexType v);
int locateArc(ArcNode *first,ArcNode a,bool (* equal)(ArcNode,ArcNode));
void listInsert(ArcNode *first,ArcNode arc);
Status listDelete(ArcNode **first,int n,ArcNode *arc);
Status visit(VertexType v);
void inputVex(VertexType *v);
ArcNode *point(ArcNode *arc,ArcNode e,bool (* equal)(ArcNode,ArcNode),ArcNode *prior);
void inputArc(InfoType **arc);
void outputArc(InfoType arc);
void display(ALGraph g);




bool equalVex(ArcNode a,ArcNode b)
{
	return a.adjvex == b.adjvex;
}

//ʹ���ڽӱ�ṹ������ͼ����G
void createGraph(ALGraph *g)
{
	VertexType v,w;
	char s[3] = "��";
	printf_s("������ͼ�����ͣ�������ͼ��0  ��������1  ����ͼ��2  ��������3����");
	scanf_s("%d",&g->kind);
	if (g->kind < 2)
	{
		strcpy_s(s,"��");
	}
	printf_s("������ͼ�Ķ������p%s��:",s);
	scanf_s("%d%d",&g->vexnum,&g->arcnum);
	printf_s("������%d�����������(����<%d���ַ�)��\n",g->vexnum,MAX_NAME);
	for (int j = 0; j < g->vexnum; j++)
	{
		inputVex(&g->vertices[j].data);
		g->vertices[j].firstArc = NULL;
		//scanf_s("%s",g->vertices[j].data.name);
	}
	printf_s("������%d��%s��",g->arcnum,s);
	switch (g->kind)
	{
		case DG:printf_s("��β�p��ͷ");//����ͼ
			break;
		case DN:printf_s("��β�p��ͷ�p������Ϣ");//������
			break;
		case UDG:printf_s("����1�p����2");//����ͼ
			break;
		case UDN:printf_s("����1�p����2�p�ߵ���Ϣ");//������
			break;
	}
	ArcNode arc;
	for (int k = 0; k < g->arcnum; k++)
	{
		scanf_s("%s%s",v.name,w.name);
		int i = locateVex(*g,v);
		int j = locateVex(*g,w);
		if (i<0 || j<0)
		{
			continue;
		}
		arc.adjvex = j;
		arc.info = NULL;
		if (g->kind%2)
		{
			inputArc(&arc.info);
		}
		listInsert(g->vertices[i].firstArc,arc);
		if (g->kind >= 2)
		{
			arc.adjvex = i;
			listInsert(g->vertices[j].firstArc,arc);
		}
	}
}



//void shortedPathFloyd(ALGraph g,PathMatrix p,DistanceMatrix d)
//{
//
//}



int locateVex(ALGraph g,VertexType u)
{
	int i;
	for (i = 0; i < g.vexnum; i++)
	{
		if (strcmp(u.name,g.vertices[i].data.name) == 0)
		{
			return i;
		}
	}
	return -1;
}



ArcNode *point(ArcNode *arc,ArcNode e,bool (* equal)(ArcNode,ArcNode),ArcNode *prior)
{
	ArcNode *p = arc;
	prior = NULL;
	for (;NULL != p; p=p->nextArc)
	{
		if (equal(*p,e))
		{
			return p;
		}
		prior = p;
	}
	return NULL;
}



VertexType getVex(ALGraph g,int v)
{
	if (v >= g.vexnum || v < 0)
	{
		exit(-1);
	}
	return g.vertices[v].data;
}



Status putVex(ALGraph *g,VertexType v,VertexType value)
{
	int loc = locateVex(*g,v);
	if (-1 != loc)
	{
		g->vertices[loc].data = value;
		return OK;
	}
	return ERROR;
}



int firstAdjvex(ALGraph g,int v)
{
	ArcNode *q;
	return v >= g.vexnum || v < 0?ERROR:(q=g.vertices[v].firstArc) != NULL?q->adjvex:ERROR;
	/*if (v >= g.vexnum || v < 0)
	{
		return ERROR;
	}
	ArcNode *p = g.vertices[v].firstArc;
	return NULL != p?p->adjvex:ERROR;*/
	/*if (p)
	{
		return p->adjvex;
	}
	return ERROR;*/
}



int nextAdjvex(ALGraph g,int v,int w)
{
	ArcNode *p = NULL;
	ArcNode *prior = NULL;
	ArcNode arc;
	arc.adjvex = w;
	p = point(g.vertices[v].firstArc,arc,equalVex,prior);
	return !p||!p->nextArc?-1:p->nextArc->adjvex;
	/*if (!p || !p->nextArc)
	{
		return -1;
	}
	return p->nextArc->adjvex;*/
}



void insertVex(ALGraph *g,VertexType v)
{
	if (g->vexnum+1 > MAX_VERTEX_NUM)
	{
		return;
	}
	g->vertices[g->vexnum].data = v;
	g->vertices[g->vexnum].firstArc = NULL;
	g->vexnum++;
}



Status insertArc(ALGraph *g,VertexType v,VertexType w)
{
	ArcNode arc;
	int i = locateVex(*g,v);
	int j = locateVex(*g,w);
	if (i<0 || j<0)
	{
		return ERROR;
	}
	char s1[3] = "��";
	char s2[3] = "-";
	if (g->kind < 2)
	{
		strcpy_s(s1,"��");
		strcpy_s(s2,"->");
	}
	arc.adjvex = j;
	arc.info = NULL;
	if ((*g).kind%2)
	{
		printf_s("������%s%s%s%s����Ϣ:",s1,v.name,s2,w.name);
		inputArc(&arc.info);
	}
	listInsert((*g).vertices[i].firstArc,arc);
	//����
	if ((*g).kind>=2)
	{
		arc.adjvex = i;
		listInsert((*g).vertices[j].firstArc,arc);
	}
	(*g).arcnum++;
	return OK;
}



Status deleteArc(ALGraph *g,VertexType v,VertexType w)
{
	int i = locateVex(*g,v);
	int j = locateVex(*g,w);
	if (i<0 || j<0 || i == j)
	{
		return ERROR;
	}
	ArcNode arc;
	arc.adjvex = j;
	int n = locateArc((*g).vertices[i].firstArc,arc,equalVex);
	if (-1 != n)
	{
		listDelete(&g->vertices[i].firstArc,n,&arc);
		(*g).arcnum--;
		//��
		if (g->kind%2)
		{
			if (arc.info)
			{
				/*�ͷŻ���Ϣ�ռ�*/
				free(arc.info);
			}
		}
		/*����ɾ���Գƻ�<w,v>*/
		if ((*g).kind>1)
		{
			arc.adjvex = i;
			n = locateArc((*g).vertices[j].firstArc,arc,equalVex);
			listDelete(&g->vertices[j].firstArc,n,&arc);
		}
		return OK;
	}
	return ERROR;
}



Status deleteVex(ALGraph *g,VertexType v)
{
	int k = locateVex(*g,v);
	if (-1 == k)
	{
		return ERROR;
	}
	for (int i = 0; i < (*g).vexnum; i++)
	{
		deleteArc(g,v,(*g).vertices[i].data);
	}
	//����ͼ������
	if ((*g).kind<2)
	{
		for (int i = 0; i<(*g).vexnum; i++)
		{
			deleteArc(g,(*g).vertices[i].data,v);
		}
	}
	ArcNode *p;
	for (int i = 0; i<g->vexnum;i++)
	{
		p = (*g).vertices[i].firstArc;
		while (p)
		{
			if (p->adjvex>k)
			{
				p->adjvex--;
			}
			p = p->nextArc;
		}
	}
	for (int i = k+1; i < g->vexnum; i++)
	{
		//����V����Ķ�������ǰ��
		g->vertices[i-1] = g->vertices[i];
	}
	//��������1
	g->vexnum--;
	return OK;
}



int locateArc(ArcNode *first,ArcNode a,bool (* equal)(ArcNode,ArcNode))
{
	ArcNode *p = first;
	int count = 1;
	while (p)
	{
		if (equal(*p,a))
		{
			return count;
		}
		count++;
		p = p->nextArc;
	}
	return -1;
}



void listInsert(ArcNode *first,ArcNode e)
{
	ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
	if (!p)
	{
		return;
	}
	*p = e;
	p->nextArc = first;
	first = p;
}



Status listDelete(ArcNode **first,int n,ArcNode *arc)
{
	int count = 1;
	ArcNode *p = *first;
	ArcNode *q = NULL;
	if(!p)
	{
		return ERROR;
	}
	//ɾ��ͷ���
	if(1 == n)
	{
		*first = (*first)->nextArc;
		arc->adjvex = p->adjvex;
		arc->info = p->info;
		free(p);
		return OK;
	}
	while(p->nextArc &&  count < n-1)
	{
		p = p->nextArc;
		count++;
	}
	if(!(p->nextArc) || count>n-1)
	{
		return ERROR;
	}
	q = p->nextArc;
	p->nextArc = q->nextArc;
	arc->adjvex = q->adjvex;
	arc->info = q->info;
	free(q);
	return OK;
}

void destroyGraph(ALGraph *g)
{
	for (int i = (*g).vexnum-1; i >= 0; i--)
	{
		deleteVex(g,(*g).vertices[i].data);
	}
}



Status visit(VertexType v)
{
	printf_s("%s  ",v.name);
	return OK;
}



void inputVex(VertexType *v)
{
	scanf_s("%s",v->name);
}



void inputArc(InfoType **arc)
{
	*arc = (InfoType *)malloc(sizeof(InfoType));
	if (*arc)
	{
		scanf_s("%d",&(*arc)->weight);
	}
}



void outputArc(InfoType arc)
{
	printf_s("  %d  ",arc.weight);
}



void display(ALGraph g)
{
	ArcNode *p = NULL;
	char s1[3] = "��";
	char s2[3] = "-";
	//����
	if (g.kind < 2)
	{
		strcpy_s(s1,"��");
		strcpy_s(s2,"->");
	}
	switch (g.kind)
	{
		case DG:printf_s("����ͼ\n");
			break;
		case DN:printf_s("������\n");
			break;
		case UDG:printf_s("����ͼ\n");
			break;
		case UDN:printf_s("������\n");
			break;
	}
	printf_s("%d�����㣬�����ǣ�",g.vexnum);
	for (int i = 0; i < g.vexnum; i++)
	{
		//���ݶ�����Ϣ���ͣ����η���ÿ������
		visit(getVex(g,i));
	}
	printf_s("\n%d��%s:\n",g.arcnum,s1);
	for (int j = 0; j < g.arcnum; j++)
	{
		//pָ�����Ϊi�Ķ���ĵ�һ����
		p = g.vertices[j].firstArc;
		while (p)
		{
			//����������еĵ�һ��
			if (g.kind < 2 || j < p->adjvex)
			{
				printf_s("   %s%s%s",g.vertices[j].data.name,s2,g.vertices[p->adjvex].data.name);
				//��
				if (g.kind%2)
				{
					//�������Ϣ
					outputArc(*p->info);
				}
			}
			p = p->nextArc;
		}
		printf_s("\n");
	}
}



