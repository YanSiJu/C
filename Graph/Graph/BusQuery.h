#include"AllPaths.h"
#include"Bus.h"
#include"Strategy.h"

Strategy*  getStrategies(MGraph stations,Bus buses[],char start[],char end[]);

Strategy*  getStrategies(MGraph stations,Bus buses[],char start[],char end[])
{
	Strategy *strategies = NULL;
	VertexType v;
	strcpy_s(v.name,start);
	VertexType w;
	strcpy_s(w.name,end);
	int m = locateVex(stations,v);
	int n = locateVex(stations,w);
	if (-1 == m || -1 == n)
	{
		return;
	}
	LinkedList paths = NULL;
	getPaths(stations,m,n,&paths);
	return strategies;
}