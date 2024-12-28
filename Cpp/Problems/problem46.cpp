//46

#include<iostream>
#include<vector>
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
  while(start<end){// s<e because we will making extra comparsion if we do so code will work fine.
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
int main(){
std::vector<int>arr={1,2,3,5,4,3,1,0};
std::cout<<peak_index_mountain_array(arr)<<"\n";
return 0;
}
