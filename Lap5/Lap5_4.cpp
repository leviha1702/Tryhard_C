#include<stdio.h>
#include<stdlib.h>
#define MAX 50


int a[MAX];
int n;
int l[MAX];
int t[MAX];
int lmax;

void readFile() {
    FILE *f = fopen("DaySo.inp", "r");
    if (f == NULL) {
        printf("khong the mo file\n");
        return;
    }
    fscanf(f, "%d", &n); // Đọc số phần tử
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &a[i]); // Đọc các phần tử của mảng
    }
    fclose(f);
}
int Init(){
    l[0]=0;
    for(int i=0;i<n;i++){
        t[i]=-1;
    }
}
void Dynamic() {
    for (int i = 0; i < n; i++) {
        lmax = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && l[i] < l[j] + 1) {
                lmax = l[j];
                t[i]=j;
            }
        }
        l[i]=lmax+1;
    }
}
int Track(){
    int max=l[0],p=-1;
    for(int i=1;i<n;i++){
        if(max<l[i]){
            max=l[i];
            p=1;
        }
    }
    printf("\ndo dai day tang dai nhat la %d", max);
    printf("\nvi tri cac phan tu:");
    while(p>=0){
        printf("%d\t",p);
        p=t[p];
    }
    return max;
}
// Hàm ghi kết quả vào file
void writeFile(int result) {
    FILE *f = fopen("DayCon.out", "w");
    if (f == NULL) {
        printf("Không thể mở file\n");
        return;
    }
    fprintf(f, "%d\n", result); // Ghi kết quả vào file
    fclose(f);
}
int main(){
    readFile();
    Init();
    Dynamic();
    int result=Track();
    writeFile(result);
}