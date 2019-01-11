
#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
        {
            int s=0;
           for(int i=1,s=0;i<20;i++) {
               if(i%2==0 || i%3==0) continue;
               cout<<i<<' ';
               s+=i;
           }
           cout<<s<<endl;
           return 0;

        }
