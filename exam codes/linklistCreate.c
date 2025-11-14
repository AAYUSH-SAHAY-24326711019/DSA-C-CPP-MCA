#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int info; struct Node* next;
}N;

N* head = NULL;

void create(N** head,int data){
    N* new_node = (N*)malloc(sizeof(N));
    new_node->info=data;
    new_node->next=NULL;
    *head = new_node;
}

void traverse(N** head){
    N* trav_ptr = *head;
    while(trav_ptr!=NULL){
        printf("[%d]-",trav_ptr->info);
        trav_ptr=trav_ptr->next;
    }
}
int main(){
    create(&head,10);
    traverse(&head);
    return 0;
}