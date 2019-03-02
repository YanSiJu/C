//A + B Problem II
//Sample Input
//2
//1 2
//112233445566778899 998877665544332211


//Sample Output
//Case 1:
//1 + 2 = 3
//
//Case 2:
//112233445566778899 + 998877665544332211 = 1111111111111111110



#include"List.h"

int getSum(int x,int y);
void sum();

void sum()
{
	int n,count = 1;
	int x = 0,y = 0;
	LinkedList head = NULL,tail = NULL,p = NULL;
	scanf_s("%d",&n);
	while (n-->0)
	{
		scanf_s("%d",&x);
		scanf_s("%d",&y);
		insertElem(&head,&tail,x,y);
	}
	p = head;
	//count = 1;
	while (NULL != p)
	{
		printf_s("case:%d\n",count++);
		printf_s("%d\n\n",getSum(p->a,p->b));
		p = p->next;
	}
}



int getSum(int x,int y)
{
	
	return x+y;
}