#include<stdio.h>
#include<stdlib.h>
struct  Node
{
    int data;
    struct Node *next;
};
typedef struct Node * node;
//hàm nhập danh sách đầu
node nhapDS_First(node &head,int x){
    node newNode;
    do{
        printf("nhap 1 so nguyen(0:dung)");
        scanf("%d",&x);
        if (x!=0){   
            newNode = (node)malloc(sizeof(Node));
            newNode->data=x;
            newNode->next=head;
            head = newNode;
        }
    } while (x!=0);
    return head;
} 

//in ra dslk đã nhập
void printfList(Node *head){
	while(head != NULL){
		printf("%d ",head->data);
		head=head->next;
	}
}
// cấp phát động một node mới với dữ liệu số nguyên x
node makeNode(int x){
    node temp=new Node();
    temp->data=x;
    temp->next=NULL;
    return temp;
}
int main(){
    int x, index;
    Node * head= NULL;    
    nhapDS_First(head,x);
    printf("Danh sach da nhap la:");
    printfList(head);
}

