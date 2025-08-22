#include<stdio.h>
#include<stdlib.h>

int arr[]={10,20,30,40,55,60,70,80,90,100};

int linearSearch(int value, int size){
    //return index for true and return -1 for false
    for(int i=0; i<size;i++){
        if(value==arr[i]){
            return i;
        }
    }
    return -11;
}

int main(){
    int v , s;
    printf("\nUser specify the value:");scanf("%d",&v);
    s= (sizeof(arr)/sizeof(int));
    printf("\nThe size of the array is :%d",s);
    printf("\nSearching value linearly in the array");
    int result = linearSearch(v,s);
    if(result==-11)
        printf("\nValue not exist in array");
    else
        printf("\nfound at index :%d value :%2d",result,arr[result]);
    return 0;

}