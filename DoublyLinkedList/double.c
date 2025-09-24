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

//------[Task 6]-------
//Insertion at the last
void ins_end(N** head, N** tail,int item){
    N *ptr=(N*)malloc(sizeof(N)); //make a new node
    ptr->info=item;//take input to the info part
    //if head and tail are null : means its the 1st and last node
    if(*head==NULL){
        //make the prev and next filed of new node(ptr)as null
        ptr->prev=ptr->next=NULL;
        //give the address of the new node(ptr) to head and tail
        *head=*tail=ptr;
    }else{
        //list has nodes , adding at the end of list , make next node null
        ptr->next=NULL;
        //tail holds the address of last node , give in prev of ptr
        ptr->prev=*tail;
        // Since tail contains address of last node , 
        //update the next field of the last node , give it address of ptr
        (*tail)->next=ptr;
        //now give the address of the newly created node to the tail.
        *tail = ptr;
    }
}

//------[Task 6]-------

//------[Task 7]-------
//Inserting after a given element

//need to implement forward searching : needs head pointer
N *search1(N*head,int item){
    //while head not null : means until not reached the last node
    while(head!=NULL){
        //check each node info part comparing to item provided
        if(head->info==item){
            //item found then return the address of node stored in head
            return head;
        }
        //else part keep moving to next node in forward direction
        head=head->next;
    }//out of loop means item was not found
    return NULL;
}

//need to implement Backward Searching needs tail pointer
N *search2(N*tail,int item){
    // while tail is not null : means while searching the 1st node not reached
    while(tail!=NULL){
        //check the info field of all the nodes whose address contain inside tail
        if(tail->info==item){
            //return the address of node contained inside tail
            return tail;
        }//else move to preveous node current node
        tail=tail->prev;
    }//out of the loop means value was not inside list
    return NULL;
}

//adding ins_aft function
void ins_aft(N** head, N** tail, int after, int item){
    N* loc;//make a location pointer
    //assuming search from beginning and last have same time complexity
    loc=search1(*head,after); //since search from head is forward search
    //search and store the location.
    if(loc==NULL){
        //means the value provided by user not the part of list
        return ;
    }//control exits the else block
    N *ptr = (N*)malloc(sizeof(N));//make a node
    ptr->info=item;//take input to the info field
    //Now Case 1 : Assuming : to add after last node
    if(loc->next==NULL){
        ptr->next=NULL; //make the ptr last node. Since next field is null
        //update the next field of the last node (addr contained inside loc)
        loc->next=ptr;
        //update the prev field of the ptr with the address inside tail
        //since tail contains address of last node
        ptr->prev=*tail;
        //give the address of ptr to the tail
        *tail=ptr;
    }
    //Case 2 : Any node other than the last node
    else{
        //give the address of loc in the prev field of ptr
        ptr->prev=loc;
        //assign the next field of the loc to next field of ptr
        ptr->next=loc->next;
        //update the prev. field of the next node of node contained inside the loc with ptr
        (loc->next)->prev=ptr;
        //make the ptr next field of the node whose address inside loc
        loc->next=ptr;
    }
}

//------[Task 7]-------

//------[Task 8]-------
//Adding function to insert a node before a specific node

void ins_bef(N **head,N **tail, int before, int item){
    //make a location pointer
    N *loc;
    // search and store the address of the desired node
    loc = search1(*head,before); //forward search
    if(loc==NULL){ //maybe user input be not inside list
        return; //control exits the body of if statement
    }
    //make the node
    N* ptr = (N*)malloc(sizeof(N));
    //take input in info field
    ptr->info=item;
    //case 1 : may be the 1st node , we try to add before the 1st node.
    if(loc->prev==NULL){
        //make the prev field of the ptr as null
        ptr->prev=NULL;
        //assign the address contained inside head (of 1st node)
        //to the next field of the newly created node(ptr)
        ptr->next=*head;
        // update the prev field of node inside loc with address of ptr
        loc->prev=ptr;
        //Since making it the 1st node , we will provide the address
        //of ptr to the head pointer
        *head=ptr;
    }//else we are adding before any node other than the 1st node
    else{
        //desired node prev value is given to the prev field of ptr
        ptr->prev=loc->prev;
        //make the loc address node the next of ptr
        ptr->next=loc;
        //update the next field of the node that lies prev. to node whose address
        //is contained inside the loc with the address of ptr
        (loc->prev)->next=ptr;
        //the prev field of the current node whose address inside in loc
        //is given the address of ptr
        loc->prev=ptr;
    }
}
//------[Task 8]-------


int main(){
    int key=1,choice1=0,choice2=0,choice3=0,input=0,input1=0;
    while(key){
        printf("\nUser follow the instructions.");
        printf("\n1. Press 1 to create a Doubly LinkedList");
        printf("\n2. Press 2 to insert nodes.");
        printf("\n3. Press 3 to traverse the list.");
        printf("\n4. Press 4 to implement deletion process");
        printf("\n4. Press 5 to implement Searching process");
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
                printf("\n\t2. press 2 for insertion at the end of list");
                printf("\n\t3. press 3 for insertion after a node");
                printf("\n\t4. press 4 for insertion before a node");
                printf("\n\t5. PRESS 0 TO GO BACK TO MENU");
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

                    case 2:
                        printf("\n\t Inserting at end of the list\n");
                        printf("\n\t User provide input =");
                        scanf("%d",&input);
                        ins_end(&head,&tail,input);
                        printf("\n\t Value inserted \n");
                    break;

                    case 3:
                        printf("\n\t Inserting after a node\n");
                        trav1(head); // 1st display the list to user
                        printf("\n\t User specify node (input-value) =");
                        scanf("%d",&input1);
                        printf("\n\t User provide input =");
                        scanf("%d",&input);
                        ins_aft(&head,&tail,input1,input);
                        printf("\n\t Value inserted \n");
                        trav1(head);//show the list after insertion
                    break;

                    case 4:
                        printf("\n\t Inserting before a node\n");
                        trav1(head); // 1st display the list to user
                        printf("\n\t User specify node (input-value) =");
                        scanf("%d",&input1);
                        printf("\n\t User provide input =");
                        scanf("%d",&input);
                        ins_bef(&head,&tail,input1,input);
                        printf("\n\t Value inserted \n");
                        trav1(head);//show the list after insertion
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