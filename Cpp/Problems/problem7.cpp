//7

//pattern rows =colomns
//1 1 1
//2 2 2 
//3 3 3
//n n n
#include<iostream>
int main(){
  int rows;
  std::cin>>rows;
  int start = 1;
  int i=1;
  while(start<=rows*rows){
  if(start%rows==0){
      std::cout<<i<<"\n";
      i++;
    }else{
      std::cout<<i;
    } 
    start=start+1;
  }
  return 0;
}

