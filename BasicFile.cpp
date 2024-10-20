#include<stdio.h>
#include<stdlib.h>
#define MAX 100
// nhap day so va ghi vao file"DaySo.inp"
void nhapDaySo(int n){
	FILE *f = fopen("DaySo.inp","w");
	if(f==NULL){
		printf(	"khong the mo file.\n");
	return;
	}
	printf("nhap so luong phan tu cua day so:");
	scanf("%d",&n);
	int num;
	for(int i=0;i<n;i++){
		printf("nhap so nguyen thu %d:",i+1);
		scanf("%d",&num);
		fprintf(f,"%d",num);
	}
	fclose(f);
	printf("day so da duoc ghi vao file 'DaySo.inp'.\n");
}
// tao ma tran va ghi vao file'MaTran.inp'
void maTran(int n){
	FILE *f = fopen("MaTran.inp","w");
	if(f==NULL){
		printf(	"khong the mo file.\n");
		return;
	}
	do{
		printf("nhap so phan tu cua ma tran:");
		scanf("%d",&n);
	}while(!(n>=2&&n<=30));
	fprintf(f,"%d\n",n);//ghi n vào file
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int num = rand() % 1000;
			fprintf(f,"%6d",num);
		}
		fprintf(f,"\n");
	}
	fclose(f);
	printf("ma tran da dc ghi vao file'MaTran'.inp.\n");
}
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
    nhapDaySo(n);
    maTran(n);
	readFile(a,n);
	ketQua(a,n);
}