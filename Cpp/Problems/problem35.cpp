//35

// find unique
#include<iostream>

int unique(int arr[],int size){
  int unique=0;
  for(int i=0;i<size;i++){
    unique^=arr[i];
  }
return unique;
}

int main(){
  int arr[5]={1,2,34,1,2};
  //std::cout<<unique(arr,5);
  std::cout<<(13^4);
  return 0;
}
