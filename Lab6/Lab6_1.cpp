#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//đọc file
void readFile(int a[],int &n){
    FILE *f=fopen("Lab6_1.inp","r");
    if(f==NULL){
        printf("khong the mo file!");
        return;
    }
    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++){
        fscanf(f,"%d",&a[i]);
    }
}

//in file
void printfFile(int a[],int n){
    printf("so luong phan tu trong mang:%d\n",n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

//đếm số lượng số nguyên âm nằm ở vị trí lẻ (đệ quy)
int demAmVTLe(int a[],int n){
    if(n==0) return 0;
    if((n-1)%2!=0&&a[n-1]<0) return demAmVTLe(a,n-1)+1;
    else return demAmVTLe(a,n-1);
}

//kiểm tra có phải toàn là số lẻ không(đệ quy)
int checkLeAll(int a[],int n){
    if(n==0) return 0;
    if(a[n-1]%2!=0) return checkLeAll(a,n-1)+1;
    else return 0;
}
int main(){
    int a[MAX],n;
    readFile(a,n);
    printfFile(a,n);

    if(demAmVTLe(a,n)){
        printf("so luong phan tu am o vi tri le:%d\n",demAmVTLe(a,n));
    }else printf("khong co so am o vi tri le!\n");

    if(checkLeAll(a,n)!=0){
        printf("tat ca phan tu trong mang deu le!\n");
    }else printf("co so chan trong mang!\n");
    
}