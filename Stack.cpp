#include<stdio.h>
#define SIZE 20
struct Stack
{
	int a[SIZE];
	int top;
};
//khai báo ngăn xếp stack
typedef struct Stack stackType;
void Init(stackType * s){
	s->top=-1;
}
//thêm phần tử vào ngăn xếp
int push(stackType *s,int x){
	if (s->top==SIZE-1) printf("ngan xep da day!");
	else {
		s->top++;
		s->a[s->top]=x;
	}
	return 0;
}
//lấy phần tử ra khỏi stack
int pop(stackType *s,int *x){
	if (s->top==-1)
	{
		return 0;
	}else {
		*x=s->a[s->top];
		s->top=s->top-1;
		return 1;
	}
}
//nhập phần tử vào stack
void nhapStack(stackType *s){
	int n,value;
	printf("nhap so luong phan tu cua stack:");
	scanf("%d",&n);
	if (n>SIZE){
			printf("vuot qua kich thuoc ngan xep");
			return;
		}
	for(int i=0;i<n;i++){
		printf("nhap gia tri phan tu thu %d:",i+1);
		scanf("%d",&value);
		push(s,value);
	}
}
//xem các phần tử trong stack
void display(stackType *s){
	if(s->top==-1) printf("ngan xep rong");
	else {
		printf("các phần tử trong ngăn xếp là:");
		for(int i=0;i<=s->top;i++){
			printf("%d ",s->a[i]);
		}
		printf("\n");
	}
}
//hàm lấy phần tử đầu mà không xóa phần tử
int view(stackType *s,int *x){
	if(s->top==-1) return 0;
	else{
		*x=s->a[s->top];
		return 1;
	}
}
int main(){
	int x;
	stackType s;
	Init(&s);
	nhapStack(&s);
	display(&s);
	push(&s,20);
	push(&s,3);
	display(&s);
	while(pop(&s,&x)==1) printf("%d ",x);
}