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

void insertEnd(N** head, int data){
    N* node = (N*)malloc(sizeof(N));
    node->info=data;
    node->next=NULL;
    N* atEnd = *head;
    if(atEnd->next==NULL)
        atEnd->next=node;
    else{
        while(atEnd->next!=NULL){
            atEnd=atEnd->next;
        }
        atEnd->next=node;
        }
}

void SCLL_Nature(N** head){
    //single circular linked list nature
    N* endNode = *head;
    while(endNode->next!=NULL){
        endNode=endNode->next;
    }

    endNode->next=*head;

    printf("- See it gives you value [%d]-",endNode->next->info);
}


int main(){
    create(&head,10);
    insertEnd(&head,20);
    insertEnd(&head,30);
    insertEnd(&head,40);
    insertEnd(&head,50);
    traverse(&head);
    SCLL_Nature(&head);

    return 0;
}