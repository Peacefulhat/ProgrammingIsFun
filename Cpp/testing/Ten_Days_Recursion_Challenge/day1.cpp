#include<iostream>
#include<vector>
// reference
//https://www.naukri.com/code360/guided-paths/data-structures-algorithms/content/118522/offering/1380913
// Recursion
// ->base Case : when to stop,retrun statement is mantatory.
// -> recursive relation.
//both base case and revursive relaiton are mandatory.

//for undersanding purposes
/*
int fact(int n){
  if(n==0){return 1;}//base case 
  int smallerProblem=fact(n-1);//smaller problem.
  int biggerProblem=n*smallerProblem;// bigger problem.
  return biggerProblem;
}
*/
int fact(int n){
  if(n==0){// base case
    return 1;
  }
  return n*fact(n-1);// recursive relation
}

int powerof2(int n){
  if(n==0){// base case 
    return 1;
  }
  return 2*powerof2(n-1);// recursive relation
}

void dcounting(int n){
  std::cout<<n<<" ";
  if(n==1){
    return;
  }
 dcounting(n-1);
}

void acounting(int n){
  if(n==0){
    return ;
  }
  acounting(n-1);
  std::cout<<n<<" ";
}

int main(){
  dcounting(6);
  std::cout<<"\n";
  acounting(6);
  return 0;
}
