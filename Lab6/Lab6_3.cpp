#include<stdio.h>
#define MAX 50

int a[]={2,5,7,-2,-6,8};
int n=sizeof(a)/sizeof(a[0]),s;
int x[MAX];
int check=0;

int count(){
    int count=0;
    for(int i=0;i<n;i++){
        if(x[i]==1){
            count+=a[i];
        }
    }
    return count;
}

void Print(){
    if(count()==s){
        check++;
        for(int i=0;i<n;i++){
            printf("%d",x[i]);
        }
        printf("\n");
    }
}
void Try(int i){
    for(int j=0;j<=1;j++){
        x[i]=j;
        if(i==n-1){
            Print();
        }
        else Try(i+1);
    }
}
int main(){
    printf("nhap vao tong:");
    scanf("%d",&s);
    Try(0);
    if (check==0)
    {
        printf("khong co dap an!");
    }
}