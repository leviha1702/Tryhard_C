#include<stdio.h>
#define Cong(x,y,z) ((x)+(y)+(z))
int main(){
	float x,y,z;
	printf("Nhap vao 3 so thuc:");
	scanf("%f %f %f",&x,&y,&z);
	float tong=Cong(x,y,z);
	printf("Tong 3 so thuc:%.2f",tong);
}