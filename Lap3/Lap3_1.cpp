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
//tìm số lớn nhất bằng đệ quy
int findNumMax2(int a[],int n){
    if(n==1) return a[n-1];
    int m=a[n-1];
    if(a[n-1]<findNumMax2(a,n-1)) {
        m=findNumMax2(a,n-1);
    }
    return m;
}
//tính tổng phần tử của mảng a(dùng đệ quy đầu)
int sum1(int a[],int n){
    if(n==1) return a[n-1];
    else return a[n-1]+sum1(a,n-1);
}
////tính tổng phần tử của mảng a(dùng đệ quy đuôi)
int sum2(int a[],int n,int s,int i){
    if(i>=n) return s;
    else return sum2(a,n-1,s+a[i],i+1);
}
int main(){
    int a[MAX],n;
    readFile(a,n);
    printf("\nso lon nhat trong mang tren:%d(vong lap)",findNumMax(a,n));
    printf("\nso lon nhat trong mang tren:%d(de quy)",findNumMax2(a,n));
    printf("\ntong cac phan tu trong mang a:%d(de quy dau)",sum1(a,n));
    printf("\ntong cac phan tu trong mang a:%d(de quy duoi)",sum1(a,n));
}