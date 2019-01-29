// Stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"stack.h"
#define N 10



int _tmain(int argc, _TCHAR* argv[])
{
	system("title 栈");


	stack s;
	s.base = s.top = NULL;
	s.stackSize = 0;
	initStack(&s);
	printf_s("初始化栈后，s.top:%p s.base:%p  s.stackSize:%d\n",s.top,s.base,s.stackSize);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++)
	{
		push(&s,rand()%100+1);
	}
	stackTraverse(s);
	printf_s("栈空否？(0否 1是):%d   栈的长度：%d\n",stackEmpty(s),stackLength(s));
	SElemType e;
	getTop(s,&e);
	printf_s("栈顶元素：%d\n",e);
	pop(&s,&e);
	printf_s("出栈的栈顶元素：%d\n",e);
	stackTraverse(s);
	clearStack(&s);
	printf_s("清空栈后，s.top:%p  s.base:%p  栈空否？(0否 1是):%d   栈的长度：%d\n",s.top,s.base,stackEmpty(s),stackLength(s));
	destroyStack(&s);
	printf_s("销毁栈后，s.top:%p  s.base:%p  栈空否？(0否 1是):%d   栈的长度：%d\n",s.top,s.base,stackEmpty(s),stackLength(s));


	printf_s("\n\n重新初始化栈......\n");
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