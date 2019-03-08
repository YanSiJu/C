#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
#define MAX_NAME 10
#define MAX_INFO 20
#define OK 1
#define ERROR -1



typedef int Status;
typedef int VRType;
//ͼ������  {����ͼ��������������ͼ��������}
typedef enum{DG,DN,UDG,UDN} GraphKind;


//������Ϣ����
typedef struct VertexType
{
	//��������
	char name[MAX_NAME];
}VertexType;


//������Ϣ����
typedef struct  InfoType
{
	char info[MAX_INFO];
}InfoType;


//����Ϣ�ṹ
typedef struct ArcCell
{
	VRType adj;
	InfoType *info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];


//�ڽӾ���洢�ṹ
typedef struct MGraph
{
	//��������
	VertexType vexs[MAX_VERTEX_NUM];
	//�ڽӾ���
	AdjMatrix arcs;
	int arcnum;
	int vexnum;
	//ͼ������
	GraphKind kind;
}MGraph;


void visit(VertexType vex);
void inputVex(VertexType *vex);
void inputArc(InfoType **info);
void outputArc(InfoType info);
void createGraph(MGraph *g);
void createDG(MGraph *g);
void createDN(MGraph *g);
void createUDN(MGraph *g);
void createUDG(MGraph *g);
int locateVex(MGraph g,VertexType v);
VertexType getVex(MGraph g,int v);
Status putVex(MGraph *g,VertexType v,VertexType value);
int firstAdjVex(MGraph g,int v);
int nextAdjVex(MGraph g,int v,int w);
void insertVex(MGraph *g,VertexType v);
Status insertArc(MGraph *g,VertexType v,VertexType w);
Status deleteVex(MGraph *g,VertexType v);
Status deleteArc(MGraph *g,VertexType v,VertexType w);
void destroyGraph(MGraph *g);
void display(MGraph g);



void createGraph(MGraph *g)
{
	switch (g->kind)
	{
	 case DN:createDN(g);
		break;
	 case DG:createDG(g);
		 break;
	 case UDN:createUDN(g);
		 break;
	 case UDG:createUDG(g);
		 break;
	}
}


//��������ͼG
void createDG(MGraph *g)
{
	VertexType v,w;
	int incInfo;
	printf_s("������ͼ�Ķ������p�����p�Ƿ��������Ϣ��0���� 1���У�");
	//%*c�Ե��س���
	scanf_s("%d%d%d%*c",&g->vexnum,&g->arcnum,&incInfo);
	printf_s("������%d�������ֵ(����<%d���ַ�)��",g->vexnum,MAX_NAME);
	//���춥������
	for (int i = 0; i < g->vexnum; i++)
	{
		//���붥����Ϣ
		inputVex(&g->vexs[i]);
	}
	//��ʼ����ά����
	for (int i = 0; i < g->vexnum; i++)
	{
		for (int j = 0; j < g->vexnum; j++)
		{
			//����ͼ��������
			g->arcs[i][j].adj = 0;
			//�������Ϣ
			g->arcs[i][j].info = NULL;
		}
	}
	printf_s("������%d�����Ļ�β�p��ͷ��\n",g->arcnum);
	for (int k = 0; k < g->arcnum; k++)
	{
		//%*c�Ե��س���
		scanf_s("%s%s%*c",v.name,w.name);
		int i = locateVex(*g,v);
		int j = locateVex(*g,w);
		//�����ڶ���v��w
		if (i < 0 || j < 0)
		{
			continue;
		}
		//����ͼ������
		g->arcs[i][j].adj = 1;
		//�������Ϣ
		if (incInfo)
		{
			//��̬���ɴ洢�ռ䣬�洢������Ϣ
			inputArc(&g->arcs[i][j].info);
		}
	}
	g->kind = DG;
}


//����������
void createDN(MGraph *g)
{
	VertexType v,w;
	int incInfo;
	printf_s("������ͼ�Ķ������p�����p�Ƿ��������Ϣ��0���� 1���У�");
	scanf_s("%d%d%d%*c",&g->vexnum,&g->arcnum,&incInfo);
	printf_s("������%d�������ֵ(����<%d���ַ�)��",g->vexnum,MAX_NAME);
	//���춥������
	for (int i = 0; i < g->vexnum; i++)
	{
		//���붥����Ϣ
		inputVex(&g->vexs[i]);
	}
	//��ʼ����ά����
	for (int i = 0; i < g->vexnum; i++)
	{
		for (int j = 0; j < g->vexnum; j++)
		{
			//��������������
			g->arcs[i][j].adj = INFINITY;
			//�������Ϣ
			g->arcs[i][j].info = NULL;
		}
	}
	printf_s("������%d�����Ļ�β�p��ͷ�pȨֵ��",g->arcnum);
	int weight = 0;
	for (int k = 0; k < g->arcnum; k++)
	{
		//%*c�Ե��س���
		scanf_s("%s%s%d%*c",v.name,w.name,&weight);
		int i = locateVex(*g,v);
		int j = locateVex(*g,w);
		//�����ڶ���v��w
		if (i < 0 || j < 0)
		{
			continue;
		}
		//������������
		g->arcs[i][j].adj = weight;
		//�������Ϣ
		if (incInfo)
		{
			//��̬���ɴ洢�ռ䣬�洢������Ϣ
			inputArc(&g->arcs[i][j].info);
		}
	}
	g->kind = DN;
}


