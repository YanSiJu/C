// Stack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"stack.h"
#define N 10



int _tmain(int argc, _TCHAR* argv[])
{
	system("title ջ");


	stack s;
	s.base = s.top = NULL;
	s.stackSize = 0;
	initStack(&s);
	printf_s("��ʼ��ջ��s.top:%p s.base:%p  s.stackSize:%d\n",s.top,s.base,s.stackSize);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++)
	{
		push(&s,rand()%100+1);
	}
	stackTraverse(s);
	printf_s("ջ�շ�(0�� 1��):%d   ջ�ĳ��ȣ�%d\n",stackEmpty(s),stackLength(s));
	SElemType e;
	getTop(s,&e);
	printf_s("ջ��Ԫ�أ�%d\n",e);
	pop(&s,&e);
	printf_s("��ջ��ջ��Ԫ�أ�%d\n",e);
	stackTraverse(s);
	clearStack(&s);
	printf_s("���ջ��s.top:%p  s.base:%p  ջ�շ�(0�� 1��):%d   ջ�ĳ��ȣ�%d\n",s.top,s.base,stackEmpty(s),stackLength(s));
	destroyStack(&s);
	printf_s("����ջ��s.top:%p  s.base:%p  ջ�շ�(0�� 1��):%d   ջ�ĳ��ȣ�%d\n",s.top,s.base,stackEmpty(s),stackLength(s));


	printf_s("\n\n���³�ʼ��ջ......\n");
	initStack(&s);
	for (int i = 0; i < N; i++)
	{
		push(&s,rand()%100+1);
	}
	stackTraverse(s);
	for (int i = 0; i < N; i++)
	{
		pop(&s,&e);
	}
	stackTraverse(s);

	system("pause");
	return 0;
}