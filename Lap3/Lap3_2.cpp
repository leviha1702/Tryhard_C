#include<stdio.h>
//Câu a
long long S1(int a,int n){//đệ quy
    if(n==1) return a;
    else return a*S1(a,n-1);
}
long long S2(int a,int n){//vòng lặp
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
//câu c:tháp Hà Nội
void towerHaNoi(int n,char a,char b,char c){
    if(n==1) {
        printf("from %c to %c\n",a,c);
        return;
    }
    towerHaNoi(n-1,a,c,b);
    towerHaNoi(1,a,b,c);
    towerHaNoi(n-1,b,a,c);
}
int main(){ 
    int A,n;
    printf("nhap gia tri cua a:");
    scanf("%d",&A);
    while(!(n>1&&n<30)){
        printf("nhap gia tri so mu:");
        scanf("%d",&n);
    }
    printf("dap so cau a:%d(de quy)",S1(A,n));
    printf("\ndap so cau a:%d(vong lap)\n",S2(A,n));
    printf("so fibonanci thu 5:%d(de quy)\n",fibo1(5));
    printf("so fibonanci thu 7:%d(vong lap)\n",fibo2(5));
    char a='A',b='B', c='C';
    int m;
    printf("nhap chieu cao cua thap:");scanf("%d",&m);
    printf("thap Ha Noi:\n");
    towerHaNoi(m,a,b,c);
}