//����������
void createUDN(MGraph *g)
{
	VertexType v,w;
	int incInfo;
	printf_s("������ͼ�Ķ������p�����p�Ƿ��������Ϣ��0���� 1���У�");
	scanf_s("%d%d%d%*c",&g->vexnum,&g->arcnum,&incInfo);
	printf_s("������%d�������ֵ(����<%d���ַ�)��",g->vexnum,MAX_NAME);
	//���춥������
	for (int i = 0; i < g->vexnum; i++)
	{
		//���붥����Ϣ
		inputVex(&g->vexs[i]);
	}
	//��ʼ����ά����
	for (int i = 0; i < g->vexnum; i++)
	{
		for (int j = 0; j < g->vexnum; j++)
		{
			//��������������
			g->arcs[i][j].adj = INFINITY;
			//�������Ϣ
			g->arcs[i][j].info = NULL;
		}
	}
	printf_s("������%d�����Ļ�β�p��ͷ�pȨֵ��",g->arcnum);
	int weight;
	for (int k = 0; k < g->arcnum; k++)
	{
		//%*c�Ե��س���
		scanf_s("%s%s%d%*c",v.name,w.name,&weight);
		int i = locateVex(*g,v);
		int j = locateVex(*g,w);
		//�����ڶ���v��w
		if (i < 0 || j < 0)
		{
			continue;
		}
		//������������
		g->arcs[i][j].adj = weight;
		//�������Ϣ
		if (incInfo)
		{
			//��̬���ɴ洢�ռ䣬�洢������Ϣ
			inputArc(&g->arcs[i][j].info);
		}
		//��������Ԫ�ش洢����Ϣ��ͬ
		g->arcs[j][i] = g->arcs[i][j];
	}
	g->kind = UDN;
}


//��������ͼ
void createUDG(MGraph *g)
{
	VertexType v,w;
	int incInfo;
	printf_s("������ͼ�Ķ������p�����p�Ƿ��������Ϣ��0���� 1���У�");
	scanf_s("%d%d%d%*c",&g->vexnum,&g->arcnum,&incInfo);
	printf_s("������%d�������ֵ(����<%d���ַ�)��",g->vexnum,MAX_NAME);
	//���춥������
	for (int i = 0; i < g->vexnum; i++)
	{
		//���붥����Ϣ
		inputVex(&g->vexs[i]);
	}
	//��ʼ����ά����
	for (int i = 0; i < g->vexnum; i++)
	{
		for (int j = 0; j < g->vexnum; j++)
		{
			//����ͼ��������
			g->arcs[i][j].adj = 0;
			//�������Ϣ
			g->arcs[i][j].info = NULL;
		}
	}
	printf_s("������%d�����Ļ�β�p��ͷ��\n",g->arcnum);
	for (int k = 0; k < g->arcnum; k++)
	{
		//%*c�Ե��س���
		scanf_s("%s%s%*c",v.name,w.name);
		int i = locateVex(*g,v);
		int j = locateVex(*g,w);
		//�����ڶ���v��w
		if (i < 0 || j < 0)
		{
			continue;
		}
		//����ͼ������
		g->arcs[i][j].adj = 1;
		//�������Ϣ
		if (incInfo)
		{
			//��̬���ɴ洢�ռ䣬�洢������Ϣ
			inputArc(&g->arcs[i][j].info);
		}
		//��������Ԫ�ش洢����Ϣ��ͬ
		g->arcs[j][i] = g->arcs[i][j];
	}
	//����ͼ
	g->kind = UDG;
}



int locateVex(MGraph g,VertexType v)
{
	for (int i = 0; i < g.vexnum; i++)
	{
		if (0 == strcmp(v.name,g.vexs[i].name))
		{
			return i;
		}
	}
	return -1;
}



VertexType getVex(MGraph g,int v)
{
	if (v<0 || v>=g.vexnum)
	{
		VertexType v;
		strcpy_s(v.name,NULL);
		return v;
	}
	return g.vexs[v];
}



Status putVex(MGraph *g,VertexType v,VertexType value)
{
	int i = locateVex(*g,v);
	if (i < 0)
	{
		return ERROR;	
	}
	g->vexs[i] = value;
	return OK;	
}



int firstAdjVex(MGraph g,int v)
{
	VRType j = 0;
	if (g.kind%2)
	{
		j = INFINITY;
	}
	//�ӵ�1�����㿪ʼ
	for (int i = 0; i < g.vexnum; i++)
	{
		//��һ���ڽӵ�
		if (g.arcs[v][i].adj != j)
		{
			//���ظ��ڽӶ�������
			return i;
		}
	}
	return -1;
}



