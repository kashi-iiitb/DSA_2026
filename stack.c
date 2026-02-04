/*
    Aim:    To implement a Stack data structure in C
    Date:   4th Feb 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

#define TRUE 1
#define FALSE 0

typedef struct node{
    BstNode *ptrBstNode;
    struct node *next;
}stackNode;

typedef struct stack{
    stackNode *top;
}Stack;

void initializeStack(Stack *s){
    s->top = NULL;
}

int empty(Stack *s){
    if(!s->top)
        return TRUE;
    else
        return FALSE;
}
stackNode* createStackNode(int data){
    stackNode *tmp = (stackNode*)malloc(sizeof(stackNode));
    if(!tmp){
        printf("Error: malloc() failure\n");
        return NULL;
    }
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}
void push(Stack *s, int data){
    if(empty(s)){
        s->top = createStackNode(data);
        return;
    }
    stackNode *tmp = createStackNode(data);
    tmp->next = s->top;
    s->top = tmp;
}

int top(Stack *s){
    if(!s->top){
        return -1;
    }
    return s->top->data;
}

void pop(Stack *s){
    if(!s->top){
        printf("Info: Stack is empty!\n");
        return;
    }
    stackNode *tmp = s->top;
    printf("Deleting %d\n", tmp->data);
    s->top = tmp->next;
    free(tmp);
}

int main(){
    Stack s;
    initializeStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);

}