// Leetcode.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
//#include"reverseInteger.h"
//#include"LongestSubstring.h"
//#include<stdlib.h>
//#include"SearchInsertPosition.h"
//#include"LongestCommonPrefix.h"
//#include"PalindromeNumber.h"
//#include"125-ValidPalindrome.h"
//#include"206-ReverseLinkedList.h"
//#include"234-PalindromeLinkedList.h"
//#include"680-ValidPalindromeII.h"
#include"866-PrimePalindrome.h"
#include<stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{
	system("title Leetcode");
	//double x = 2,y=31;
	//-2147483648
	//printf_s("%f\n\n",pow(x,y));
	//printf_s("%d\n\n",1534236469>INT_MAX);
	//printf_s("%d\n\n",9646324351>pow(x,y));
//	printf_s("INT_MAX:%d\n\n",INT_MAX);
	//x = -2;
	//printf_s("%f\n\n",pow(x,y));


	/*printf_s("342:%d\n",reverse(342));
	printf_s("123:%d\n",reverse(123));
	printf_s("120:%d\n",reverse(120));
	printf_s("-342:%d\n",reverse(-342));
	printf_s("-123:%d\n",reverse(-123));
	printf_s("-120:%d\n",reverse(-120));*/

	  /*char  num = 'a';
    char str[25];
    sprintf_s(str, "%s%d" , num);
   printf ("The number 'num' is %d and the string 'str' is %s. \n" ,
                          num, str);*/

	//lengthOfLongestSubstring("bbbbb");
