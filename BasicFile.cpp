#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void readFile(int a[][MAX],int n){
	FILE *f = fopen("MaTran.inp","r");
	if(f==NULL){
		printf("Error.");
	}
	//cau a
	//lấy số phan tu n trong file ra
	fscanf(f,"%d",&n);
	//đọc giá trị trong file ra 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(f,"%d",&a[i][j]);
		}
	}
	fclose(f);
	//cau b:in ma trận ra màn hình
	printf("ma tran trong file'Matran.inp':\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%8d",a[i][j]);
		}
		printf("\n");
	}
}
// cau c:tbc số nằm trên đường chéo chính và ghi vào file "KetQua.out"
void ketQua(int a[][MAX],int n){
	FILE *f =fopen("KetQua.out","w");
	if(f==NULL){
		printf("khong mo duoc file!");
	}
	FILE *g = fopen("MaTran.inp","r");
	if(g==NULL){
		printf("khong mo duoc file!");
	}
	fscanf(g,"%d",&n);
	float tbc=1;
	int count=0,s=0;
	int max=a[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				count++;
				s+=a[i][j];
			}//cau d:tim so lon nhat trong ma tran
			if(a[i][j]>max){
				max=a[i][j];
			}
		}
	}
	tbc=s/count;
	fprintf(f,"%.1f",tbc);
	fprintf(f,"\nso lon nhat trong ma tran:%d",max);
	fclose(g);
	fclose(f);
	printf("da nhap ket qua trung binh cong va so lon nhat vao file");
}

int main(){
	int a[MAX][MAX],n;
	readFile(a,n);
	ketQua(a,n);
}