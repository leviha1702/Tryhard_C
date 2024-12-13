#include<stdio.h>
#define MAX 50

int f[MAX];
int n;

int fibo(){
    if(n==1&&n==0) return 1;
    else{
        f[0]=1;
        f[1]=1;
        for(int i=2;i<=n;i++){
            f[i]=f[i-1]+f[i-2];
        }
        return f[n];
    }
}
int main(){
    printf("nhap vao so n:");
    scanf("%d",&n);
    printf("so Fibonancci thu n:%d",fibo());
}