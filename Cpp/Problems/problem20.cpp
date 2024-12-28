//20

//pattern
//****
//***
//**
//*

#include<iostream>
int main(){
  int n;
  std::cin>>n;
  int rows=n;
  while(rows>=1){
   int col=rows;
    while(col>=1){
      std::cout<<"*";
      col=col-1;
    }
    std::cout<<"\n";
    rows=rows-1;
  }
  return 0;
}
