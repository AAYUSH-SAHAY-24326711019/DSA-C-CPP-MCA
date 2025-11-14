#include<stdio.h>

void findTargetSum(int arr[],int size,int target);
//we want target sum = 15
int arr[]={1,2,3,5,7,10,11,15};

void findTargetSum(int arr[],int size,int target){
    int left=0; int right = size-1;

    while(left<right){ //greedy approach
        int currentSum = arr[left]+arr[right];

        if(currentSum == target){
            printf("(%d+%d)=%d",arr[left],arr[right],target);
            break;
        }
        else if(currentSum<target){
            left++;
        }
        else{ //current sum>target sum 
            right--;
        }
    }
}
int main(){
    int s = sizeof(arr)/sizeof(int);
    findTargetSum(arr,s,15);
    return 0;
}
//output:(5+10)=15
