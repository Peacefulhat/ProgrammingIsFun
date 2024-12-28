/*1480. Running Sum of 1d Array
Easy

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> runningSum(vector<int>&nums){
  vector<int>sum;
  int sum2=0;
  for(int i=0;i<nums.size();i++){
    sum2=sum2+nums[i];
    sum.push_back(sum2);
  }
  
  return sum;
}

int main(){
  vector<int>nums={1,2,3,4};
  runningSum(nums); 
  return 0;
}
