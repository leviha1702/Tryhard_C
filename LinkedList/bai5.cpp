#include<stdio.h>
#include<stdlib.h>
struct Node
{
    float data;
    Node * next;
};
typedef struct Node *node;

node nhapFirst(node &head){
    float x;
    do{
        printf("nhap gia tri nguyen(0:dung):");
        scanf("%f",&x);
        if(x!=0){
            node newNode = new Node();
            newNode->data=x;
            newNode->next=NULL;
            newNode->next=head;
            head=newNode;
        }
    }while(x!=0);
    return head;
}
void printList(node head){
    if(head==NULL){
        printf("danh sach lien ket rong");
    }
    node temp=head;
    while(temp!=NULL){
        printf("%.1f ",temp->data);
        temp=temp->next;
    }
}
//tổng số âm trong danh sách
float sum(node head){
    float s=0;
    node p=head;
    while(p!=NULL){
        if(p->data<0) s+=p->data;
        p=p->next;
    }
    return s;
}
int main(){
    node head=NULL;
    nhapFirst(head);
    printList(head);
    printf("tong so am trong daanh sach:%.1f",sum(head));
}