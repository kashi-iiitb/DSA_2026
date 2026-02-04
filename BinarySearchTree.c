#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}BstNode;

typedef struct BST{
    BstNode *root;
}BsTree;

void initializeBST(BsTree *bst){
    bst->root = NULL;
}

BstNode* createBstNode(int data){
    BstNode *tmp = (BstNode*)malloc(sizeof(BstNode));
    if(!tmp){
        printf("Error: malloc() failure\n");
        return NULL;
    }
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void insert(BsTree *bst, int data){
    if(!bst->root){
        bst->root = createBstNode(data);
        return;
    }
    BstNode *cur = bst->root;
    while(cur){
        if(data<cur->data){
            if(cur->left){
                cur = cur->left;
            } else{
                cur->left = createBstNode(data);
                break;
            }
        } else {
            if(cur->right){
                cur  = cur->right;
            } else {
                cur->right = createBstNode(data);
                break;
            }
        }
    } //end of while
}

void inorder(BstNode *node){
    if(!node){
        return;
    }
    inorder(node->left);
    printf("%d\n", node->data);
    inorder(node->right);
}
void display(BsTree *bst){
    if(!bst->root){
        printf("Info: BST is empty!!\n");
        return;
    }
    printf("The elements in the BST:\n");
    inorder(bst->root);
}

void main(){
    BsTree b1;
    initializeBST(&b1);
    insert(&b1, 10);
    insert(&b1, 5);
    insert(&b1, 20);
    insert(&b1, 3);
    insert(&b1, 7);
    insert(&b1, 6);
    insert(&b1, 80);
    insert(&b1, 12);
    display(&b1); //inorder traversal
}