#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 20

struct Node
{
    char data[MAX_LEN+1];
    Node * next;
};
typedef struct Node *node;

//nhap chuoi ki tu vao danh sach lien ket
node nhapFirst(node &head,char str[]){
    do{
        printf("nhap nhap cac ki tu('0':dung):");
        scanf(" %s",str);
        if(strcmp(str,"0")!=0){
            node newNode = (node)malloc(sizeof(Node));
            strcpy(newNode->data,str);
            newNode->next=NULL;
            newNode->next=head;
            head=newNode;
        }
    }while(strcmp(str,"0")!=0);
    return head;
}
//xuất danh sách liên kết
void printList(node head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    printf("Danh sach lien ket:\n");
    node temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
//tìm vị trí kí tự dài nhất
void findIndexWordMax(node head){
    int max=strlen(head->data);
    int index=1;
    int count=1;
    if(head==NULL){
        return;
    }
    node temp=head->next;
    node wordShorted=head;
    while(temp!=NULL){
        count++;
        if(strlen(temp->data)>max){
            max=strlen(temp->data);
            index=count;
            wordShorted=temp;
        }
        temp=temp->next;
    }
    printf("phan tu co chuoi ki tu ngan nhat la:%s\n",wordShorted->data);
    printf("vi tri ki tu ngan nhat la:%d va do dai la:%d\n",index,max);
}
int main(){
    node head=NULL;
    char str[MAX_LEN+1];
    nhapFirst(head,str);
    printList(head);
    findIndexWordMax(head);
}