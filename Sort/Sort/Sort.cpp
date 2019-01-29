// Sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h"

#define N 13



int _tmain(int argc, _TCHAR* argv[])
{
	int a[N];
	
	srand((unsigned int)time(NULL));
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < N; i++)
		{
			a[i] = rand()%100+1;
		}
		printf_s("排序前：\n");
		printArray(a,N);
		//insertSort(a,N,compare);
		//selectSort(a,N,compare);
		//quickSort(a,N);
		bubbleSort(a,N,compare);
		printf_s("排序后：\n");
		printArray(a,N);
	}

	system("pause");
	return 0;
}

