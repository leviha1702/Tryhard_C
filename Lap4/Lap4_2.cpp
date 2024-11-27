#include<stdio.h>
#define MAX 100
//hàm tìm phần tử lớn nhất trong mảng
int ptMax(int a[],int l,int r){
    if(l==r) return a[l];
    int m=(l+r)/2;
    return ptMax(a,l,m)>ptMax(a,m+1,r)?ptMax(a,l,m):ptMax(a,m+1,r);
}
int count(int a[],int l,int r,int x){
    if(l==r) {
        if(a[l]==x) return 1;
        else return 0;   
    }
    int m=(l+r)/2;
        return count(a,l,m,x)+count(a,m+1,r,x);
}
int findMax(int a[],int l,int r){
    if(l==r) return a[l];
    int m=(l+r)/2;
    int lMajor= findMax(a,l,m);
    int rMajor = findMax(a,m+1,r);
    int lcount=count(a,l,r,lMajor);
    int rcount=count(a,l,r,rMajor);
    return (lcount >= rcount) ? lMajor : rMajor;
}
int main(){
    int a[MAX],n,x;
    printf("nhap so luong phan tu cua mang :");
    scanf("%d",&n);
    printf("nhap phan tu trong mang tu ban phim:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //cau a
    printf("phan tu lon nhat trong mang:%d",ptMax(a,0,n-1));
    //cau b
    printf("\nnhap gia tri x:");
    scanf("%d",&x);
    printf("so lan x xuat hien:%d",count(a,0,n-1,x));
    //cau c
    printf("\nphan tu co so lan xuat hien nhieu nhat trong mang:%d",findMax(a,0,n-1));
}