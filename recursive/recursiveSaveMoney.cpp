#include<stdio.h>
float money(float x,int n,float a,int b){
    if(n==0) return x;
    float x_new=x*(1+a/100);
    if(n%10==0) return money(x_new,n-1,a,b)+b;
    else return money(x_new,n-1,a,b);
}
int main(){
    float x=1000000,a=5;
    int n=3,b=50000;
    float S=money(x,n,a,b);
    printf("tien trong tai khoan sau 15 nam:%.2f",S);
}