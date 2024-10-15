#include<stdio.h>
#include<stdlib.h>
struct  Node
{
    float data;
    struct Node *next;
};
typedef struct Node * node;
//hàm nhập danh sách đầu
/*
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
*/
Node *nhapDS_First(Node *&dau){
	int x;
	Node *New;
	do{
		printf("nhap 1 so nguyen(0:dung)");
		scanf("%d",&x);
		if(x!=0){
			New=(Node*)malloc(sizeof(Node));
			New->data=x;
			New->next=dau;
			dau=New;
		}
	}while(x!=0);
	return dau;
}
//in ra dslk đã nhập
void printfList(Node *dau){
	while(dau != NULL){
		printf("%d ",dau->data);
		dau=dau->next;
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
    nhapDS_First(head);
    printf("Danh sach da nhap la:");
    printfList(head);


}

