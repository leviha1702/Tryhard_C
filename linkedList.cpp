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
// thêm phần tử đầu
void insertFirst(node &head,int x){
    node temp= makeNode(x);
    if(head ==NULL) head=temp;
    else{
        temp->next=head;
        head=temp;
    }
}
// thêm phần tử cuối 
void insertLast(node &head,int x){
    node temp= makeNode(x);
    if (head==NULL) head = temp;
    else {
        node p=head;
        while (p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }
}
//thêm phần tử ở giữa
void insertMiddle(node &head,int x,int pos){
    int n=sizeof(head);
    if (pos<=0||pos>n+1){
        printf("Vi tri chen khong hop le");
    }
    if (n==1) {
        insertFirst(head,x);
        return ;
    } else if(n==pos+1){
        insertLast(head,x);
        return;
    }
    node temp = makeNode(x);
    node p=head;
    for (size_t i = 1; i < pos-1; i++){
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
}
int main(){
    int x, index;
    Node * head= NULL; 
    //tạo danh sách liên kết   
    nhapDS_First(head,x);
    printf("Danh sach da nhap la:");
    printfList(head);
    //chèn vị trí bất kì
    int pos,a;
    printf("\nNhap gia tri va vi tri chen:");
    scanf("%d %d",&a,&pos);
    insertMiddle(head,a,pos);
    printf("dslk vua chen:");
    printfList(head);
}

