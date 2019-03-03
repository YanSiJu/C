#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

bool isPalindrome(char* s) {
	int len = strlen(s);
	if (0 == len || 1 == len)
	{
		return true;
	}
	for (int low = 0,high=len-1; low <= high; low++,high--)
	{
		while (!(isdigit(s[low]) || isalpha(s[low])))
		{
			low++;
			if (!(low <= high))
			{
				return true;
			}
		}
		while (!(isdigit(s[high]) || isalpha(s[high])))
		{
			high--;
			if (!(low <= high))
			{
				return true;
			}
		}
		int n =  abs(s[low] -  s[high]);
		if (low > high)
		{
			return false;
		}
		if ((isalpha(s[low]) && isdigit(s[high]))  ||  (isalpha(s[high]) && isdigit(s[low])))
		{
			return false;
		}
		if (s[low]!= s[high] && 32 != n)
		{
			return false;
		}
	}
	return true;
}