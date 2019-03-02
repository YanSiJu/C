#include<string.h>
#include<stdlib.h>


char* longestCommonPrefix(char** strs, int strsSize) {
	char *prefix=(char *)malloc(1*sizeof(char *));
	if (!prefix)
	{
		exit(0);
	}
	/*for (int i = 0; i < sizeof(prefix)/sizeof(prefix[0]); i++)
	{
		prefix[i] = '\0';
	}*/
	int size = 0;
	int length = sizeof(prefix)/sizeof(prefix[0]);
	printf("%d  \n",length);
	char c;
	int len = strlen(strs[0]);
	for (int i = 0; i < len; i++)
	{
		c = strs[0][i];
		int flag = 0;
		for (int j = 1; j  < strsSize; j ++)
		{
			if (c != strs[j][i])
			{
				flag = 1;
				break;
			}
		}
		if (0 == flag)
		{
			if (size > length)
			{
				char *newString = (char*)realloc(prefix,(sizeof(prefix)/sizeof(prefix[0])+10)*sizeof(char *));
				
				if (!newString)
				{
					exit(0);
				}
				prefix = newString;
				if (newString)
				{
					free(newString);
				}
			}
			prefix[size++] = c;
			prefix[size] = '\0';
			length = sizeof(prefix)/sizeof(prefix[0])+10;
		}else
		{
			return prefix;
		}
	}
}