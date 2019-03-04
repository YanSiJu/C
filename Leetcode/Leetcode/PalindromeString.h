#include<string.h>

//判断字符串s是否为回文串
//是回文串则返回true
//否则返回false
bool isPalindrome(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < len/2; i++)
	{
		if (s[i] != s[len-(i+1)])
		{
			return false;
		}
	}
	return true;
}