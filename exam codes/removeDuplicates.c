#include<stdio.h>

int arr[]={5,5,7,8,8,9,9,10,10};
int s = sizeof(arr)/sizeof(int);

int new_arr[9];

void removeDuplicates(int arr[],int size){
    new_arr[0] = arr[0];
    int x=0;
    for(int i =1; i<size; i++){
        if(new_arr[x]!=arr[i])
            x=x+1;
            new_arr[x]=arr[i];
    }
    

    printf("\nThe resultant array is :");
    printf("{");
    for(int i = 0; i<size; i++){
        printf("%d, ",new_arr[i]);
    }
    printf("}");

}

int main(){
    
    removeDuplicates(arr,s);
    return 0;
}

/* output
The resultant array is :{5, 7, 8, 9, 10, 0, 0, 0, 0, }
*/