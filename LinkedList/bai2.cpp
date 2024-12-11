#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<float.h>
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
//tìm số dương nhỏ nhất trong danh sách liên kết
void findPosMin(node head){
    if(head==NULL) return;
    float find=FLT_MAX;
    node temp=head;
    while(temp!=NULL){
        if(temp->data<find&&temp->data>0){
            find=temp->data;
        }
        temp=temp->next;
    }
    if(find==FLT_MAX){
        printf("\nkhong co so duong trong danh sach lien ket");
    }else{
        printf("\nso duong nho nhat trong danh sach lien ket:%.1f",find);
    }
}
int main(){
    node head=NULL;
    nhapFirst(head);
    printList(head);
    findPosMin(head);
}