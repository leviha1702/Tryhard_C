#include<stdio.h>
#include<stdlib.h>
#define MAX 50
void docFile(int a[],int &n,int &s){
    FILE *f=fopen("ATM.inp","r");
    if(f==NULL){
        printf("khong the mo file!");
        return;
    }
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&s);
    for (int i = 0; i < n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    fclose(f);
}
void xuatFile(int a[],int n,int s){
    printf("\nso to tien:%d",n);
    printf("\ntong so tien:%d");
    printf("\ngia tri cac to tien:\n");
    for (int i = 0; i < n; i++)
    {
       printf("%d ",a[i]);
    }
}
int main(){
    int a[MAX],n,s;
    docFile(a,n,s);
    xuatFile(a,n,s);
}