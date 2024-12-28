//6

//pattern
//****
//****
//****
//****
#include<iostream>
int main(){
  int rows;
  std::cin>>rows;
  int start=1;
  while(start<=rows*rows){
    if(start%rows==0){
      std::cout<<"*\n";
    }else{
      std::cout<<"*";
    }
    start=start+1;
  }
  return 0;
}

