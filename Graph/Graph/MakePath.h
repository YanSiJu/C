 #ifndef HEAD_H_ 
#define HEAD_H_

void MakePath(MGraph g,bool p[],int i,int j);

//����ͼG�����[i]���յ�[j]�����·����;�������Ķ���
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
				//��Сֵ������Ÿ���minNum
				minNum = k;
				min = g.arcs[begin][k].adj;
			}
		}
		//���[i]���յ�[j]֮��û��ͨ·
		if (INFINITY == min)
		{
			//����whileѭ��
			break;
		}
		printf_s("%s",g.vexs[minNum].name);
		//minNum�����յ�
		if (minNum != j)
		{
			printf_s("->");
		}
		//����·��������������[minNum]��
		p[minNum] = false;
		//�������Ķ��㸳ֵ��begin����Ϊ��ǰ�����������
		begin = minNum;
	}
	printf_s("\n");
}

#endif