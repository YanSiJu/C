#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_VERTEX_NUM 10
#define MAX_NAME 10
#define OK 1
#define ERROR -1
#include"Queue.h"



//图的种类  {有向图，有向网，无向图，无向网}
enum GraphKind{DG,DN,UDG,UDN};
//权值类型
typedef int VRTYPE;
typedef int Status;


//顶点信息类型
typedef struct VertexType
{
	//顶点名称
	char name[MAX_NAME];
}VertexType;


//弧的信息类型
typedef struct  InfoType
{
	//权值
	VRTYPE weight;
}InfoType;


//表结点，存储弧的信息
typedef struct  ArcNode
{
	//弧所指向的顶点的位置
	int adjvex;
	//弧的信息
	InfoType *info;
	//指向下一条弧的指针
	struct ArcNode *nextArc;
}ArcNode;



//顶点
typedef struct  VNode
{
	VertexType data;
	ArcNode *firstArc;
}VNode,AdjList[MAX_VERTEX_NUM];



//邻接表存储结构
typedef	struct  ALGraph
{
	//顶点集合
	AdjList vertices;
	//当前弧的数目
	int arcnum;
	//当前顶点数目
	int vexnum;
	//图的种类
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
void DFSTraverse(ALGraph g,Status(* visit)(VertexType));
void DFS(ALGraph g,int v);
void BFSTraverse(ALGraph g,Status(* visit)(VertexType));
Status visit(VertexType v);
void inputVex(VertexType *v);
ArcNode *point(ArcNode *arc,ArcNode e,bool (* equal)(ArcNode,ArcNode),ArcNode *prior);
void inputArc(InfoType **arc);
void outputArc(InfoType arc);
void display(ALGraph g);
//访问标志数组
bool visited[MAX_VERTEX_NUM];
//访问函数变量
Status (* visitFunc)(VertexType);



bool equalVex(ArcNode a,ArcNode b)
{
	return a.adjvex == b.adjvex;
}

void createGraph(ALGraph *g)
{
	VertexType v,w;
	char s[3] = "边";
	printf_s("请输入图的类型：（有向图：0  有向网：1  无向图：2  无向网：3）：");
	scanf_s("%d",&g->kind);
	if (g->kind < 2)
	{
		strcpy_s(s,"弧");
	}
	printf_s("请输入图的顶点数﹑%s数",s);
	scanf_s("%d%d",&g->vexnum,&g->arcnum);
	printf_s("请输入%d个顶点的名称(名称<%d个字符)：\n",g->vexnum,MAX_NAME);
	for (int j = 0; j < g->vexnum; j++)
	{
		inputVex(&g->vertices[j].data);
		//scanf_s("%s",g->vertices[j].data.name);
	}
	printf_s("请输入%d条%s的",g->arcnum,s);
	switch (g->kind)
	{
		case DG:printf_s("弧尾﹑弧头");//有向图
			break;
		case DN:printf_s("弧尾﹑弧头﹑弧的信息");//有向网
			break;
		case UDG:printf_s("顶点1﹑顶点2");//无向图
			break;
		case UDN:printf_s("顶点1﹑顶点2﹑边的信息");//无向网
			break;
	}
	int i,j;
	ArcNode arc;
	for (int k = 0; k < g->arcnum; k++)
	{
		scanf_s("%s%s",v.name,w.name);
		i = locateVex(*g,v);
		j = locateVex(*g,w);
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
	char s1[3] = "边";
	char s2[3] = "-";
	if (g->kind < 2)
	{
		strcpy_s(s1,"弧");
		strcpy_s(s2,"->");
	}
	arc.adjvex = j;
	arc.info = NULL;
	if ((*g).kind%2)
	{
		printf_s("请输入%s%s%s%s的信息:",s1,v.name,s2,w.name);
		inputArc(&arc.info);
	}
	listInsert((*g).vertices[i].firstArc,arc);
	//无向
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
		//网
		if (g->kind%2)
		{
			if (arc.info)
			{
				/*释放弧信息空间*/
				free(arc.info);
			}
		}
		/*无向，删除对称弧<w,v>*/
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
	//有向图（网）
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
		//顶点V后面的顶点依次前移
		g->vertices[i-1] = g->vertices[i];
	}
	//顶点数减1
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
	//删除头结点
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



void DFSTraverse(ALGraph g,Status(* visit)(VertexType))
{
	visitFunc = visit;
	for (int i = 0; i < g.vexnum; i++)
	{
		visited[i] = false;
	}
	for (int j = 0; j < g.vexnum; j++)
	{
		if (!visited[j])
		{
			DFS(g,j);
		}
	}
}



void DFS(ALGraph g,int v)
{
	visited[v] = true;
	visitFunc(getVex(g,v));
	for (int w = firstAdjvex(g,v);w >= 0;w = nextAdjvex(g,v,w))
	{
		if (!visited[w])
		{
			DFS(g,w);
		}
	}
}



void BFSTraverse(ALGraph g,Status(* visit)(VertexType))
{
	int u,v,w;
	LinkQueue q;
	initQueue(&q);
	for (int i = 0; i < g.vexnum; i++)
	{
		visited[i] = false;
	}
	for (v = 0; v < g.vexnum; v++)
	{
		if (!visited[v])
		{
			visit(getVex(g,v));
			visited[v] = true;
			enQueue(&q,v);
			while (!queueEmpty(q))
			{
				deQueue(&q,&u);
				for (w = firstAdjvex(g,u);w>=0;w = nextAdjvex(g,u,w))
				{
					if (!visited[w])
					{
						visit(getVex(g,w));
						visited[w] = true;
						enQueue(&q,w);
					}
				}
			}
		}
	}
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
	char s1[3] = "边";
	char s2[3] = "-";
	if (g.kind < 2)
	{
		strcpy_s(s1,"弧");
		strcpy_s(s2,"->");
	}
	switch (g.kind)
	{
		case DG:printf_s("有向图\n");
			break;
		case DN:printf_s("有向网\n");
			break;
		case UDG:printf_s("无向图\n");
			break;
		case UDN:printf_s("无向网\n");
			break;
	}
	printf_s("%d个顶点，依次是：",g.vexnum);
	for (int i = 0; i < g.vexnum; i++)
	{
		visit(getVex(g,i));
	}
	printf_s("\n%d条%s:\n",g.arcnum,s1);
	for (int j = 0; j < g.arcnum; j++)
	{
		p = g.vertices[j].firstArc;
		while (p)
		{
			if (g.kind < 2 || j < p->adjvex)
			{
				printf_s("   %s%s%s",g.vertices[j].data.name,s2,g.vertices[p->adjvex].data.name);
				if (g.kind%2)
				{
					outputArc(*p->info);
				}
			}
			p = p->nextArc;
		}
		printf_s("\n");
	}
}



