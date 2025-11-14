#include<stdio.h>

int arr[]={24,36,39,47,78,87,92,112,156};

int BSA(int arr[],int size,int target){
    int low =0; 
    int high = size;
    int loc =-1;
    for(int i =low ; i<high; i++){
        int mid = (low+high)/2;
            if(target < arr[mid]){
                high=mid;
            }
            else if(target>arr[mid]){
                low=mid;
            }
            else{ // target =arr[mid]
                loc=mid;
                return loc;
            }
    }
    return loc;  
}
int main(){
    int s = sizeof(arr)/sizeof(int);
    int value = BSA(arr,s,39);
    printf("\nValue found at index : %d",value);
    return 0;
}