//	Example 1:
//
//Input: [1,3,5,6], 5
//Output: 2
	/*int nums[] = {1,3,5,6};
	int numSize = sizeof(nums)/sizeof(nums[0]);
	int target = 5;
	printf_s("[1,3,5,6], 5:%d\n",searchInsert(nums,numSize,target));

	target = 2;
	printf_s("[1,3,5,6], 2:%d\n",searchInsert(nums,numSize,target));

	target = 7;
	printf_s("[1,3,5,6], 7:%d\n",searchInsert(nums,numSize,target));

	target = 0;
	printf_s("[1,3,5,6], 0:%d\n",searchInsert(nums,numSize,target));*/

	//char *strs[] = {"flower","flow","floight"};
	//char *strs[] = {"dog","racecar","car"};
	//char *ptr=(char *)malloc(4*sizeof(char));
	//if (!ptr)
	//{
	//	printf("Allocation Falure!\n");
	//	exit(0);
	//}
	//printf("%s",ptr);
	//char *new_ptr=(char*)realloc(ptr,100*sizeof(char));
	//printf("The address get by realloc is : %p\n",new_ptr);
	//char *s = longestCommonPrefix(strs, 3);
	//int len = sizeof(s)/sizeof(s[0]);
	/*int len = sizeof(s)/sizeof(s[0]);
	printf("The longest Common  Prefix is : %s  %d\n",s,len);*/

	/*char str[] = "123c@#FDsP[e?";
	for (int i = 0; str[i] != 0; i++)
	{
		if(isdigit(str[i]))
            printf("%c is an digit character\n", str[i]);
		if(isalpha(str[i]))
            printf("%c is an alphanumeric character\n", str[i]);
	}*/
        


	/*int num = 1840;
	char str[100];
	sprintf_s(str, "%d", 123); 
	printf("str:%s\n", str);
	printf("%d\n", INT_MAX);*/
	//printf_s("--->%p\n",nullptr);
	/*printf_s("isPalindrome(\"A man, a plan, a canal: Panama\"):%d\n\n", isPalindrome("A man, a plan, a canal: Panama"));
	printf_s("isPalindrome(\"race a car\"):%d\n\n", isPalindrome("race a car"));
	printf_s("isPalindrome(\" \"):%d\n\n", isPalindrome(" "));
	printf_s("isPalindrome(\"\"):%d\n\n", isPalindrome(""));
	printf_s("isPalindrome(\"0P\"):%d\n\n", isPalindrome("0P"));*/
	//printf_s("isPalindrome(\" \"):%d\n\n", isPalindrome(" "));
	/*printf_s("isPalindrome(222):%d\n\n", isPalindrome(222));
	printf_s("isPalindrome(2222):%d\n\n", isPalindrome(2222));
	printf_s("isPalindrome(12321):%d\n\n", isPalindrome(12321));
	printf_s("isPalindrome(-2222):%d\n\n", isPalindrome(-2222));
	printf_s("isPalindrome(-12321):%d\n\n", isPalindrome(-12321));
	printf_s("isPalindrome(-121):%d\n\n", isPalindrome(-121));
	printf_s("isPalindrome(10):%d\n\n", isPalindrome(10));*/

	/*struct ListNode *head = NULL;
	struct ListNode *tail = NULL;
	createListF(&head,&tail,5);
	printf_s("head:%p  val:%d  next:%p\n\n",head,head->val,head->next);
	listTraverse(head);
	listTraverse(reverseList(head));*/

	/*struct ListNode *head = NULL;*/
	/*struct ListNode *tail = NULL;*/
	/*createListF(&head,&tail,5);*/
	/*insertElem(&head,1,1);
	insertElem(&head,1,2);
	insertElem(&head,1,2);
	insertElem(&head,1,2);
	insertElem(&head,1,1);
	printf_s("List Traverse:");
	listTraverse(head);
	printf_s("isPalindrome(head):%d\n",isPalindrome(head));

	printf_s("\n\n");
	head = NULL;
	insertElem(&head,1,1);
	insertElem(&head,1,2);
	insertElem(&head,1,2);
	insertElem(&head,1,2);
	insertElem(&head,1,3);
	printf_s("List Traverse:");
	listTraverse(head);
	printf_s("isPalindrome(head):%d\n",isPalindrome(head));*/


	/*char *s = "abbfa";
	printf_s("s:%s    validPalindrome(s):%d\n\n",s,validPalindrome(s));

	s = "deeee";
	printf_s("s:%s    validPalindrome(s):%d\n\n",s,validPalindrome(s));

	s = "abca";
	printf_s("s:%s    validPalindrome(s):%d\n\n",s,validPalindrome(s));

	s = "acbba";
	printf_s("s:%s    validPalindrome(s):%d\n\n",s,validPalindrome(s));

	s = "abad";
	printf_s("s:%s    validPalindrome(s):%d\n\n",s,validPalindrome(s));

	s = "abadc";
	printf_s("s:%s    validPalindrome(s):%d\n\n",s,validPalindrome(s));

	s = "ebcbbececabbacecbbcbe";
	printf_s("s:%s    validPalindrome(s):%d\n\n",s,validPalindrome(s));

	s = "aba";
	printf_s("s:%s    validPalindrome(%s):%d\n\n",s,s,validPalindrome(s));*/
	
	int n = 6;
	printf_s("n:%d    validPalindrome(%d):%d\n\n",n,n,primePalindrome(n));

	n = 8;
	printf_s("n:%d    validPalindrome(%d):%d\n\n",n,n,primePalindrome(n));

	n = 13;
	printf_s("n:%d    validPalindrome(%d):%d\n\n",n,n,primePalindrome(n));

	n = 2;
	printf_s("n:%d    validPalindrome(%d):%d\n\n",n,n,primePalindrome(n));

	n = 1;
	printf_s("n:%d    validPalindrome(%d):%d\n\n",n,n,primePalindrome(n));


	n = 4;
	printf_s("n:%d    validPalindrome(%d):%d\n\n",n,n,primePalindrome(n));
	


	 n = 9989900;
	 /*100031000*/
	printf_s("n:%d    validPalindrome(%d):%d\n\n",n,n,primePalindrome(n));

	system("pause");
	return 0;
}