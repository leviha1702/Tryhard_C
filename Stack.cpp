#include<stdio.h>
#define SIZE 20
struct Stack
{
	int a[SIZE];
	int top;
};
//khai báo ngăn xếp stack
typedef struct Stack*stackType;
void Init(stackType s){
	s->top=-1;
}
//kiểm tra ngăn xếp có rỗng không
int isEmpty(stackType s){
	return s->top==-1;
}
//kiểm tra ngăn xếp đầy không
int isFull(stackType s){
	return s->top==SIZE-1;
}
//thêm phần tử vào ngăn xếp
void push(stackType s,int x){
	if (isFull(s)) printf("ngan xep da day!");
	else {
		s->top++;
		s->a[s->top]=x;
	}
}
//lấy phần tử ra khỏi stack
int pop(stackType s,int *x){
	if (s->top==-1)
	{
		return 0;
	}else {
		*x=s->a[s->top];
		s->top=s->top-1;
		return 1;
	}
}
//xem cách phần tử trong stack
void display(stackType s){
	if(isEmpty(s)) printf("ngan xep rong");
	else {
		for(int i;i<=s->top;i++){
			printf("%d",s->a[i]);
		}
		printf("\n");
	}
}
//nhập phần tử vào stack
void nhapStack(stackType &s){
	int n,value;
	printf("nhap so luong phan tu cua stack:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		if (isFull(s)){
			printf("ngan xep da day!");
			break;
		}
		printf("nhap gia tri phan tu thu %d:",i+1);
		scanf("%d",&value);
		push(s,value);
	}
}
//hàm lấy phần tử đầu mà không xóa phần tử
int view(stackType s,int *x){
	if(s->top==-1) return 0;
	else{
		*x=s->a[s->top];
		return 1;
	}
}
int main(){
	int x;
	stackType s;
	Init(s);
	nhapStack(s);
	display(s);
	while(pop(s,&x)==1){
		printf("gia tri phan tu bi lay ra:%d\n",x);
	}
	display(s);
}