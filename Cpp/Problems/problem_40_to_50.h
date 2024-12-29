#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<climits>

//41
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

//42
//find pivot element in array
int getPivot2(int arr[],int n){
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

//43
// sqrt of number using binary search .(leet code).

int sqrt_of_number(int n){// integer only
int s=0;
int e=n;
long long int mid=s+(e-s)/2;// to handle the interger overflow long long int.
long long int ans=-1;
while(s<=e){
if(mid*mid==num){
return mid;
}
if(mid*mid>n){
e=mid-1;
}
if(mid*mid<n){
   ans=mid; 
    s=mid+1;
}
mid=s+(e-s)/2;
}
return ans;
}

// have decimal values also
double real_sqrt(int n,int precision, int tempsol){
double factor=1;
double ans=tempsol;
for(int i=0;i<precision;i++){
factor=factor/10;
for(double j=ans;j*j<n;j=j+factor){
ans=j;
}
}
return ans;
}


//44

// Book Allocation problem
//refer to notes for full disciption (code studio.)

// find  if the allocation of pages is possible.
bool isPosssible( vector<int>arr, int n, int m, int mid){
int studentCount = 1;
int pageSum = 0;
for(int i=0 ; i< n; i++){
if( pageSum + arr[i] <= mid ){
pageSum += arr[i];
}
else{
studentCount++;
if( studentCount > m || arr[i] > mid ){
    return false;
}
pageSum = arr[i];

}
}
return true;
}

int allocate(vector<int> arr, int n , int m) {
    for(int i = 0; i < n; i++) {
    }
    cout << endl;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i]; 
    }
    int ans = -1;
    int start = 0;
    int end = sum;
    int mid = start + (end - start) / 2;
    while(start <= end) {
        if(isPosssible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}


//45
//AggressiveCows
bool isPossible(vector<int> &stalls, int k, int mid){
int cowCount = 1;
int lastPos = stalls[0];

for(int i=0; i<stalls.size(); i++){
    if(stalls[i]-lastPos >= mid){
        cowCount++;
        if(cowCount==k){
            return true;
        }
        lastPos = stalls[i];
    }
}
    return false;
}

int aggressiveCows(vector<int> &stalls,int k){
sort(stalls.begin(),stalls.end());
int s = 0;
int e = stalls[stalls.size()-1];
int ans = -1;
int mid = s+(e-s)/2;

while(s<=e){
    if(isPossible(stalls,k,mid)){
        ans = mid;
        s = mid +1;
    }else{
        e = mid-1;
    }
    mid = s+(e-s)/2;
}
return ans;
}

//46
//peak index in mountain array(leet code;)
//love babbr bahiya

int peak_index_mountain_array(std::vector<int>&arr){
int s=0;
int e=arr.size()-1;
int mid=s+(e-s)/2;
while(s<e){
if(arr[mid]<arr[mid+1]){
  s=mid+1;
}else{
e=mid;
}
mid=s+(e-s)/2;
}
return s;
}

//by me
int peakIndexInMountainArray(vector<int>& arr) {
  int start=0;
  int end=arr.size()-1;
  int mid=(start+end)/2;
  while(start<end){
// s<e because we will making extra comparsion if we do so code will work fine.
      if(arr[mid-1]<arr[mid]&&arr[mid]>arr[mid+1])
      {
         return mid;
      }
      if(arr[mid]<arr[mid+1]){
      start=mid+1;
      }
      if(arr[mid]>arr[mid+1]){
      end=mid;
      }
      mid=(start+end)/2;
  }
  return -1;
}