int nextAdjVex(MGraph g,int v,int w)
{
	//�����ϵ���ͣ�ͼ
	VRType j = 0;
	//��
	if (g.kind%2)
	{
		j = INFINITY;
	}
	//�ӵ�w+1�����㿪ʼ
	for (int i = w+1; i < g.vexnum; i++)
	{
		//�ӵ�w+1�����㿪ʼ�ĵ�һ���ڽӵ�
		if (g.arcs[v][i].adj != j)
		{
			return i;
		}
	}
	return -1;
}



void insertVex(MGraph *g,VertexType v)
{
	if (g->vexnum+1 <= MAX_VERTEX_NUM)
	{
		g->vexs[g->vexnum] = v;
		VRType j = 0;
		if (g->kind%2)
		{
			j = INFINITY;
		}
		for (int i = 0; i <= g->vexnum; i++)
		{
			g->arcs[g->vexnum][i].adj = g->arcs[i][g->vexnum].adj = j;
			g->arcs[g->vexnum][i].info = g->arcs[i][g->vexnum].info = NULL;
		}
		g->vexnum++;
	}
}



Status insertArc(MGraph *g,VertexType v,VertexType w)
{
	int v1 = locateVex(*g,v);
	int w1 = locateVex(*g,w);
	if (v1 < 0 || w1 < 0 || v1 == w1)
	{
		return ERROR;
	}
	//��
	if (g->kind%2)
	{
		printf_s("�����뻡���ߣ���Ȩֵ:");
		scanf_s("%d",g->arcs[v1][w1].adj);
	}else
	{
		//ͼ
		g->arcs[v1][w1].adj = 1;
	}
	printf_s("�Ƿ��иû��������Ϣ0���� 1���У�");
	int i;
	scanf_s("%d%*c",&i);
	if (1 == i)
	{
		inputArc(&g->arcs[v1][w1].info);
	}
	//����
	if (g->kind>1)
	{
		g->arcs[w1][v1] = g->arcs[v1][w1];
	}
	g->arcnum++;
	return OK;
}


//��ͼg�д��ڶ���v����ɾ��ͼg�еĶ���v
Status deleteVex(MGraph *g,VertexType v)
{
	//��ɾ��������
	int k = locateVex(*g,v);
	//�����ڶ���v
	if (k < 0)
	{
		return ERROR;
	}
	//ɾ���ɶ���v���������бߣ�����
	for (int i = 0; i < g->vexnum; i++)
	{
		deleteArc(g,v,g->vexs[i]);
	}
	//����
	if (g->kind < 2)
	{
		//ɾ�����򶥵�v�����л�
		for (int i = 0; i < g->vexnum; i++)
		{
			deleteArc(g,g->vexs[i],v);
		}
	}
	//����v����Ķ�����ǰ��
	for (int j = k+1; j < g->vexnum; j++)
	{
		g->vexs[j-1] = g->vexs[j];
	}
	for (int i = 0; i < g->vexnum; i++)
	{
		for (int j = k+1; j < g->vexnum; j++)
		{
			//�ƶ���ɾ������v�ұߵľ���Ԫ��
			g->arcs[i][j-1] = g->arcs[i][j];
			//�ƶ���ɾ������v�±ߵľ���Ԫ��
			g->arcs[j-1][i] = g->arcs[j][i];
		}
	}
	//��������1
	g->vexnum--;
	return OK;
}



Status deleteArc(MGraph *g,VertexType v,VertexType w)
{
	int v1 = locateVex(*g,v);
	int w1 = locateVex(*g,w);
	//�����ڶ���v1��w1
	if (v1 < 0 || w1 < 0)
	{
		return ERROR;
	}
	VRType j = 0;
	//��
	if (g->kind%2)
	{
		j = INFINITY;
	}
	//���ڻ����ߣ�
	if (g->arcs[v1][w1].adj != j)
	{
		//ɾ����<w,v>
		g->arcs[v1][w1].adj = j;
		//�л����ߣ�����Ϣ
		if (g->arcs[v1][w1].info)
		{
			//�ͷ���Ϣָ��
			free(g->arcs[v1][w1].info);
			//����Ϣָ����Ϊ��
			g->arcs[v1][w1].info = NULL;
		}
		//����ɾ���Գƻ����ߣ�<w,v>
		if (g->kind>1)
		{
			g->arcs[w1][v1] = g->arcs[v1][w1];
		}
		g->arcnum--;
		return OK;
	}
	return ERROR;
}



void destroyGraph(MGraph *g)
{
	for (int i = g->vexnum-1; i >= 0; i--)
	{
		deleteVex(g,g->vexs[i]);
	}
}



void inputArc(InfoType **info)
{
	char s[MAX_INFO];
	printf_s("������û��������Ϣ(<%d���ַ�)��",MAX_INFO);
	gets_s(s);
	int m = strlen(s);
	if (m)
	{
		*info = (InfoType *)malloc(MAX_INFO*sizeof(char));
		strcpy_s((**info).info,s);
	}
}



void outputArc(InfoType info)
{
	printf_s("%s",info.info);
}



void visit(VertexType vex)
{
	printf_s("%s",vex.name);
}



void inputVex(VertexType *vex)
{
	scanf_s("%s",vex->name);
}



void display(MGraph g)
{

}



