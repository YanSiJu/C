#include<iostream>
#include<stdlib.h>
int main()
        {
            int a[8]={25,48,32,85,64,18,48,29};
            int max,min;
            max=min=a[0];
            for(int i=0; i<8; i++) {
                if(max<a[i]) max=a[i];
                 if(min>a[i]) min=a[i];
            }
            std::cout<<"max:"<<max<<std::endl;
            std::cout<<"min:"<<min<<std::endl;
            return 0;
        }
