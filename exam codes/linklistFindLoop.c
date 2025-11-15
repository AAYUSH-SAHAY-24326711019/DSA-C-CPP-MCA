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

void fourPointsSecond(N** head){
    N* lastNode = *head;
    while(lastNode->next!=NULL){
        lastNode=lastNode->next;
    }
    int count=1;
    N* secondNode=*head;
    while(secondNode!=NULL){
        count++;
        secondNode=secondNode->next;
        if(count==2)
            break;
    }
    lastNode->next=secondNode;
}

void findLoop(N** head){
    N* fast = *head;
    N* slow = *head;
 
    while(1){
        slow=slow->next;
        fast = fast->next->next;
        if(slow==fast){
            printf("loop exists in Linklist");
            return;
        }else{
            printf("No loop exists in Linklist\n");
            continue;
        }
    }
    
}

int main(){
    create(&head,10);
    insertEnd(&head,20);
    insertEnd(&head,30);
    insertEnd(&head,40);
    
    fourPointsSecond(&head);
    findLoop(&head);
   

    return 0;
}