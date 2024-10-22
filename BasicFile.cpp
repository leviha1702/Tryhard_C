#include<stdio.h>
#include<stdlib.h>
#define MAX 100
/*
// nhap day so va ghi vao file"DaySo.inp"
void nhapDaySo(int n){
	FILE *f = fopen("DaySo.inp","w");
	if(f==NULL){
		printf(	"khong the mo file.\n");
	return;
	}
	printf("nhap so luong phan tu cua day so:");
	scanf("%d",&n);
	fprintf(f,"%d\n",n);
	int num;
	for(int i=0;i<n;i++){
		printf("nhap so nguyen thu %d:",i+1);
		scanf("%d",&num);
		fprintf(f,"%d ",num);
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
void readDaySo(int arr[],int &n){
	FILE *f=fopen("DaySo.inp","r");
	if(f==NULL) {
		printf("khong the mo file!\n");
		return;
	}
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(f,"%d ",&arr[i]);
	}
	fclose(f);
}
//cau b:ham xuat day so
void printfDaySo(int arr[],int n){
	printf("day so trong file 'DaySo.inp':");
	for(int i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//cau c:
//dem va tra ve so luong phần tử có giá trị x dùng vòng lặp;
int count1(int a[],int n,int x){
	int count=0;
	for(int i=0;i<n;i++){
		if(a[i]==x){
			count++;
		}
	}
	return count;
}
//dùng đệ quy;
int count2(int a[],int n,int x){
	if(n==0){
		return 0;
	}
	return (a[n-1]==x)+ count2(a,n-1,x);
}
// cau a: khai báo kiểu dữ liệu cấu trúc
typedef struct{
	char code[20];
	char name[100];
	int numCredit;
}course;
void readFile(course hp[],int &n){
	FILE *f=fopen("HocPhan.txt","r");
	if(f==NULL){
		printf("khong the mo file'HocPhan.txt'");
		return;
	}
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(f,"%s",hp[i].code);//đọc mã học phần
		fgetc(f);//xuống dòng
		fgets(hp[i].name,100,f);//đọc tên học phần 
		fscanf(f,"%d",&hp[i].numCredit);//đọc số tín chỉ
	}
	fclose(f);
}
//câu d:xuất danh sách học phần
void xuatDS(course hp[],int n){
	printf("So hoc phan:%d\n",n);
	printf("Danh sach cac hoc phan:\n");
	for(int i=0;i<n;i++){
		printf("%s\n",hp[i].code);
		printf("%s",hp[i].name);
		printf("%d\n",hp[i].numCredit);
	}
}*/
void outFile(int a[],int &n){
	FILE *f=fopen("MangSoThuc.txt","r");
	if(f==NULL){
		printf("Khong mo duoc file!");
		return;
	}
	//câub:đọc n số thực từ file và lưu vào mảng a
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(f,"%d",&a[i]);
	}
	fclose(f);
}
//câu c:xuất mảng a ra màng hình
void printfArr(int a[],int n){
	printf("Mang so thuc trong file 'MangSoThuc.txt':\n");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
//câu d:tính tổng phần tử trong dãy số(vòng lặp)
int sumArr(int a[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	return sum;
}
//tính tổng phần tử trong dãy số(đệ qui)
int sumAr(int a[],int n){
	if(n==1){
		return a[0];
	}
	return a[n-1]+sumAr(a,n-1);
}
int main(){
	/*
	int a[MAX][MAX],n;
    nhapDaySo(n);
    maTran(n);
	readFile(a,n);
	ketQua(a,n);
	int arr[20];
	//cau a;
	readDaySo(arr,n);
	//cau b;
	printfDaySo(arr,n);
	//cau c
	int x;
	printf("\nnhap gia tri cua x:");
	scanf("%d",&x);
	printf("(ham vong lap)so luong gia tri %d trong mang:%d\n",x,count1(arr,n,x));
	printf("(ham de quy)so luong %d co trong mang:%d",x,count2(arr,n,x));
	int n;
	course hp[100];
	readFile(hp,n);
	xuatDS(hp,n);
	*/
	int a[MAX],n;
	outFile(a,n);
	printfArr(a,n);
	printf("tong day so trong mang(vong lap):%d\n",sumArr(a,n));
	printf("tong de qui:%d",sumAr(a,n));
}