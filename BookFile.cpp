#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// câu a cấu trúc sách
typedef struct{
	char name[50];
	char nameAuthor[20];
	char publisher[20];
	int year;
}Book;
//câu b:viết chương trình nhập n quyển sách
void writeBookIn(Book *book,int n){
	FILE *f=fopen("Sach.inp","wb");
	if(f==NULL){
		printf("Khong the mo file de ghi\n");
		return;
	}
	fprintf(f,"%d\n",n);
// nhập sách vào file nhị phân Sach.inp
	for(int i=1;i<=n;i++){
		printf("nhap thong tin sach thu %d:\n",i);
		printf("Ten sach:");
		scanf("%s",&book[i].name);
		fprintf(f,"%s\n",book[i].name);
		printf("Nhap ten tac gia:");
		scanf("%s",&book[i].nameAuthor);
		fprintf(f,"%s\n",book[i].nameAuthor);
		printf("Nhap nha xuat ban:");
		scanf("%s",&book[i].publisher);
		fprintf(f,"%s\n",book[i].publisher);
		printf("Nhap nam xuat ban:");
		scanf("%d",&book[i].year);
		fprintf(f,"%d\n",book[i].year);
	}
	fclose(f);
}
// cau c: đọc và hiển thị thông tin sách thứ p
void readBookP(int p,int n){
	FILE *f=fopen("Sach.inp","rb");
	if(f==NULL){
		printf("Khong the mo file ra doc\n");
		return;
	}
	if(p<1 || p>n){
		printf("so thu tu p khong hop le\n");
		fclose(f);
		return;
	}
	Book *book;
	printf("Thong tin sach thu %d:\n",p);
	printf("Ten sach");
	fscanf(f,"%s",&book[p].name[50]);
	printf("Ten tac gia:");
	fscanf(f,"%s",&book[p].nameAuthor[20]);
	printf("Nha xuat ban:");
	fscanf(f,"%s",&book[p].publisher[20]);
	printf("Nam xuat ban:");
	fscanf(f,"%d",&book[p].year);
	fclose(f);
}
int main(){
	int n,p;
	while(n<2||n>=50){
		printf("Nhap so luong sach:");
		scanf("%d",&n);
	}
	Book *book = (Book*)malloc(n*sizeof(Book));
	writeBookIn(book,n);
	printf("Nhap so thu tu sach can doc:");
	scanf("%d",&p);
	readBookP(p,n);
	return 0;
}