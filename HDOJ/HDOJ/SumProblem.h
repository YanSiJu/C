#include"LinkList.h"

int getSum(int x);
void sum();

void sum()
{
	int n,count;
	int x = 0;
	LinkedList head = NULL,tail = NULL,p = NULL;
	scanf_s("%d",&n);
	count = n;
	while (count-->0)
	{
		scanf_s("%d",&x);
		insertElem(&head,&tail,x);
	}
	p = head;
	//printf_s("%d\n",getSum(p->data));
	printf_s("\n%d\n\n",n);
	while (NULL != p)
	{
//		printf_s("p->data:%d\n\n",p->data);
		printf_s("%d\n",getSum(p->data));
		p = p->next;
	}
}



int getSum(int x)
{
	int count = 1;
	int sum = 0;
	while (count<=x)
	{
		sum += count;
		count++;
	}
	return sum;
}