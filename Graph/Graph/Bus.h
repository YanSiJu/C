#define MAX_BUS_NAME 10

typedef struct Bus
{
	//������id
	int id;
	//����������
	char name[MAX_BUS_NAME];
	//������վ����
	int stationNum;
	//�洢�侭����վ��id��վ���������е�λ�ü�Ϊ������·�е�λ��
	int *stations;
}Bus;