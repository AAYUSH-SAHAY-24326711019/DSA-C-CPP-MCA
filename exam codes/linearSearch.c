#include<stdio.h>

int arr[]={24,36,39,47,78,87,92,112,156};

int LSA(int arr[],int size,int target){
    int loc =-1;
    for(int i =0 ; i<size; i++){
        if(arr[i]==target)
            loc =i;     
    }
    return loc;
}

int main(){
    int s = sizeof(arr)/sizeof(int);
    int value = LSA(arr,s,39);
    printf("\nValue found at index : %d",value);
    return 0;
}
//Output : Value found at index : 2