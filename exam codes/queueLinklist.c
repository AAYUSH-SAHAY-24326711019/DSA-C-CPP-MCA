#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node* next;
}N;

N* front =NULL;
N* rear =NULL;

void createQueue(N** front, N** rear,int data){    
        N* newNode = (N*)malloc(sizeof(N));
        newNode->info=data;
        newNode->next=NULL;
        *front=*rear=newNode;
}

void enqueue(N** front , N** rear,int data){
    if(*front == NULL && *rear ==NULL){
        createQueue(front,rear,data);
    }
    else{
        //insert from the rear
        N* temp = *rear;
        N* newNode = (N*)malloc(sizeof(N));
        newNode->info=data;
        newNode->next=NULL;
        temp->next=newNode;
        *rear=temp->next;
    }
}

void dequeue(N** front, N** rear){
    //if queue is empty
    if(*front ==NULL && *rear==NULL){
        printf("\nCannot dequeue , queue is empty");
        return;
    }else{
        N* temp = *front;
        printf("\nDequeued [%d] ",temp->info);
        *front = temp->next;
        free(temp);
    }
}

int main(){
    enqueue(&front,&rear,10);
    enqueue(&front,&rear,20);
    enqueue(&front,&rear,30);
    dequeue(&front,&rear);


    return 0;
}