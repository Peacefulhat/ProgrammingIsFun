#include<iostream>
int binarySearch(int arr[],int size,int key){
    int start=0;
    int end=size-1;
   // int mid=(start+end)/2; 
   int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){// go to right part.
            start=mid+1;
        }
        if(key<arr[mid]){//go to left part.
            end=mid-1;
        }
     mid=(start+end)/2;
    }
    return -1;

}
int main(){
    int even[6]={2,4,6,8,12,14};
    int odd[5]={1,3,5,7,9};
    std::cout<<binarySearch(even,6,3)<<std::endl;
    std::cout<<binarySearch(odd,5,7);
    return 0;
}