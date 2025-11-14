#include<stdio.h>

void findSubArr(int arr[], int size, int windowSize);
int arr[]={3,8,2,5,7,6,12};
int sum,maxValue=0,jv=0;

void findSubArr(int arr[], int size, int windowSize){
    for(int i = 0 ; i<size-windowSize+1; i++){
        for(int j = i; j<=windowSize+i-1; j++){
            sum+=arr[j];
            maxValue=sum;
            jv=j;
        }
        printf("Window [%d...%d] Sum = %d\n",i,jv,sum);
        if(sum>maxValue){
            maxValue=sum;
        }
        sum=0;
    }
    printf("max value is = %d",maxValue);
}


int main(){
    int s = sizeof(arr) / sizeof(int);
    findSubArr(arr, s, 4);
    return 0;
}

/*output
Window [0...3] Sum = 18
Window [1...4] Sum = 22
Window [2...5] Sum = 20
Window [3...6] Sum = 30
max value is = 30
*/