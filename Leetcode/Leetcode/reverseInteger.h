#include"stack.h"
#include<math.h>

// [−2^31,  2^31 − 1]
int reverse(int x) {
	int flag = 1;
	double _x = 2,y=31;
	if (x>=pow(_x,y)-1 || x<=pow(-1*_x,y))
	{
		return 0;
	}
	if (x<0)
	{
		flag = -1;
		x = -1*x;
	}
	long n = 10;
	stack s;
	initStack(&s);
	while (x>0)
	{
		push(&s,x%n);
		x = x/10;
	}
	//stackTraverse(s);
	n = 1;
	long top = 0;
	long reverseInt = 0;
	while (!stackEmpty(s))
	{
		pop(&s,&top);
		reverseInt += top*n;
		n = n*10;
	}
	if (reverseInt>=pow(_x,y)-1)
	{
		return 0;
	}
	return -1 != flag?reverseInt:reverseInt*-1;
}