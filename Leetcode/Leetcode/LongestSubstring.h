#include<string.h>
#include <stdlib.h>


//1.sizeof(s)����
//2.strlen()

int lengthOfLongestSubstring(char* s) {
	char *currentString = "";
	char *subString = "";
	for (int i = 0; i < strlen(s); i++)
	{
		int currentlen =  strlen(currentString);
		int subLen = strlen(subString);
		int flag = 0;
		for (int j = 0; j < currentlen; j++)
		{
			if (currentString[j] == s[i])
			{
				if (currentlen > subLen)
				{
					subString = currentString;
				}
				*currentString = s[i];
				flag = 1;
				break;
			}
		}
		if (0 == flag)
		{

			//��s[i]ƴ�ӵ�currentString
			//strcat(currentString,s[i]);
			char *newString = (char *)realloc(currentString,(strlen(currentString)+10)*sizeof(char));
			//printf_s("currentString:%p\n\n",currentString);
			//if (!newString) {
			//	// ������
			//	continue;
			//}
			//currentString = (char *)newString;
			//currentString[currentlen] = s[i];
			if (NULL != newString)
			{
				free(newString);
			}
		}
	}
	return sizeof(subString)/sizeof(subString[0]);
}