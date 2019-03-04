#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct ListNode {
	int val;
	struct ListNode *next;
};


int  createListF(struct ListNode **head,struct ListNode **tail,int len);
int  insertElem(struct ListNode **head,int locate,int e);
int length(struct ListNode *head);
void listTraverse(struct ListNode *head);
void visit(struct ListNode *p);



int length(struct ListNode *head)
{
    struct ListNode *p = head;
    int count = 0;
    while(p)
    {
        p = p->next;
        count++;
    }
    return count;
}

int  createListF(struct ListNode **head,struct ListNode **tail,int len)
{
	struct ListNode * p = NULL;
	int data;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
	{
		data = rand()%100+1;
		if (NULL == (*head))
		{
			struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
			if (!q)
			{
				return -1;
			}
			*head = q;
			(*head)->val = data;
			(*head)->next =  NULL;
			*tail = *head;
		}else
		{
			/*此处可传入函数指针，调用函数完成操作*/
			p = (struct ListNode *)malloc(sizeof(struct ListNode));
			if (!p)
			{
				return -1;
			}
			p->val = data;
			p->next = *head;
			*head = p;
		}
	}
	return 1;
}



void listTraverse(struct ListNode *head)
{
	struct ListNode * p = head;
	while (NULL != p)
	{
		visit(p);
		p = p->next;
	}
	printf_s("\n");
}

int  insertElem(struct ListNode **head,int locate,int e)
{
	int count = 1;
	struct ListNode * p = *head;
	struct ListNode * pnew = NULL;
	if (locate < 1 || locate > length(*head)+1)
	{
		return -1;
	}
	if (1 == locate)
	{
		pnew = (struct ListNode *)malloc(sizeof(struct ListNode));
		if (!pnew)
		{
			return -1;
		}
		pnew->val = e;
		pnew->next = *head;
		*head = pnew;
		return 1;
	}
	while (p && count < locate-1)
	{
		p = p->next;
		count++;
	}
	if (!p || count > locate-1)
	{
		return -1;
	}
	pnew = (struct ListNode *)malloc(sizeof(struct ListNode));
	if (!pnew)
	{
		return -1;
	}
	pnew->val = e;
	pnew->next = p->next;
	p->next = pnew;
	return 1;
}


void visit(struct ListNode *p)
{
	printf_s("%d ",p->val);		
}