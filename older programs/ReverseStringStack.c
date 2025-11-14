//implementing reversal of stack using stack
//implementation of Stack
//Taking input integer and converting into Octal.
#include<stdio.h>
#include<stdlib.h>
#define Max 100
int top=-1;
char stack[Max];

void push(char data){
    if(top==Max-1){
        printf("\nstack is full");
        return;
    }else{
        stack[++top]=data;
    }
}

char pop(){
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
            printf("index[%2d] %c\n",i,stack[i]);
        }
    }
}

int main(){
    int choice; char value[Max]; char* ptr;
    while(1){
        printf("\n1.To add string data to the stack");
        printf("\n2.To view the contents of the stack");
        printf("\n3.To pop the elements from the stack in reverse");
        printf("\n4.To exit from the program");
        printf("\n\tUser give your choice->");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                printf("\nprovide string value to push=>");
                scanf("%s",value);
                ptr=value;
                while(*ptr!='\0'){
                    push(*ptr);
                    ++ptr;
                }
                break;
            case 2: peep(); break;
            case 3: 
                while(top!=-1){
                    printf("%3c",pop());
                }
                break;
            case 4: exit(0); break;
            default: printf("\nKindly give a valid choice");
        }
    }
    return 0;
}