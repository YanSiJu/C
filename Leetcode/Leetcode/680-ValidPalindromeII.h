#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"PalindromeString.h"

bool validPalindrome(char* s) {
	int len = strlen(s);
	for (int i = 0; i < len/2;i++)
	{
		if (s[i] != s[len-(i+1)])
		{
			char *str = (char *)malloc(len*sizeof(char));
			if (!str)
			{
				exit(0);
			}
			/*ɾ��s[len-(i+1)]*/
			for (int j = 0; j <= len-i-2; j++)
			{
				str[j] = s[j];
			}
			for (int j = len-(i+1); j < len; j++)
			{
				str[j] = s[j+1];
			}
			if (isPalindrome(str))
			{
				printf_s("str:%s\n",str);
				return true;
			}
			//ɾ��s[i]
			for (int j = 0; j <= i-1;j++)
			{
				str[j] = s[j];
			}
			for (int j = i; j < len; j++)
			{
				str[j] = s[j+1];
			}
			printf_s("str:%s\n",str);
			return isPalindrome(str);
		}
	}
	return true;
}