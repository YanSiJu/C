// Leetcode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include"reverseInteger.h"
//#include"LongestSubstring.h"
#include<stdlib.h>
//#include"SearchInsertPosition.h"
#include"LongestCommonPrefix.h"

int _tmain(int argc, _TCHAR* argv[])
{
	system("title reverse");
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

	char *strs[] = {"flower","flow","floight"};
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
	char *s = longestCommonPrefix(strs, 3);
	//int len = sizeof(s)/sizeof(s[0]);
	int len = sizeof(s)/sizeof(s[0]);
	printf("The longest Common  Prefix is : %s  %d\n",s,len);
	system("pause");
	return 0;
}