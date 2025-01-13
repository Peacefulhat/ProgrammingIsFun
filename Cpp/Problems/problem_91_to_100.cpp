#pragman once
// 91
//Fibonacci Number
//https://leetcode.com/problems/fibonacci-number/
int fib(int n ){
  if(n==0){
    return 0;
  }

  if(n==1){
    return 1;
  }
  return fib(n-1)+fib(n-2);
}

//92
//climb stares(nth-staire)
//https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_10

int climb_stare(int n){
  if(n<0)return 0;
  if(n==0){
    return 1;
  }
  return climb_stare(n-1)+climb_stare(n-2);
}

// 93
// say digits
//ip=412
//op=four one two

// Todo

// 94
//check if array is sorted or not using recursion
bool is_sorted(int *arr,int size){
  if(size==0|| size==1) return true;
  if(arr[0]>arr[1]){
    return false;
  }else{
    bool sorted=is_sorted(arr+1, size-1);
    return true;
}

  //95
  //Todo:
  //ip 3,2,5,1
  // return sum
  int rsum(int*arr, int size){
  if(s<0){
    return 0;
  }
 return arr[size]+rsum(arr,size-1); 
  }
