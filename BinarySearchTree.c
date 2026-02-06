#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode{
    int data;
    struct bstNode *left;
    struct bstNode *right;
}BstNode;

typedef struct bsTree{
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
BstNode* findNode(BsTree *bst, int data){
    if(!bst->root){
        printf("Info: BST is empty!!\n");
        return NULL;
    }
    BstNode *cur = bst->root;
    while(cur){
        if(data < cur->data)
            cur = cur->left;
        else if(data > cur->data)
            cur = cur->right;
        else{
            printf("found node for data %d\n", data);
            return cur;
        }
    }
    printf("Not found node for data %d\n", data);
}

BstNode* inSuccessor(BstNode *node){
    BstNode* tmp = node;
    if(tmp->right){
        tmp = tmp->right;
        while(tmp->left){
            tmp = tmp->left;
        }
        return tmp;
    }    
}

int countChildren(BstNode *node){
    int count=0;
    if(node->left)
        count++;
    if(node->right)
        count++;
    return count;
}

BstNode* findParent(BsTree *bst, int data){
    if(!bst->root){
        printf("Info: BST is empty!!\n");
        return NULL;
    }
    BstNode *cur = bst->root;
    BstNode *parent = NULL;
    while(cur){
        if(data < cur->data){
            parent = cur;
            cur = cur->left;
        }
        else if(data > cur->data){
            parent = cur;
            cur = cur->right;
        }
        else{
            //printf("found node for data %d\n", data);
            return parent;
        }
    }
    return NULL;
    //printf("Not found node for data %d\n", data);
}

void delete(BsTree* bst, int data){
    if(!bst->root){
        printf("Info: BST is empty!!\n");
        return ;
    }
    BstNode *node = findNode(bst, data);
    BstNode* parent = findParent(bst, data);

    int children=0;
    if(node)
        children = countChildren(node);

    if(children==0){        
        BstNode* tmp = node;
        if(parent->left == node){
            parent->left = NULL;
        } else{
            parent->right = NULL;
        }
        free(tmp);
    } else if(children==1){
        BstNode *tmp = node;
        if(parent->left == node){
            if(node->left){
                parent->left = node->left;
            } else{
                parent->left = node->right;
            }
        } else {
            if(node->left){
                parent->right = node->left;                
            } else {
                parent->right = node->right;
            }
        }
        free(tmp);

    } else{ //node with 2 children
        BstNode *tmp = NULL;
        BstNode* successor = inSuccessor(node);
        BstNode* succParent = findParent(bst, successor->data);
        tmp = successor;
        if(successor->right){
            succParent->left = successor->right;
        } else{
            succParent->left = NULL;
        }
        node->data = successor->data;
        free(tmp);
    }
}

void main(){
    BsTree b1;
    initializeBST(&b1);
    insert(&b1, 10);
    insert(&b1, 5);
    insert(&b1, 20);
    insert(&b1, 3);
    insert(&b1, 8);
    insert(&b1, 7);
    insert(&b1, 6);
    insert(&b1, 80);
    insert(&b1, 12);
    insert(&b1, 90);
    display(&b1); //inorder traversal
    //findNode(&b1, 7);
    delete(&b1, 5);
    display(&b1);

}



//This code is useful even for Binary tree where the elements
//inserted may not be following any order.
//But for BST we can do away with simple comparison to find the node location
/*BstNode* findNode(BsTree* bst, int data){
    if(!bst->root){
        printf("Info: BSTree is empty!!\n");
        return NULL;
    }    
    Stack s;
    initializeStack(&s);

    BstNode *cur = bst->root;
    push(&s, cur);
    do{
        if(cur->left){
            push(&s, cur->left);
            cur = cur->left;
        }
        else{
            if(cur->data == data){
                printf("Info: Found %d and memory address is %p\n",cur->data, cur);
                return cur;
            }
            cur = top(&s);
            pop(&s);
            if(cur->right){
                push(&s, cur->right);
                cur = cur->right;
            } 
        }
    }while(!empty(&s));
}*/