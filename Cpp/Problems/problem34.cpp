//34

//swap alternate values
#include<iostream>

void printArray(int arr[],int size){
for(int i=0;i<size;i++){
    std::cout<<arr[i]<<" ";
  }
  std::cout<<"\n";
}

void swapAlternate(int arr[],int size){
for(int start=0;start<size;start+=2){
    if(start+1<size){
  int temp=arr[start];
    arr[start]=arr[start+1];
    arr[start+1]=temp;
    }
  }
}


int main(){
  int arr[8]={1,2,3,4,5,82,21,2};
  swapAlternate(arr,8);
  printArray(arr,8);
  return 0;
}
