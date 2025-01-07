#include<iostream>
// check if array is sorted or not using recursion
bool is_sorted(int *arr,int size){
  if(size==0|| size=1) return true;
  if(arr[0]>arr[1]){
    return false;
  }else{
    bool sorted=is_sorted(arr+1, size-1);
    return true;
}

  // Todo
  // linear search using recursion
  // make recuriosn tree if not able to watch video
  // key point where its pausing

  //Todo
  // binary search
  // using recursion
  
int main(){
  return 0;
}
