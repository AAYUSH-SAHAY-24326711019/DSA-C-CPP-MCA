//implementation of Stack
//Taking input integer and converting into Octal.
#include<stdio.h>
#include<stdlib.h>
#define Max 100
int top=-1;
int stack[Max];

void push(int data){
    if(top==Max-1){
        printf("\nUnable to resolve in 64 bits");
        return;
    }else{
        stack[++top]=data;
    }
}

int pop(){
    if(top==-1){
        printf("\nThe stack is empty cannot pop");
        return 0;
    }else{
        return stack[top--];
    }
}

void peep(){
    if(top==-1){
        printf("\nthe stack is empty");
    }else{
        for(int i=top; i>=0;i--){
            printf("index[%2d] %d\n",i,stack[i]);
        }
    }
}

int main(){
    int choice , value;;
    while(1){
        printf("\n1.To add data to the stack");
        printf("\n2.To view the contents of the stack");
        printf("\n3.To pop the elements from the stack in octal");
        printf("\n4.To exit from the program");
        printf("\n\tUser give your choice->");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                printf("\nprovide int value to push=>");
                scanf("%d",&value);
                while(value>0){
                    push(value%8);
                    value=value/8;
                }
                break;
            case 2: peep(); break;
            case 3: 
                while(top!=-1){
                    printf("%3d",pop());
                }
                break;
            case 4: exit(0); break;
            default: printf("\nKindly give a valid choice");
        }
    }
    return 0;
}