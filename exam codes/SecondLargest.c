#include<stdio.h>
void findSecondLargest(int a[],int size);
int arr[] = {1,2,3,4,5,6,7,8,9};
int max1,max2=0;

void findSecondLargest(int a[],int size){
    if(a[0]>a[1]){
        max1=a[0]; 
        max2=a[1];
    }else{
        max1=a[1];
        max2=a[0];
    }
    for(int i=1;i<size;i++){
        if(a[i]>max1){
            max2=max1;
            max1=a[i];
        }
        else if(a[i]>max2){
            max2=a[i];
        }
    }
    printf("[Largest no.] = %d\n[Second Largest] = %d",max1,max2);
}

int main(){
    int s = sizeof(arr)/sizeof(int);
    findSecondLargest(arr,s);
    return 0;
}

/*output
[Largest no.] = 9
[Second Largest] = 8
*/