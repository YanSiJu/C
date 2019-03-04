#include"List.h"


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