/48
#include<iostream>
#include<vector>
// search in rotated sorted array (code studio.)
int getPivot(vector<int>&arr,int n){
int s=0;
int e=n-1;
int mid=s+(e-s)/2;
while(s<e){
if(arr[mid]>=arr[0]){
  s=mid+1;
}else{
  e=mid;
}
mid=s+(e-s)/2;
}
return s;
}
int binarySearch(vector<int>&arr,int s,int n,int k){

 int mid=s+(n-s)/2;
 while(s<=n){
  if(arr[mid]==k){
    return mid;
  }
  if(arr[mid]>k){
    n=mid-1;
  }
  if (arr[mid] < k) {
    s = mid + 1;
  }
  mid = s + (n - s) / 2;
 }
 return -1;
}

int search(vector<int>& arr, int n, int k)
{
int pivot=getPivot(arr,n);
int s=0;
int e=n-1;
int mid=s+(e-s)/2;
if(arr[pivot]<=k&&k<=arr[e]){
 return binarySearch(arr,pivot,n-1,k);
} else {
    return binarySearch(arr,0, pivot-1, k);
}
}

int main(){
return 0;
}
