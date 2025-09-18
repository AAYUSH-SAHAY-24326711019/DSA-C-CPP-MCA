#include<stdio.h>
#include<stdlib.h>

//------[Task 2]------
//representation of doubly linklist
typedef struct node{
    struct node *prev;
    int info;
    struct node *next;
}N;

N* head = NULL;
N* tail = NULL;
//------[Task 2]------

//------[Task 3]------
//creation of a doubly link list
void create(N** head, N** tail){
    *head = NULL;
    *tail = NULL;
    //when empty , head and tail pointers hold adress of no nodes.
}
//------[Task 3]------

int main(){
    int key=1,choice1=0;
    while(key){
        printf("\nUser follow the instructions.");
        printf("\n1. Press 1 to create a Doubly LinkedList");
        printf("\n2. Press 2 to insert nodes.");
        printf("\n3. Press 3 to traverse the list.");
        printf("\n4. Press 4 to implement deletion process");
        printf("\n PRESS 0 TO EXIT.");
        printf("\nUser give input =");
        scanf("%d",&choice1);
        switch(choice1){
            case 0:
                printf("\n\tExiting the program ...");
                key=0;
            break;

            case 1:
                printf("\n\t Created a Doubly Linked List\n");
                create(&head,&tail);
            break;

            case 2:
                printf("\n\t inserting nodes in Doubly Linked List\n");
            break;

            case 3:
                printf("\n\t Traversing the Doubly Linked List\n");
            break;

            case 4:
                printf("\n\t Implementing Deletion in Doubly Linked List\n");
            break;

        }

    }


    return 0;
}