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
//tìm số âm lớn nhất trong danh sách liên kết
void findNegMax(node head){
    if(head==NULL) return;
    float find=-FLT_MAX;
    node temp=head;
    while(temp!=NULL){
        if(temp->data<0&&temp->data>find){
            find=temp->data;
        }
        temp=temp->next;
    }
    if(find==-FLT_MAX){
        printf("\nkhong co so am trong danh sach lien ket");
    }else{
        printf("\nso am lon nhat trong danh sach lien ket:%.1f",find);
    }
}
int main(){
    node head=NULL;
    nhapFirst(head);
    printList(head);
    findNegMax(head);
}