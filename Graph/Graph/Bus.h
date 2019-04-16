#define MAX_BUS_NAME 10

typedef struct Bus
{
	//公交车id
	int id;
	//公交车名字
	char name[MAX_BUS_NAME];
	//经过的站点数
	int stationNum;
	//存储其经过的站点id，站点在数组中的位置即为其在线路中的位置
	int *stations;
}Bus;