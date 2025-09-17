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

//---------[Task 5]-----------
//5.1 implementing searching in the sorted list
N * search2(N* head,int item){
    while(head!=NULL){//search until reaching the last node
        if(head->info ==item)//if the head->info has element return head position
            return head;
        //it can be the element is less than head->info
        //Since, all elements exist in increasing value manner,
        else if(item<head->info)
            return NULL;  //in that case nothing to return
        else
            head=head->next; //if not found then check the next node
    } //exit from loop when last node is reached (node->next=NULL)
    return NULL ;
}

//---------[Task 5]-----------

//--------------[Task 6]--------------
//6.1 delete from the beginning
void del_beg(N **head){
    N* ptr;//make a node
    if(head==NULL)//if list is empty then return
        return;
    else{
        ptr=*head;//give address of head to new node (head holds add. of 1st node)
        //assign the address of the next node i.e head->next in the head
        *head=(*head)->next;
        //free the node that contains the add
        free(ptr);
    }
}
//6.2 Deleting from the end of the list
void del_end(N** head){
    N* ptr;//make a temporary node
    N *loc;//make a pointer to store the location of last node
    if(*head==NULL)//if list is empty, head is null, then return
        return;
    else if((*head)->next==NULL){//possibly be the 1st node in the list
        ptr=*head;//store the address of head in ptr
        *head=NULL;//set the head pointer to be null
        free(ptr);//free the pointer
    }
    //else loop to the end of the list
    else{
        //provide loc pointer the address stored inside head (contains add of 1st node)
        loc=*head;
        //provide the ptr node the address in the next of 1st node
        ptr=(*head)->next; //ptr holds address of 2nd node
        while(ptr->next!=NULL){ // move until last node is reached
            loc=ptr;
            ptr=ptr->next;
        } //exit from the loop when ptr is having address of last node
        //and loc holds the address of the second last node.
        
        loc->next = NULL;//disconnect second last node and last node
        free(ptr);//free the memory of the last node.
    }

}
//--------------[Task 6]--------------




int main(){
    int key = 1;
    int choice =0,choice1=0,input=0,after=0,choice2=0,choice3=0;
    while(key){
        printf("\n1. Press 1 to create a single linklist ");
        printf("\n2. Press 2 to insert a node in single linklist");
        printf("\n3. Press 3 to traverse single linklist ");
        printf("\n4. Press 4 to search a node in single linklist ");
        printf("\n5. Press 5 to initiate deletion in single linklist ");
        printf("\n5. Press 0 to exit program");
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

            case 4 :
                printf("\nSearching node in single linklist\n");
                printf("\n\t1. Press 1 to search if unsorted list.");
                printf("\n\t2. Press 2 to search if sorted list.");
                printf("\n\t3. Press 0 to go back");
                printf("\n\tUser give input = ");
                scanf("%d",&choice2);
                switch(choice2){
                    case 0:
                    break;

                    case 1:
                        printf("\n\tsearching in unsorted list\n");
                        printf("\nUser provide input =");
                        scanf("%d",&input);
                        N* temp=search1(head,input);
                        printf("[%d],(address : %p)",temp->info,(void *)temp);
                    break;

                    case 2:
                        printf("\nSearching in sorted list\n");
                        printf("\nUser provide input =");
                        scanf("%d",&input);
                        N* temp1=search1(head,input);
                        printf("[%d],(address : %p)",temp1->info,(void *)temp1);
                        
                    break;

                    default:
                        break;

                }
            break;

            case 5:
                printf("\nDeleting node in single linklist\n");
                printf("\n\t1. Press 1 to delete from beginning");
                printf("\n\t2. Press 2 to delete from the end");
                printf("\n\t3. Press 3 to delete entire list");
                printf("\n\t3. Press 4 to delete after specific node");
                printf("\n\t3. Press 0 to go back");
                printf("\n\tUser give input = ");
                scanf("%d",&choice3);
                switch(choice3){
                    case 0:
                    break;

                    case 1:
                        printf("\nDeleting node from begining\n");
                        trav(head);
                        del_beg(&head);
                        printf("\n\tNew List :");
                        trav(head);
                    break;

                    case 2:
                        printf("\nDeleting node from end of list\n");
                        trav(head);
                        del_end(&head);
                        printf("\n\tNew List :");
                        trav(head);
                    break;

                    default:
                    break;
                    

                }
            break;

            default:
                printf("\nuser give a valid input\n");
        }
    }
    return 0;
}