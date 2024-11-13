#include<stdio.h>
#include<stdlib.h>
#define MAX 50
void readFile(int a[],int &n){
    FILE*f=fopen("Lap3_1.inp","r");
    if(f==NULL){
        printf("khong the truy cap file!\n");
        return;
    }
    fscanf(f,"%d",&n);
    printf("so luong phan tu trong mang :%d\n",n);
    printf("cac phan tu trong mang:\n");
    for (int i = 0; i < n; i++){
        fscanf(f,"%d",&a[i]);
        printf("%d ",a[i]);
    }
    fclose(f);
}
//số lớn nhất trong mảng vòng lặp
int findNumMax(int a[],int n){
    int max=a[0];
    for (int i = 0; i < n; i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}
int main(){
    int a[MAX],n;
    readFile(a,n);
    printf("so lon nhat trong mang tren:%d",findNumMax(a,n));
}