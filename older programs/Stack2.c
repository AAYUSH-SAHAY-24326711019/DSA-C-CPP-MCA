//implement stack using linked list
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define Max 5

typedef struct node{
    int info;
    struct node* next;
}N;

N* top =NULL;

void push(){
    N* p; int data;
    p=malloc(sizeof(N));
    printf("\nEnter data :");
    scanf("%d",&data);
    p->info=data;
    p->next=top;
    top=p;
}

void pop(){
    N*p; p=top;
    printf("\nThe popped Value is: %d",p->info);
    top=top->next;
    free(p);
}

void peep(){
    N *p;
    p=top;
    while(p!=NULL){
        printf("\t%d",p->info);
        p=p->next;
    }
}

int main(){
    int choice;
    while(1){
        printf("\n1.To add data to the stack");
        printf("\n2.To view the contents of the stack");
        printf("\n3.To pop the elements from the stack");
        printf("\n4.To exit from the program");
        printf("\n\tUser give your choice->");
        scanf("%d",&choice);
        switch(choice){
            case 1: push(); break;
            case 2: peep(); break;
            case 3: pop();  break;
            case 4: exit(0); break;
            default: printf("\nKindly give a valid choice");
        }
    }
    return 0;
}
