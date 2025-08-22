//to check palindrome number

#include<stdio.h>
int main(){
    int num, original , reversed=0 , remainder=0;

    printf("\nUser give a number to check palindrome  ");
    scanf("%d",&num);
    original=num;

    printf("\nReversing the number...");
    while(num!=0){
        remainder=num%10;
        reversed=reversed*10+remainder;
        num = num/10;
    }
    if(original==reversed)
        printf("\nthe number is palindrome");
    else
        printf("\nThe number is not palindrome");

}

