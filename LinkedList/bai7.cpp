#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    Node * next;
};
typedef struct Node *node;

node nhapFirst(node &head){
    int x;
    do{
        printf("nhap gia tri nguyen(0:dung):");
        scanf("%d",&x);
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
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
//tìm số chẵn cuói cùng trong danh sách
int findSole(node head){
    int find=0;
    node p=head;
    while(p!=NULL){
        if(p->data % 2 ==0){ 
            find=p->data;
        }
        p=p->next;
    }
    return (find!=0)? find:0;

}
int main(){
    node head=NULL;
    nhapFirst(head);
    printList(head);
    if(findSole!=0){
        printf("\nso chan dau tien trong danh sach:%d",findSole(head));
    } else {
        printf("\nkhong co so chan trong danh sach");
    }
}