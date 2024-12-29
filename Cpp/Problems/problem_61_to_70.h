#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<climits>

//61
// Insertion sort (code studio)
//https://www.naukri.com/code360/problems/insertion-sort_3155179?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
//TODO

//62
//Reverse the Array(code studio)
//https://www.naukri.com/code360/problems/reverse-the-array_1262298?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio3
void reverseArray(vector<int> &arr , int m){
    int start=m+1;
    int end=arr.size()-1;
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        end--;
        start++;
    }    	
}

//63
//Merge Sorted Array (leet code)
//https://leetcode.com/problems/merge-sorted-array/description/
//TODO

//64
//Move Zeros (leet code)
//https://leetcode.com/problems/move-zeroes/description/
//TODO

//65
//Sum of Two Arrays (code studio)
//https://www.naukri.com/code360/problems/sum-of-two-arrays_893186?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_4
//TODO

//67
//Check if Array is Sorted and Rotated (leet code)
//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
//TODO


//68
//Rotate Array (leet code)
//https://leetcode.com/problems/rotate-array/description/
//TODO

//69
//Reverse String (leet code)
//https://leetcode.com/problems/reverse-string/description/
//TODO

//70
//Check is The String Is A Palindrome
//https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_5
//TODO


