#include <stdio.h>


void findSubArr(int arr[], int size, int windowSize);
int sum=0;
int arr[] = {3, 8, 2, 5, 7, 6, 12};

void findSubArr(int arr[], int size, int windowSize) {
    //invalid window size
    if(windowSize<=0 || windowSize>size){
        printf("\nWindow size invalid..");
    }
    //1st window of 4 from index 0 to 4(4-1=3)
    for(int i=0; i<windowSize;i++){
        sum+=arr[i];
    }
    int maxValue=sum;
    printf("\nWindow [0...%d] Sum = %d",(windowSize-1),sum);

    //time to slide
    for(int i=1; i<size-windowSize+1;i++){
        sum = sum - arr[i-1]+arr[i+windowSize-1];
        if(sum>maxValue)
            maxValue=sum;
        printf("\nWindow [%d...%d] Sum = %d",i,(i+windowSize-1),sum);
    }
    printf("\nMax Sum Value = %d",maxValue);
}

int main() {
    int s = sizeof(arr) / sizeof(int);
    findSubArr(arr, s, 4);
    return 0;
}

/*output
Window [0...3] Sum = 18
Window [1...4] Sum = 22
Window [2...5] Sum = 20
Window [3...6] Sum = 30
Max Sum Value = 30
*/