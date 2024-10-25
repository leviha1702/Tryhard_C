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
	fwrite(book, sizeof(Book),n,f);
	fclose(f);
}
// nhập sách vào file nhị phân Sach.inp
void nhapBook(Book*book,int n){
	for(int i=0;i<n;i++){
		printf("nhap thong tin sach thu %d:\n",i+1);
		printf("Ten sach:");
		fflush(stdin);
		gets(book[i].name);
		printf("Ten tac gia:");
		gets(book[i].nameAuthor);
		printf("Nhap nha xuat ban:");
		gets(book[i].publisher);
		printf("Nhap nam xuat ban:");
		scanf("%d",&book[i].year);
	}
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
	Book book;
	fseek(f,(p-1)*sizeof(Book),SEEK_SET);
	fread(&book, sizeof(Book),1,f);
	printf("Thong tin sach thu %d:\n",p);
	printf("Ten sach:%s\n",book.name);
	printf("Ten tac gia:%s\n",book.nameAuthor);
	printf("Nha xuat ban:%s\n",book.publisher);
	printf("Nam xuat ban:%d\n",book.year);
	fclose(f);
}
int main(){
    Book *book;
	int n,p;
	while(n<2||n>=50){
		printf("Nhap so luong sach:");
		scanf("%d",&n);
	}
	Book*book = (Book*)malloc(n*sizeof(Book));
	nhapBook(book,n);
	writeBookIn(book,n);
	printf("Nhap so thu tu sach can doc:");
	scanf("%d",&p);
	readBookP(p,n);
	free(book);
	return 0;
}