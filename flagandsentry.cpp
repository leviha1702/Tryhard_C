#include<stdio.h>
#define max 50
//nhap day so
void nhapDS(int a[],int &n){
	do{
		printf("nhap so luong phan tu :");
		scanf("%d",&n);
	}while(!(n>3&&n<50));
	printf("Nhap phan tu cua mang:");
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
}
//dem so lan xuat hien gia tri x den khi gap linh canh -99999
int dem(int a[],int n,int x){
	int dem=0;
	int linhcanh=-99999;
	a[n]=linhcanh;
	int i=0;
	while(a[i]!=linhcanh){
		if(a[i]==x){
			dem++;
		}
		i++;
	}
	return dem;
}
//co hieu kiem tra day so giam dan(co hieu)
bool checkDD(int a[],int n){
	bool flag=true;
	for(int i=0;i<n;i++){
		if(a[i+1]>a[i]){
			flag=false;
			break;
		}
	}
	return flag;
}
int main(){
	int a[max],n;
	//cau a:
	nhapDS(a,n);
	//cau b:
	int x;
	printf("nhap gia tri x:");
	scanf("%d",&x);
	printf("so lan xuat hien gia tri x:%d",dem(a,n,x));
	//cau c:
	if(checkDD(a,n)){
		printf("\nday so dam dan");
	}else printf("\nday khong dam dan");
}