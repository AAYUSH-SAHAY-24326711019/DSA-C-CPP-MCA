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

void insertBeginning(N** head,int data){
    N* node = (N*)malloc(sizeof(N));
    node->info=data;
    node->next=NULL;
    N* temp =*head;
    node->next=temp;
    *head=node;
}

void insertBtw(N** head){
    printf("\n--[see the list of nodes]--\n");
    traverse(head);
    printf("after ?: ");
    int value=0;
    scanf("%d",&value);
    N* temp = *head;
    while(temp->info!=value){
        temp=temp->next;
    }
    N* node = (N*)malloc(sizeof(N));
    printf("\nProvide data = ");
    int data;
    scanf("%d",&data);
    node->info=data;
    node->next=temp->next;
    temp->next=node;

}

int main(){
    create(&head,10);
    insertEnd(&head,20);
    insertEnd(&head,30);
    insertBeginning(&head,0);
    insertBtw(&head);
    traverse(&head);
    return 0;
}