#include<stdlib.h>
#include<string.h>
#include<stdio.h>

bool isPalindrome(int x) {
	if (x < 0)
	{
		return false;
	}
	char str[10];
	//_itoa(x, str, 10);      //������10ת��Ϊʮ���Ʊ�����str�ַ�������
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