#include<stdio.h>
//Câu a
int S1(int a,int n){//đệ quy
    if(n==1) return a;
    else return a*S1(a,n-1);
}
int S2(int a,int n){//vòng lặp
    int s=1;
    for(int i=1;i<=n;i++){
        s*=a;
    }
    return s;
}
//câu b
int fibo1(int n){//đệ quy
    if(n<=2) return 1;
    return fibo1(n-1)+fibo1(n-1);
}
int fibo2(int n){//vòng lặp
    int n1=0,n2=1,n3;
    for(int i=0;i<n;i++){
        n3=n1+n2;
        n1=n2;
        n2=n3;
    }
    return n3;
}
int main(){ 
    int a,n;
    printf("nhap gia tri cua a:");
    scanf("%d",&a);
    while(!(n>1&&n<30)){
        printf("nhap gia tri so mu:");
        scanf("%d",&n);
    }
    printf("dap so cau a:%d(de quy)",S1(a,n));
    printf("\ndap so cau a:%d(vong lap)",S2(a,n));
    printf("so fibonanci thu 5:%d(de quy)",fibo1(5));
    printf("so fibonanci thu 7:%d(vong lap)",fibo2(5));
}