//40

//sort 0 1 2
#include<iostream>
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        std::cout<<arr[i];
    }
}
void Sort(int arr[],int size){
    int start=0;
    int end=size-1;
    while(start<end){
        if(arr[start]==0){
            start++;
        }
        if(arr[end]==2){
        end--;
        }
        if(arr[start]>arr[end]){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
        if(arr[start]!=arr[end]){
            start++;

        }
    }
}
int main(){
    int arr[6]={0,1,2,2,1,0};
    Sort(arr,6);
    printArray(arr,6);
    return 0;
}
