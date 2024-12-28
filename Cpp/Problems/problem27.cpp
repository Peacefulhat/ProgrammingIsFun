//27

//pattern
// 1234554321
// 1234**4321
// 123****321
// 12******21
// 1********1
#include<iostream>
int main(){
  int n;
  int i=0;
  std::cin>>n;
  int row=1;
  for(;row<=n;row++){
    for(int start=1;start<=n;start++){
      if(start>=(n-row+2)){
        std::cout<<"*"; 
      }else{
        std::cout<<start;
      }
    }

    for(int End=n;End>=1;End--){
      
    if(End>=(n-row+2)){
        std::cout<<"*";
      }else{
        std::cout<<(End);
      } 
    }
    std::cout<<"\n";
    }
  return 0;
}
