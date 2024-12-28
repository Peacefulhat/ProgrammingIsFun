#include<iostream>
int peak(int arr[],int size){
    int start=0;
    int end=size-1;
     int mid=start+(end-start)/2;
    while(start<=end){
        mid=start+(end-start)/2;
        if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]){
            end=mid;
            return mid;
        }
        if(arr[mid]<arr[mid+1]){
            start=mid+1;
        }
    if(arr[mid]>arr[mid-1]){
        end=mid-1;
    }

    }
    return mid;
    
}
int main(){
    int arr[4]={3,4,5,1};
    std::cout<<peak(arr,4);
    return 0;
}