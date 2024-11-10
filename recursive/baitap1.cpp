#include<stdio.h>
int giaithua(int n);
int x_n(int n);
int main(){
    int n;
    printf("nhap n:");
    scanf("%d", &n);
    printf("x_n co gia tri bang khi n=%d:%d",n,x_n(n));
}
int giaithua(int n){
    if(n==0||n==1) return 1;
    return n*giaithua(n-1);
}
int x_n(int n){
    if(n==0) return 1;
    int result=0;
    for(int i=0;i<n;i++){
        result+=giaithua(n-1)*x_n(i);
    }
    return result;
}