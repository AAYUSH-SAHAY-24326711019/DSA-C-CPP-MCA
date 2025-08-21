//stack implementation through array

#include<stdio.h>
#include<stdlib.h>
#define Max 5
int stack[Max];

int top=-1;
void push(){
    int data;
    if(top==Max-1){
        printf("\nThe stack is full , cannot push new data");
        return;
    }else{
        printf("Enter data(int):"); scanf("%d",&data);
        top=top+1; stack[top]=data;
    }
}

void pop(){
    if(top==-1){
        printf("\nThe stack is empty cannot pop data");
    }else{
        printf("\nThe popped data is %d",stack[top--]);
    }
}

void peep(){
    if(top==-1){
        printf("\nThe stack is empty cannot show data.");
        return;
    }else{
        printf("\n==Contents of the stack ==\n");
        for(int i =top;i>=0; i--){
            printf("%d\n",stack[i]);
        }
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