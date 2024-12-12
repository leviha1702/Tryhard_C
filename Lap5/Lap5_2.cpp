#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int n;
int maxc=10000;
int c[MAX][MAX];
int x[MAX];
int chuaxet[MAX];
int sum=0;

void readFile(){
    FILE * f=fopen("Dulich.inp","r");
    if(f==NULL) return;
    fscanf(f,"%d\n",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            fscanf(f,"%d",&c[i][j]);
        }
        fscanf(f,"\n");
    }
    for(int i=2;i<=n;i++){
        chuaxet[i]=1;
    }
    fclose(f);
}
void init(){
    x[1]=1; chuaxet[1]=0;
    for(int i=2;i<=n;i++){
        chuaxet[i]=1;
    }
}
void print(){
    printf("TP1 -> ");
    for(int i=2;i<=n;i++){
        printf("TP%d-> ",x[i]);
    }
    printf("TP1\n");
    printf("tong chi phi la:%d",sum);
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
void writeFile(){
    FILE *f=fopen("Dulich.out","w");
    if(f==NULL) return;
    fputs("TP1-> ", f);
    for(int i=2;i<=n;i++){
        fprintf(f,"TP%d-> ",x[i]);
        fputs("TP1\n",f);
        fprintf(f,"Tong chi phi la:%d",sum);
    }
    fclose(f);
}
void Greedy(){
    int i, xi,tot;
    x[i]=1;
    chuaxet[1]=0;
    i=1;
    while(i<n){
        i++;
        tot = maxc;
        for(int j=2;j<=n;j++){
            if(chuaxet[j]&&c[x[i-1]][j]<tot){
                xi=j;
                tot = c[x[i-1]][j];
            }
        }
        x[i]=xi;
        chuaxet[xi]=0;
        sum=sum+c[x[i-1]][x[i]];
    }
    sum=sum+c[x[n]][1];
}
int main(){
    readFile();
    printfMT();
    Greedy();
    print();
    writeFile();
}