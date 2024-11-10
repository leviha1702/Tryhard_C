#include<stdio.h>
int x_n(int n);
int y_n(int n);
int main(){
    int n;
    printf("nhap n:");
    scanf("%d", &n);
    printf("\nx_n co gia tri bang khi n=%d:%d",n,x_n(n));
    printf("\ny_n co gia tri bang khi n=%d:%d",n,y_n(n));
}
int x_n(int n){
    if(n==0) return 1;
    return 2 * x_n(n-1)+ 3 * y_n(n-1);
}
int y_n(int n){
    if(n==0) return 1;
    return 3 * x_n(n-1)- 2* y_n(n-1);
}