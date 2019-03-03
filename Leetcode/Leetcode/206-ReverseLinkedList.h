#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};


//int insertElem(struct ListNode ** head,int locate,int e);
int  createListF(struct ListNode **head,struct ListNode **tail,int len);
int length(struct ListNode *head);
void listTraverse(struct ListNode *head);
void visit(struct ListNode *p);


struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode  *p = head;
	struct ListNode  *pnew;
	struct ListNode  *phead = NULL;
	while (NULL != p)
	{
		pnew = (struct ListNode *)malloc(sizeof(struct ListNode));
		if (!pnew)
		{
			exit(0);
		}
		pnew->val = p->val;
		pnew->next =  NULL;
		if (NULL == phead)
		{
			phead = pnew;
		}else
		{
			pnew->next = phead;
			phead = pnew;
		}
		p = p->next;
	}
	return phead;
}


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
		//printf_s("data:%d  %d\n",data,NULL == (*head));
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
			//printf_s("(*head)->next----->%d\n",(*head)->next);
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
		//printf_s("p--->%p\n",p);
	}
	/*printf_s("\n\n\n\n----->%d ",p->val);	*/
	printf_s("\n");
}



void visit(struct ListNode *p)
{
	printf_s("%d ",p->val);		
}