#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<climits>
//31
// nth fibonacci number
int fibonaci(int n){
  int a=0;
  int b=1;
  int c;
  for(int i=1;i<=n;i++){
  c=a+b;
  a=b;
  b=c;
  }
  return c;
}

//32
//max and min value in array
void maxMin(int arr[],int size){
int max=arr[0];
int min=arr[0];
for(int i=0;i<size;i++){
 if(arr[i]>max){
      max=arr[i];
    }
  if(arr[i]<min){
      min=arr[i];
    }
  }
 std::cout<<"Min and Max value of array: "<<min;
}

//33
// reverseing of array

void printArray(int arr[],int size){
for(int i=0;i<size;i++){
 std::cout<<arr[i]<<" ";
  }
  std::cout<<"\n";
}

void reverse(int arr[],int size){
  int start=0,end=size-1;
  for(;start<=end;){
    int temp=arr[start];
      arr[start++]=arr[end];
      arr[end--]=temp;
  }
}


//34
//swap alternate values

void swapAlternate(int arr[],int size){
for(int start=0;start<size;start+=2){
    if(start+1<size){
  int temp=arr[start];
    arr[start]=arr[start+1];
    arr[start+1]=temp;
    }
  }
}

//35
// find unique.(code studio)
//https://www.naukri.com/code360/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&isSignin=true&leftPanelTabValue=SUBMISSION
int unique(int arr[],int size){
  int unique=0;
  for(int i=0;i<size;i++){
    unique^=arr[i];
  }
return unique;
}

//36
//find duplicate in array (code studio)
//https://www.naukri.com/code360/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTabValue=SUBMISSION

int duplicate(int arr[],int size){
int sum =0;
sum = ((size-1)*(size))/2;
int sum2=0;
for(int i=0;i<size;i++){
sum2+=arr[i];
}
return sum2-sum;
}

int duplicateWithXor(int arr[]){
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];
    }
    for(int i=1;i<size;i++){
        ans=ans^i;
    }
    return ans;
}


//37
//intersection of arrays(code studio)
//https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1

//brute force method
void findArrayInstersection(int arr[], int n,int arr2[] ,int m ){
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(arr[i]<arr2[j]){
            break;
        }
        if(arr[i]==arr2[j]){
            std::cout<<arr2[j]<<" ";
            arr2[j]=INT_MIN;
            break;
        }
    }
}}

//2 pointer approach
void findArrayInstersection2(int arr[],int n,int arr2[],int m){
    int i=0,j=0;
    while(i<n&&j<m){
       if(arr[i]<arr2[j]){
        i++;
       } 
       if(arr[i]==arr2[j]){
       std::cout<<arr[i]<<" " ;
        i++;
        j++;
       }
       if(arr[i]>arr2[j]){
        j++;
       }
    }
}

//38
// pair sum (code studio)
//https://www.naukri.com/code360/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1
void  pairSum(int arr[],int size,int sum){
 for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        if(arr[i]+arr[j]==sum){
            std::cout<<"{"<<arr[i]<<","<<arr[j]<<"} ";
        }
    }
 }
}

// triplet sum(code studio)
//https://www.naukri.com/code360/problems/triplets-with-given-sum_893028?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1
void tripletSum(int arr[],int size,int sum){
for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        for(int k=j+1;k<size;k++){
         if(sum==arr[i]+arr[j]+arr[k]){
            
          std::cout<<"{"<<arr[i]<<","<<arr[j]<<","<<arr[k]<<"} ";
         }    
        }
    }
}
}

//39
//sort 0 and 1
// 2pointer approach

void sort0and1(int arr[],int size){
    int i=0,j=size-1;
    while(i<j){
    while(arr[i]==0&&i<j){
        i++;
    }
    while(arr[j]==1&&i<j){
        j--;
    }
    if(arr[i]==0&&arr[j]==1&&i<j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    i++;
    j--;
    }
    }
}

//40
// TODO: sort 0,1,2
//https://www.naukri.com/code360/problems/sort-0-1-2_631055?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1
void sort012(int arr[],int size){
}


