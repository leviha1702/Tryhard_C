#include<stdio.h>
#include<stdlib.h>
#define MAX 150

int n;//số thành phố
int c[MAX][MAX];//ma trận chi phí
int x[MAX];//nghiệm đang xét
int kq[MAX];//nghiệm tốt nhất
int chuaXet[MAX];//đánh dấu thành phố chưa xét
int best_sum=1000;//chi phí hành trình tốt nhất
int sum;//lưu chi phí từ tp đầu tới tp i

//đọc file
void readFile(){
    FILE *f=fopen("Dulich.inp","r");
    if(f==NULL){
        printf("file rong");
        return;
    }
    else{
        fscanf(f,"%d\n",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                fscanf(f,"%d",&c[i][j]);
            }
            fscanf(f,"\n");
        }
    }
    fclose(f);
}
//xuất ma trận
void printfMT(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%8d",c[i][j]);
        }
        printf("\n");
    }
}
//khoi tao
void khoitao(){
    x[1]=1;
    for(int i=2;i<=n;i++)
        chuaXet[i]=1;
}
//đánh giá
void danhgia(){
    if(sum<best_sum){
        best_sum = sum;
        for(int i=1;i<=n;i++){
            kq[i]=x[i];
        }
    }
}
//ghi file
void writeFile(){
    FILE *f=fopen("Dulich.out","w");
        if(f==NULL){
            printf("khong the mo file");
            return;
        }
        fputs("TP1 ->",f);
        for(int i=2;i<=n;i++){
            fprintf(f,"TP%d ->",kq[i]);
        }
        fputs("TP1\n",f);
        fprintf(f,"Tong chi phi la: %d",best_sum+c[kq[n]][1]);
}
void thu(int i){
    if(sum<best_sum){
        for(int j=2;j<=n;j++){
            if(chuaXet[j]){
                x[i]=j;
                chuaXet[j]=0;
                sum=sum+c[x[i-1]][j];
                if(i==n) danhgia();
                else thu(i+1);
                sum=sum-c[x[i-1]][j];
                chuaXet[j]=1;
            }
        }
    }
}
int main(){
    readFile();
    printfMT();
    khoitao();
    thu(2);
    writeFile();
}