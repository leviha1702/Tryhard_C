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
        scanf(" %c",&a);
        if(a!='0'){
            node newNode = (node)malloc(sizeof(Node));
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
//tìm thứ tự cuối cùng của kí tự "A" trong danh sách liên kết
void findLastA(node head){
    int index=0,count=1;
    if(head==NULL) return;
    node p=head;
    while (p!=NULL)
    {
        if(p->data=='A'){
            index=count;
        }
        p=p->next;
        count++;
    }
    if(index!=0){
        printf("vi tri cuoi cung cua ki tu 'A' trong danh sach :%d",index);
    }else printf("\nkhong co ki tu 'A' trong danh sach lien ket");
}
int main(){
    node head=NULL;
    nhapFirst(head);
    printList(head);
    findLastA(head);
}