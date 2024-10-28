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
