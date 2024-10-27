#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
typedef struct
{
    int a[SIZE];
    int head,tail;//vị trí đầu cuối 
}Queue;
void Init(Queue *q){
    q->head=q->tail=-1;
}
int Push(Queue *q,int x){
    if((q->tail+1)%SIZE==q->head){
        printf("hang doi day!");
        return 0;
    }
    else{
        q->tail=(q->tail+1)%SIZE;
        q->a[q->tail]=x;
        if (q->head==-1)
        {
            q->head=0;
        }
        return 1;
    }
}
int Pop(Queue *q,int *x){
    if (q->head==-1)
    {
        printf("hang doi rong!");
        return 0;
    }
    else {
        *x=q->a[q->head];
        if (q->head==q->tail){
            q->head=q->tail=-1;
        } else{
            q->head=(q->head+1)%SIZE;
        }
        return 1;
    }
}
void nhapQueue(Queue *q){
    int n,value;
    while (!(n<=SIZE&&n>0))
    {
        printf("nhap so luong phan tu trong hang doi:");
        scanf("%d",&n);
    }
    for(int i=0;i<n;i++){
        printf("Nhap phan tu thu %d:",i+1);
        scanf("%d",&value);
        Push(q,value);
    }
}
void display(Queue *q){
    if (q->head==-1)
    {
        printf("hang doi rong");
    }
    else{
        int i=q->head;
        printf("cac phan tu trong hang doi:");
        while (1){
            printf("%d ",q->a[i]);
            if (i==q->tail) break;
            i=(i+1)%SIZE;
        }
        printf("\n");
    }
}
int view(Queue *q,int *x){
    if (q->head==-1) return 0;
    else{
        *x=q->a[q->head];
        return 1;
    }
}
int main(){
    int x;
    Queue q;
    Init(&q);
    nhapQueue(&q);
    display(&q);
    while (Pop(&q,&x)==1)
    {
       printf("%d ",x);
    }
}