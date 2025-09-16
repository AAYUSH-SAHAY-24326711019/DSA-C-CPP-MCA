#include<stdio.h>
#include<stdlib.h>

int main(){
    int key = 1;
    int choice =0;
    while(key){
        printf("\n1. Press 1 to create a single linklist ");
        printf("\n2. Press 2 to insert a node in single linklist (starting)");
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
            break;

            case 2 :
                printf("\ninserting a node at start \n");
            break;

            case 3 :
                printf("\ntraversing a single linklist\n");
            break;
            
            default:
                printf("\nuser give a valid input\n");
            

        }



    }

    return 0;
}