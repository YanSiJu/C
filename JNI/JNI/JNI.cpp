
#include "com_ghgame_javausecpp_JavaUseCpp.h"

JNIEXPORT void JNICALL Java_com_ghgame_javausecpp_JavaUseCpp_printStr(JNIEnv* env, jobject obj, jstring str)
{
	const char* pTempStr = env->GetStringUTFChars(str, NULL);  
	char *s = "Daimler and  Mercedes Benz";
	printf("---->s:%s\n",s);
	printf(">>>>>>>>>>>>>>>The input string is = [ %s ]<<<<<<<<<<<<<<",pTempStr);
}


JNIEXPORT jdouble JNICALL Java_com_ghgame_javausecpp_JavaUseCpp_average
	(JNIEnv *, jobject, jint a, jint b){
		jdouble result;
   //cout << "In C++, the numbers are " << a << " and " << b << endl;
   printf("In C, the numbers are  %d and %d\n",a,b);
   result = ((jdouble)a + b) / 2.0;
   // jint is mapped to int, jdouble is mapped to double
   return result;
}