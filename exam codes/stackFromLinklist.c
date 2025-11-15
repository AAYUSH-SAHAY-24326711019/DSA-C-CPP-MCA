#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* next;
}N;

N* head = NULL;
N* top =NULL;

void create(N** head,int data){
    if(*head==NULL){
        N* node = (N*)malloc(sizeof(N));
        node->info=data;
        node->next=NULL;
        *head = node;
        top = *head;
    }
}

void push(N** head,int data){
    N* node = (N*)malloc(sizeof(N));
    N* temp = node;
    node->info=data; 
    node->next=top;
    top=temp;
    *head=top;
}

void pop(N** head){
    N* temp = *head;
    top=top->next;
    *head=top;
    free(temp);
}

void traverse(N** head){
    N* temp = *head;
    while(temp!=NULL){
        printf("[%d]-",temp->info);
        temp=temp->next;
    }
}

int main(){
    create(&head,10);
    push(&head,20);
    push(&head,30);
    push(&head,40);
    pop(&head);
    traverse(&head);
    return 0;
}