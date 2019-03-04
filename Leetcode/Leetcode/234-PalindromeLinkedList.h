#include"List.h"

bool isPalindrome(struct ListNode* head) {
	struct ListNode *pnew = NULL;
	struct ListNode *phead = NULL;
	struct ListNode *p = head;
	while (NULL != p)
	{
		pnew = (struct ListNode *)malloc(sizeof(struct ListNode));
		if (!pnew)
		{
			exit(0);
		}
		pnew->next = NULL;
		pnew->val = p->val;
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
	p = head;
	struct ListNode *q = phead;
	while (NULL != p && NULL != q)
	{
		if (p->val != q->val)
		{
			return false;
		}
		p = p->next;
		q = q->next;
	}
	return true;
}