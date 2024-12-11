#include<stdio.h>
#include<stdlib.h>
struct Node
{
    char data;
    Node * next;
};
typedef struct Node *node;

node nhapFirst(node &head){
    char a;
    do{
        printf("nhap nhap cac ki tu('0':dung):");
        scanf("%c",&a);
        if(a!='0'){
            node newNode = new Node();
            newNode->data=a;
            newNode->next=NULL;
            newNode->next=head;
            head=newNode;
        }
    }while(a!='0');
    return head;
}
void printList(node head){
    if(head==NULL){
        printf("danh sach lien ket rong");
    }
    node temp=head;
    while(temp!=NULL){
        printf("%c",temp->data);
        temp=temp->next;
    }
}
//đếm số kí tự 'A' có trong danh sách liên kết
void countChar(node head){
    int count=0;
    if(head==NULL){
        printf("danh sach lien ket rong");
    }
    node p=head;
    while(p!=NULL){
        if(p->data=='A'){
            count++;
        }
        p=p->next;
    }
    if(count!=0){
        printf("\nco %d so ki tu 'A' trong danh sach",count);
    }else{
        printf("\nkhong co ki tu 'A'");
    }
}
int main(){
    node head=NULL;
    nhapFirst(head);
    printList(head);
    countChar(head);
}