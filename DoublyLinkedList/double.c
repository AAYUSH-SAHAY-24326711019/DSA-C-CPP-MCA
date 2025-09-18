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

//------[Task 4]------
//traversal operation : forward direction
void trav1(N* head){
    while(head!=NULL){
        printf("\t-[%2d]-",head->info);//print info
        head=head->next;//move to the next node.
    }
}//forward direction uses the head pointer

//traversal operation : backward direction
void trav2(N* tail){
    while(tail!=NULL){
        printf("\t-[%2d]-",tail->info);//print info
        tail=tail->prev;//move to the preveous node
    }
}// forward direction uses the tail pointer
//------[Task 4]------

//------[Task 5]------
//insertion operation in the list : beginning
void ins_beg(N** head, N** tail,int item){
    N* ptr = (N*)malloc(sizeof(N));//make a node
    ptr->info=item;//provide the item to info field
    if(*head==NULL){//maybe its the first node
        ptr->next=ptr->prev=NULL;//1st make the prev and next field of node as null
        *head=*tail=ptr;//2nd provide address of new node(ptr) to both head and tail
    }
    else{
        ptr->prev=NULL;//1st make the prev as null of new node
        ptr->next=(*head);//2nd , assign the address inside head to next field of ptr
        (*head)->prev=ptr;//3rd in the preveous field of node assigned to head pointer , assign address of ptr
        //assign the address of the 1st node to the head pointer
        *head =ptr;
    }
}

//------[Task 5]------

int main(){
    int key=1,choice1=0,choice2=0,choice3=0,input=0;
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
                printf("\n\t1. press 1 for insertion at begining");
                printf("\n\t3. PRESS 0 TO GO BACK TO MENU");
                printf("\n\t User give input =");
                scanf("%d",&choice3);
                switch(choice3){
                    case 0:
                    break;

                    case 1:
                        printf("\n\t Inserting in Begining\n");
                        printf("\n\t User provide input =");
                        scanf("%d",&input);
                        ins_beg(&head,&tail,input);
                        printf("\n\t Value inserted \n");
                        break;

                    default:
                        break;
                }
            break;

            case 3:
                printf("\n\t Traversing the Doubly Linked List\n");
                printf("\n\t1. press 1 for forward traversal");
                printf("\n\t2. Press 2 for backward traversal");
                printf("\n\t3. PRESS 0 TO GO BACK TO MENU");
                printf("\n\t User give input =");
                scanf("%d",&choice2);
                switch(choice2){
                    case 0:
                    break;

                    case 1:
                        printf("\n\t Traversing in forward manner\n");
                        trav1(head);
                    break;

                    case 2:
                        printf("\n\t Traversing in backward manner\n");
                        trav2(tail);
                    break;

                    default:
                        break;
                }
            break;

            case 4:
                printf("\n\t Implementing Deletion in Doubly Linked List\n");
            break;

            default:
                printf("\n\tUser give proper input...\n\n");

        }

    }


    return 0;
}