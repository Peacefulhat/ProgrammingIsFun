//33

// reversing of array
#include<iostream>

void printArray(int arr[],int size){
for(int i=0;i<size;i++){
 std::cout<<arr[i]<<" ";
  }
  std::cout<<"\n";
}

void reverse(int arr[],int size){
  int start=0,end=size-1;
  for(;start<=end;){
    int temp=arr[start];
      arr[start++]=arr[end];
      arr[end--]=temp;
  }
 
}

int main()
{
int arr[6]={1,2,3,4,5,6};
  reverse(arr,6);
  printArray(arr,6);
return 0;
}
