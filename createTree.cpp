#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * left;
    struct Node *right;
};
//Tạo một nút mới cho cây
typedef struct Node*node;
node creatNode(int value){
    node newNode=(node)malloc(sizeof(Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
node insert(node root, int x){
    if(root ==NULL) return creatNode(x);
    if(x>root->data) root->right=insert(root->right,x);
    else if(x<root->data) root->left=insert(root->left,x);
    return root;
}
void printfTree(node root){
    if (root!=NULL)
    {
        printfTree(root->left);
        printf("%d ",root->data);
        printfTree(root->right);
    }
}
int main(){
    node root=NULL;
    root=insert(root,50);
    root=insert(root,40);
    root=insert(root,70);
    printfTree(root);
}
