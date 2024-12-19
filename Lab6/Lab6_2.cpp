#include<stdio.h>
#define MAX 50

int n,k;
int x[MAX];
int check=0;

int count(){
    int count=0;
    for(int i=1;i<=n;i++){
        count+=x[i];
    }
    return count;
}

void Print(){
    if(count()==k){
        check++;
        for(int j=1;j<=n;j++){
            printf("%d",x[j]);
        }
        printf("\n");
    }
}
void Try(int i){
    for(int j=0;j<=1;j++){
        x[i]=j;
        if(i==n){
            Print();
        }
        else Try(i+1);
    }
}
int main(){
    printf("nhap chuoi dai chuoi nhi phan:");
    scanf("%d",&n);
    printf("nhap vao so ky tu 1:");
    scanf("%d",&k);
    Try(1);
    if (check==0)
    {
        printf("khong co dap an!");
    }
}