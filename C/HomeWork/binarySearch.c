#include<stdio.h>
int binarySearch(int list[],int size,int value){
  int low=0,high=size-1,mid,result;
  while(low<=high){
    mid=(low+high)/2;
    if(value<list[mid]){
    high=mid-1;
    }else if(value>list[mid]){
    low=mid+1;
  }else{
    return mid;
  }
  return -1;
}
}

// optimized version of binary search in only one if condition inside loop.
int binarySearch2(int list[], int size, int value) {
    int low = 0, high = size - 1, mid, result = -1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (value < list[mid]) {
            high = mid - 1;
            result = high;
        } else {
            low = mid + 1;
            result = mid;
        }
    }

    return (list[result] == value) ? list[result] : -1;
}
int main(){
  int arr[6]={2,3,7,11,23,37};
  //printf("%d",binarySearch(arr,4,100)); 
  printf("%d",binarySearch2(arr,6,7));
  return 0;
}
