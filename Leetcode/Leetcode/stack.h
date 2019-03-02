#include<stdio.h>
#include<stdlib.h>
#include<time.h>



#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2
#define OK 1
#define ERROR -1


typedef long SElemType;
typedef int Status;

typedef struct stack
{
	SElemType *base;
	SElemType *top;
	int stackSize;
}stack;



Status initStack(stack *s);
Status push(stack *s,SElemType e);
Status pop(stack *s,SElemType *e);
Status getTop(stack s,SElemType *e);
Status stackEmpty(stack s);
int stackLength(stack s);
Status destroyStack(stack *s);
void clearStack(stack *s);
void stackTraverse(stack s);
void visit(SElemType e);


Status initStack(stack *s)
{
	(*s).base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!(*s).base)
	{
		return ERROR;
	}
	(*s).top = (*s).base;
	(*s).stackSize = STACK_INIT_SIZE;
	return OK;
}



Status push(stack *s,SElemType e)
{
	if ((*s).top - (*s).base == (*s).stackSize)
	{
		SElemType *newbase = (SElemType *)realloc((*s).base,((*s).stackSize+STACK_INCREMENT)*sizeof(SElemType));
		if (!newbase)
		{
			return ERROR;
		}
		(*s).base = newbase;
		(*s).top = (*s).base + (*s).stackSize;
		(*s).stackSize += STACK_INCREMENT;
	}
	*((*s).top) = e;
	(*s).top++;
	return OK;
}


Status pop(stack *s,SElemType *e)
{
	if (!stackEmpty(*s))
	{
		*e = *(--(*s).top);
		return OK;
	}
	return ERROR;
}



Status getTop(stack s,SElemType *e)
{
	if (!stackEmpty(s))
	{
		*e = *(s.top-1);
	}
	return OK;
}



Status stackEmpty(stack s)
{
	return s.base == s.top;
}



int stackLength(stack s)
{
	int length = 0;
	SElemType *p = s.base;
	while (p != s.top)
	{
		length++;
		p++;
	}
	return length;
}



Status destroyStack(stack *s)
{
	SElemType *p = (*s).base;
	while (p != (*s).top)
	{
		free(p++);
	}
	(*s).base = (*s).top = NULL;
	(*s).stackSize = 0;
	return OK;
}



void clearStack(stack *s)
{
	(*s).top = (*s).base;
}



void stackTraverse(stack s)
{
	SElemType *p = s.base;
	while (p != s.top)
	{
		visit(*p++);
	}
	printf_s("\n");
}



void visit(SElemType e)
{
	printf_s("%d  ",e);
}