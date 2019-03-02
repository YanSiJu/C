#include"LinkList.h"


int f(int a,int b,int n);

void calc()
{
	int a;
	int b;
	int n;
	scanf_s("%d%d%d",&a,&b,&n);
	LinkedList head = NULL,tail = NULL;
	while (!(0 == a && 0 == b && 0 == n))
	{
		int result = f(a,b,n);
		insertElem(&head,&tail,result);
		scanf_s("%d%d%d",&a,&b,&n);
	}
	LinkedList p = head;
	while (NULL != p)
	{
		printf_s("%d\n",p->data);
		p = p->next;
	}
}


int f(int a,int b,int n)
{
	//f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
	int *arr = (int *)malloc(sizeof(int)*n);
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < n; i++)
	{
		arr[i] = (a * arr[i-1] + b * arr[i-2]) % 7;
	}
}