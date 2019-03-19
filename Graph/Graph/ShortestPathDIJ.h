


//·�����󣬶�ά����
typedef bool PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//��̾���� һά����
typedef VRType ShortPathTable[MAX_VERTEX_NUM];


void shortestPathDIJ(MGraph g,int v,PathMatrix p,ShortPathTable d);



void shortestPathDIJ(MGraph g,int u,PathMatrix p,ShortPathTable D)
{
	VRType min;
	//��������
	bool final[MAX_VERTEX_NUM];
	for (int v = 0; v < g.vexnum; v++)
	{
		final[v] = false;
		//D[]���u��v����̾��룬��ֵΪu��v��ֱ�Ӿ���
		D[v] = g.arcs[u][v].adj;
		for (int w = 0; w < g.vexnum; w++)
		{
			//��p[][]��ֵΪfalse��û��·��
			p[v][w] = false;
		}
		//u��v��ֱ��·��
		if (D[v] < INFINITY)
		{
			p[v][u] = p[v][v] = true;
		}
	}
	int v = 0;
	//u��u����Ϊ0
	D[u] = 0;
	//��u����s��
	final[u] = true;
	//��ѭ������������g.vexnum-1�����㣬ÿ�����u��ĳ������v����̾��룬��������v����S��
	for (int i = 1; i < g.vexnum; i++)
	{
		min = INFINITY;
		for (int w = 0; w < g.vexnum; w++)
		{
			if (!final[w] && D[w] < min)
			{
				v = w;
				min = D[w];
			}
		}
		//��v����s��
		final[v] = true;
		//�����²���Ķ��㣬���²���s���Ķ��㵽u�ľ����·������
		for (int w = 0; w < g.vexnum; w++)
		{
			//w������s������u->v->w�ľ��� < Ŀǰu->...w�ľ���
			//min����u��v�ľ���
			if (!final[w] && g.arcs[v][w].adj < INFINITY 
				&& min < INFINITY && g.arcs[v][w].adj + min < D[w])
			{
				D[w] = g.arcs[v][w].adj + min;
				//���´�u��w��·��
				for (int j = 0; j < g.vexnum; j++)
				{
					//�޸�p[w]����u��w�����Ķ��������u��v���������ж������w
					p[w][j] = p[v][j];
				}
				p[w][w] = true;
			}
		}
	}

}