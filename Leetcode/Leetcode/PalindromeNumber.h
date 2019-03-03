#include<stdlib.h>
#include<string.h>
#include<stdlib.h>

bool isPalindrome(int x) {
	if (x < 0)
	{
		return false;
	}
	char str[10];
	//_itoa(x, str, 10);      //将整数10转换为十进制保存在str字符数组中
	sprintf_s(str, "%d", x); 
	int len = strlen(str);
	for (int i = 0; i < len/2; i++)
	{
		if (str[i] != str[len-(i+1)])
		{
			return false;
		}
	}
	return true;
}