//implementation of queue using linkedlist

#include<stdio.h>
#include<stdlib.h>
#define Max 5

typedef struct node{
    int info;
    struct node* next;
}N;

N*front=NULL;
N*rear=NULL;

void insert(){
    int data;
    N* p;
    p=malloc(sizeof(N));
    printf("\nEnter data(int):"); scanf("%d",&data);
    p->info=data;
    p->next=NULL;
    if(front==NULL){
        front=rear=p;
    }else{
        rear->next=p;
    }
     rear=p;
}

void delete(){
    N*p;
    if(front==NULL){
        printf("\nNo Deletion should take place.");
        return;
    }else{
        p=front; 
        printf("\nThe deleted data is %d\n",p->info);
        if(front->next==NULL){
            front=rear=NULL;
        }else{
            front=front->next;
        }
        free(p);
    }
}

void traversal(){
    N* p;
    if(front==NULL){
        printf("\nQueue Empty , no traversal takes place");
        return;
    }else{
        p=front;
        for(;p!=NULL;p=p->next){
            printf("\t%3d",p->info);
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("\n1.To add data to the Queue [ Enqueue ]");
        printf("\n2.To view the contents of the Queue / Traversal");
        printf("\n3.To Delete the elements from the Queue [Dequeue]");
        printf("\n4.To exit from the program");
        printf("\n\tUser give your choice->");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert(); break;
            case 2: traversal(); break;
            case 3: delete();  break;
            case 4: exit(0); break;
            default: printf("\nKindly give a valid choice");
        }
    }
    return 0;
}