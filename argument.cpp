#include<stdio.h>
#include<stdlib.h>
int main(int argc,char*argv[]){
    int dem=0;
    if (argc>=2)
    {
        for (int i = 0; i < argc; i++)
        {
            if(atoi(argv[i])%2!=0) dem++;
        }
    }
    printf("DemLe:%d",dem);
}