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
node makeNode(int x){
    node temp=new Node();
    temp->data=x;
    temp->next=NULL;
    return temp;
}
//chèn đầu ds
void insertFirstList(node &head,int x){
    node temp = makeNode(x);
    if(head==NULL) head = temp;
    else{
        temp->next=head;
        head=temp;
    }
}
//chèn ở vị trí cuối cùng của ds
void insertLastList(node &head,int x){
    node temp = makeNode(x);
    if(head==NULL) head = temp;
    else{
        node p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }
}
//chèn ở vị trí bất kì của ds
void insertMiddleList(node &head,int x,int index){
    int n=sizeof(head);
    if(index<=0||index>n+1){
        printf("vi tri chen khong hop le");
        return;
    }
    if(n==1){
        insertFirstList(head,x);
        return;
    }else if(n==index+1){
        insertLastList(head,x);
        return;
    }
    node temp = makeNode(x);
    node p=head;
    for(int i=1;i<index-1;i++){
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
}
//xóa đầu danh sách
void deleteFirst(node &head){
    node temp=head;
    if(head==NULL) return;
    else{
        head = head->next;
        free(temp);
    }
}
//xóa cuối danh sách
void deleteLast(node &head){
    node temp=NULL;
    if(head==NULL) return;
    node p=head;
    while(p->next!=NULL){
        temp=p;
        p=p->next;
    }
    if(temp=NULL){
        head=NULL;
    }
    else{
        temp->next=NULL;
        free(p);
    }
}
//xóa vị trí bất kì
void deleteMiddle(node &head,int index){
    int n=sizeof(head);
    if(index<=0||index>n+1){
        printf("vi tri xoa khong hop le");
        return;
    }
    if(n==1){
        deleteFirst(head);
        return;
    }else if(n==index+1){
        deleteLast(head);
        return;
    }
    node temp=NULL;
    node p=head;
    for(int i=1;i<index;i++){
        temp=p;
        p=p->next;  
    }
    temp->next=p->next;
    free(p);
}
int main(){
    node head=NULL;
    int n;
    nhapFirst(head);
    printList(head);
    insertFirstList(head,5);
    insertLastList(head,7);
    insertMiddleList(head,3,5);
    printf("\n danh sach sau khi chen:\n");
    printList(head);
    deleteMiddle(head,4);
    printf("\n danh sach sau khi xoa:\n");
    printList(head);
}
