#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>

//1 <= N <= 10^8
//The answer is guaranteed to exist and be less than 2 * 10^8.

bool isprime(int N) ;
bool isPalindromeNumber(int N) ;


//a = a++;
//(++i) + (++i) + (++i)
int primePalindrome(int N) {
	double a = 10;
	double x = 8;
	if (0 == N%2)
	{
		for (int i = N; i <= 2 * pow(a,x);i=i+1)
		{
			if (isPalindromeNumber(i) &&  isprime(i))
			{
				return 1 == i?2:i;
			}
			printf_s("--->i:%d\n",i);
		}
	}else
	{
		for (int i = N; i <= 2 * pow(a,x);1 == i?i=i+1:i=i+2)
		{
			if (isPalindromeNumber(i) &&  isprime(i))
			{
				return 1 == i?2:i;
			}
			printf_s("--->i:%d\n",i);
		}
	}
	//printf_s("\n\n");
	return -1;
}



bool isprime(int N) 
{
	 if (N <= 3) 
	 {
		return N > 1;
	 }
	 if (N % 6 != 1 && N % 6 != 5) 
	 {
        return false;
	 }
	double x = N;
	/*for (int i = 2; i <= sqrt(x);i=i+1)
	{
		if (0 == N%i)
		{
			return false;
		}
	}*/
	for (int i = 5; i <= sqrt(x); i += 6)
	{
		if (N % i == 0 || N % (i + 2) == 0) 
		{
            return false;
        }
    }
	return true;
}



bool isPalindromeNumber(int N) 
{
	char str[15];
	sprintf_s(str, "%d", N); 
	int len = strlen(str);
	for (int i = 0; i < len/2; i=i+1)
	{
		if (str[i] != str[len-i-1])
		{
			return false;
		}
	}
	return true;
}