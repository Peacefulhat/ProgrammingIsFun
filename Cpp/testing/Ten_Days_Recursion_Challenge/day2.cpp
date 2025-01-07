#include<iostream>
void reachHome(int src, int dest){
  std::cout<<src;
  if(src==dest){
    std::cout<<"At Home";
    return ;
}
  src++;// argument is src that is why its not changing
  // if it was not argument i would have reseted
  reachHome(src,dest);
}

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

int main(){
  reachHome(1,5);
  return 0;
}
