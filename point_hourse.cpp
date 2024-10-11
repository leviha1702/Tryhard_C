#include<stdio.h>
int main(){
	//cau a
	int n,a[100][100];
	while(!(n>2&&n<10)){
		printf("nhap n:");
		scanf("%d",&n);
	}
	// nhap ma tran
	printf("nhap phan tu la:");
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
	// xuat ma tran
	printf("ma tran da nhap :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d",a[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	// cau b:diem yen ngua trong ma tran
	int temp=0;
	//tim phan tu lon nhat tren dong
	for(int i=0;i<n;i++){
		int max=a[i][0];
		int index=0;
		for(int j=0;j<n;j++){
			if(max<a[i][j]){
				max=a[i][j];
				index=j;
			}
		}
		// xet phan tu do co bé nhat tren cot chua no khong
		int point_house=1;
		for(int k=0;k<n;k++){
			if(a[k][index]<max){
				point_house=0;
				break;
			}
		}
		if(point_house){
			printf("diem yen ngua tai [%d][%d] = %d\n",i,index,max);
			temp=1;
		}
	}
	if(temp!=1){
		printf("ma tran khong co diem xe ngua");
	}
}