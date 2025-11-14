//implementation of queue using array

#include<stdio.h>
#include<stdlib.h>
#define Max 5
int front =-1;
int rear=-1;
int Queue[Max];
void insert(){
    int data;
    if(rear==Max-1){
        printf("\nQueue full / overflow problem");
        return;
    }else{
        if(front==-1){
            front =0; rear=0;
        }else{
            rear=rear+1;
        }
    }
    printf("\nEnter Data(int):");scanf("%d",&data);
    Queue[rear]=data;
}

void delete(){
    if(front==-1){
        printf("\nThe queue is empty...");
    }else{
        printf("\nThe deleted Data is: %d\n",Queue[front]);
        if(front==rear){
            front=-1; rear=-1;
        }else{
            front=front+1;
        }
    }
}

void traversal(){
    for(int i=front;i<=rear;i++){
        printf("%3d",Queue[i]);
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