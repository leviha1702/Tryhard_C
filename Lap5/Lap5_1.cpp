#include<stdio.h>
#define MAX 50
#define SWAP(a,b,c){c=a;a=b;b=c;}

float w[]={5,3,6,4};
float v[]={4,7,10,2};
int n=sizeof(v)/sizeof(v[1]);
float p[MAX];
int x[MAX];
float T,M=9;

void init(){
    T=M;
    //tính đơn giá
    for (int i = 0; i < n; i++)
    {
        p[i]=v[i]/w[i];
    }
    float temp;
    for (int i = 0; i < n-1; i++){
        for(int j=i-1;j<n;j++){
            if(p[i]<p[j]){
                SWAP(p[i],p[j],temp);
                SWAP(v[i],v[j],temp);
                SWAP(w[i],w[j],temp);
            }
        }
    }
}
void print(){
    printf("trong luong tui dung do vat:%.1f\n",M-T);
    T=0;
    float k=0;
    for(int i=0;i<n;i++){
        if(x[i]!=0){
            printf("x:%d v:%.2f w:%.2f\t",x[i],v[i],w[i]);
            T=T+x[i]*v[i];
            k = k+x[i]*w[i];
        }
    }
    printf("\nGia tri lon nhat la:%.1f voi tong trong luong la:%.1f\n",T,k);
}
void Greedy(){
    int i=0;
    while(T>0&&i<n){
        if(T>=w[i]){
            x[i]++;
            T-=w[i];
        }else i++;
    }
}
int main (){
    init();
    Greedy();
    print();
}