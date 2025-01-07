#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<climits>

//51
//unique number of occurrences.(leet code)
//https://leetcode.com/problems/unique-number-of-occurrences/description/
//TODO


//52
// first and last position of an element in sorted array.(code studio)
//https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    pair<int, int> occ = {-1, -1};
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] < k) {
            start = mid + 1;
        }
          if (arr[mid] > k) {
            end = mid - 1;
        }
         if(arr[mid]==k) {
            occ.first = mid;
            end = mid - 1; 
        }
    }

    start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] < k) {
            start = mid + 1;
        } 
        if (arr[mid] > k) {
            end = mid - 1;
        }
         if(arr[mid]==k) {
            occ.second = mid;
            start = mid + 1;
        }
    }
     return occ;
}

//53
//find pivot index (leet code)
//https://leetcode.com/problems/find-pivot-index/description/
//TODO

//54
//square root of a number (code studio)
//https://www.naukri.com/code360/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
//TODO

//55
//Painter's Partition Problem.(code studio)
//https://www.naukri.com/code360/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
//TODO

//56
//EKO - Eko (spoj)
//https://www.spoj.com/problems/EKO/
//TODO

//57
//PRATA - Roti Prata (spoj)
//https://www.spoj.com/problems/PRATA/
//TODO

//58
//Cooking Ninjas (code studio)
//https://www.naukri.com/code360/problems/cooking-ninjas_1164174?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
//TODO

//59
//Selection sort (code studio)
//https://www.naukri.com/code360/problems/selection-sort_981162?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
//TODO

//60
//Bubble Sort (code studio)
//https://www.naukri.com/code360/problems/bubble-sort_980524?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
//TODO

