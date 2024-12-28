
/* Find First and Last Position of Element in Sorted Array
(leetcode)

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

*/ 
#include<iostream>
#include<vector>
  int first(vector<int>&num,int key){
        int start=0;
        int ans=INT_MIN;
        int end= num.size()-1;
        int mid=start+((end-start)/2);
        while(start<=end){
            if(num[mid]==key){
                ans=mid;
                end=mid-1;
            }
            if(num[mid]<key){
                start=mid+1;
            }
            if(num[mid]>key){
                end=mid-1;
            }
            mid=start+((end-start)/2);
        }
        return ans==INT_MIN?-1:ans;
    }
      int last(vector<int>&num,int key){
        int start=0;
        int ans=INT_MAX;
        int end= num.size()-1;
          int mid=start+((end-start)/2);
        while(start<=end){
            if(num[mid]==key){
                ans=mid;
                start=mid+1;
            }
            if(num[mid]<key){
                start=mid+1;
            }
            if(num[mid]>key){
                end=mid-1;
            }
            mid=start+((end-start)/2);
        }
        return ans==INT_MAX?-1:ans;
    }
int main(){
  return 0;
}
