#include<stdio.h>
#include<stdlib.h>
#define MAX 30
void docFile(int a[],int &n,int &s){
    FILE *f=fopen("ATM.inp","r");
    if(f==NULL){
        printf("khong the mo file!");
        return;
    }
    fscanf(f,"%d %d",&n,&s);
    for (int i = 0; i < n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    fclose(f);
}
void xuatFile(int a[],int n,int s){
    printf("\nso to tien:%d",n);
    printf("\ntong so tien:%d",s);
    printf("\ngia tri cac to tien:\n");
    for (int i = 0; i < n; i++)
    {
       printf("%d ",a[i]);
    }
}
int n,s,a[MAX],solution[MAX];
int found = 0 ;
FILE *g;
void backtrack(int i,int current_sum){
    if(current_sum==s){
        found=1;
        for(int j =0; j<i;j++){
            if(solution[j]>0){
                fprintf(g,"%d",solution[j]);
            }
        }
        fprintf(g,"\n");
        return;
    }
    if(current_sum>s||i >=n){
        return;
    }
    for(int j=0;j<=s/a[i];j++){
        solution[i]=j*a[i];
        backtrack(i+1,current_sum+solution[i]);
    }
    solution[i]=0;
}
int main(){
    docFile(a,n,s);
    xuatFile(a,n,s);
}