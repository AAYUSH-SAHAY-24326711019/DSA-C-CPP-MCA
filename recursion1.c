#include<stdio.h>
#include<conio.h>

void fun(int x);

void main(){
    fun(3);
    getch();
}

void fun(int x){
    if(x>0){
        printf("%d",x);
        fun(x-1);
        printf("%d",x);
        fun(x-1);
        printf("%d",x);
        fun(x-1);
    }
}