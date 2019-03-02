#include<stdio.h>
#include<stdlib.h>



typedef struct result
{
	int maxSum;
	int startPosition;
	int endPosition;
}result;


void calcMaxSum(result *rsl,int a[],int len);

void maxSum()
{
	int *a;
	int caseNum;
	int len = 0;
	scanf_s("%d",&caseNum);
	int count = 1;
	result *rsl = (result *)malloc(sizeof(result)*caseNum);

	//初始化数据并将计算结果存入rsl数组
	while (count++ <= caseNum)
	{
		scanf_s("%d",&len);
		a = (int *)malloc(sizeof(int)*len);
		int i;
		for (i = 0; i < len; i++)
		{
			scanf_s("%d",&a[i]);
		}
		calcMaxSum(&rsl[count-1],a,len);
	}

	//输出结果
	for (int i = 0; i < caseNum; i++)
	{
		printf_s("case %d:",i+1);
		printf_s("%d %d %d\n\n",rsl[i].maxSum,rsl[i].startPosition,rsl[i].endPosition);
	}

}


void calcMaxSum(result *rsl,int a[],int len)
{
	int sum = 0;
	int maxSum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += a[i];
		if (sum <= 0)
		{
			if (sum < 0)
			{
				rsl->startPosition = i+1;
			}else
			{
				rsl->startPosition = 0;
			}
			rsl->startPosition = i+1;
		}
		if (sum > maxSum)
		{
			maxSum = sum;
			rsl->endPosition = i;
		}
	}
	rsl->maxSum = maxSum;
}