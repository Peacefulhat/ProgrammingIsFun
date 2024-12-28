//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

//Input: nums = [1,3,5,6], target = 5
//Output: 2
//You must write an algorithm with O(log n) runtime complexity.

#include<iostream>
#include<vector>
 int searchInsert(std::vector<int>& nums, int target) {
     int start=0;
     int end=nums.size()-1;
     int mid=(start+end)/2;
    while(start<=end){
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]>target){
            end=mid-1;
        }
        if(nums[mid]<target){
            start=mid+1;
        } 
      mid=(start+end)/2;
    }
        return target<nums[mid]?mid:mid+1;
    }

int main(){
  std::vector<int>num={1,3,5,6};
  std::cout<<searchInsert(num,5);
  return 0;
}
