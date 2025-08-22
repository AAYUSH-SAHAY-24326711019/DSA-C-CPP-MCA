//to linear sort the array : using bubble sort

#include<stdio.h>

int main() {
    int arr[] = {20,65,89,25,4,73,10,5,16,14};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i, j, temp;

    // Bubble Sort
    for(i = 0; i < size-1; i++) {
        for(j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nDisplaying array:");
    printf("Sorted Array: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}