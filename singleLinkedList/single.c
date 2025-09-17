#include<stdio.h>
#include<stdlib.h>

//----------[Task 2]-----------
//1. Creating a node structure
typedef struct node{
    int info; 
    struct node* next;
}N;
//2. Creating head pointer
N *head =NULL;

//3. creating c_list function
void c_list(N **head){
    *head=NULL;
}
//----------[Task 2]-----------


//---------[Task 3]---------
//1. inserting at the end
    void ins_end(N** head, int item){
        //1.1 create a node and location pointer
            N *ptr, *loc;
            ptr=(N*)malloc(sizeof(N));
            ptr->info=item; //providing the value to the info field
            ptr->next=NULL; // making the next field null

        //1.2 if list empty make it the first node
        if(*head ==NULL){
            *head=ptr;
        }
        //1.3 else traverse to the final node and attach it,
        else{
            loc=*head; //initially start from head pointer
            while(loc->next!=NULL){
                loc=loc->next;
            }//exit from loop when the last node next field is found null
            loc->next=ptr; // assign address of the ptr to the next field of last node
        }

    }

    void trav(N *head){
        while(head!=NULL){
            printf("[%2d]",head->info);
            printf("-");
            head=head->next;
        }
    }

    //2. Adding a function to insert at beginning

    void ins_beg(N** head, int item){
        //2.1 make a node
        N *ptr = (N*)malloc(sizeof(N));
        //2.2 provide the input to the field.
        ptr->info= item;
        //2.3 if the head is null the make it the first node
        if(*head==NULL){
            ptr->next=NULL; //then make the next field as null
        }
        //2.4 provide the address of the node of node ->next
        else{
            ptr->next=*head;
        }
        //2.5 finally make the node the 1st node by
        *head=ptr;
    }

//---------[Task 3]---------


//---------[Task 4]-----------
//4.1 implement the search function : assuming list unsorted
N * search1(N* head,int item){
    while((head!=NULL)&& (head->info!=item)){
        head=head->next;
    }//it will exit loop when item found , returns location
    return head;
}

//4.2 implement the add after function 
void ins_aft(N* head,int after,int item){
    N*ptr = (N*)malloc(sizeof(N));//make a node
    N* loc=search1(head,after);//get location of specific node after searching
    if(loc==NULL)//return from function if the list has that element absent.
        return;
    ptr->info=item;//take input in the value of new node
    ptr->next=loc->next;//prove the loc->next in the ptr->next field
    loc->next=ptr;//update the next field of loc , give it address of new node
}
//---------[Task 4]-----------


int main(){
    int key = 1;
    int choice =0,choice1=0,input=0,after=0;
    while(key){
        printf("\n1. Press 1 to create a single linklist ");
        printf("\n2. Press 2 to insert a node in single linklist");
        printf("\n3. Press 3 to traverse single linklist ");
        printf("\n4. Press 0 to exit program");
        printf("\nUser provide your choice =>");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("\nexiting the program...\n\n");
                key=0;
            break;

            case 1 :
                printf("\nCreating a single linklist\n");
                c_list(&head); // passing head pointer
            break;

            case 2 :
                
                printf("\ninserting a node at start \n");
                printf("\n\t1. Press 1 to insert from the end.");
                printf("\n\t2. Press 2 to insert from the start.");
                printf("\n\t3. Press 3 to insert after a particular node.");
                printf("\n\t4. Press 0 to go back");
                printf("\n\tUser give input = ");
                scanf("%d",&choice1);
                switch(choice1){
                    case 0:
                    break;

                    case 1:
                        printf("\nAdding element at end\n");
                        printf("\nUser provide input =");
                        scanf("%d",&input);
                        ins_end(&head,input);
                    break;

                    case 2:
                        printf("\nAdding element at start\n");
                        printf("\nUser provide input =");
                        scanf("%d",&input);
                        ins_beg(&head,input);
                    break;

                    case 3:
                        printf("\nAdding node after specific node \n");
                        printf("\n\tSee the list :");
                        trav(head);
                        printf("\nUser which node to add after =");
                        scanf("%d",&after);
                        printf("\nUser provide input =");
                        scanf("%d",&input);
                        ins_aft(head,after,input);
                        
                    break;

                    default:
                        break;

                }


            break;

            case 3 :
                printf("\ntraversing a single linklist\n");
                trav(head);
            break;
            
            default:
                printf("\nuser give a valid input\n");
            

        }



    }

    return 0;
}