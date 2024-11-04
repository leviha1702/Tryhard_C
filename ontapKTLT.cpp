#include<stdio.h>
#include<stdlib.h>
#define MAX 50
void readFile(int a[],int &n,int &x){
	FILE*f=fopen("DaySoNguyen.txt","r");
	fscanf(f,"%d %d",&n,&x);
	printf("so luong phan tu va gia tri x:%d va %d\n",n,x);
	printf("day so nguyen:\n");
	for(int i=0;i<n;i++){
		fscanf(f,"%d",&a[i]);
		printf("%d ",a[i]);
	}
	fclose(f);
}
// dem uoc so dung vong lap
int countUS1(int a[],int n,int x){
	int dem=0;
	for(int i=0;i<n;i++){
		if(x%a[i]==0&&a[i]>0){
			dem++;
		}
	}
	return dem;
}int checkUS(int a,int x){
	if(x%a==0&&a>0){
		return 1;
	}return 0;
}
// dem uoc so dung de quy
int countUS2(int a[],int n,int x){
	if(n==0){
		return 0;
	}
	return checkUS(a[n-1],x)+countUS2(a,n-1,x);
}
void writeFile(int a[],int n ,int x){
	FILE *f=fopen("DemUocSo.txt","w");
	fprintf(f,"so luong so nguyen duong trong day so la uoc so cua x(vong lap):%d",countUS1(a,n,x));
	fprintf(f,"\nso luong so nguyen duong trong day so la uoc so cua x(de quy):%d",countUS2(a,n,x));
	fclose(f);
}
int main(){
	int a[MAX],n,x;
	readFile(a,n,x);
	writeFile(a,n,x);
}