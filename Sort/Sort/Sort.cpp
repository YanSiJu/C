// Sort.cpp : �������̨Ӧ�ó������ڵ㡣
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
		printf_s("����ǰ��\n");
		printArray(a,N);
		//insertSort(a,N,compare);
		//selectSort(a,N,compare);
		//quickSort(a,N);
		bubbleSort(a,N,compare);
		printf_s("�����\n");
		printArray(a,N);
	}

	system("pause");
	return 0;
}

