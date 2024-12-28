//9

//pattern
//*
//**
//***
//****
//*****
#include<iostream>

int main(){
  int n;
  std::cin>>n;
  int i=1;
  while(i<=n){
    int j=1;
    while(j<=i){
    std::cout<<"*";
    j=j+1;
    }
    std::cout<<"\n";
    i=i+1;
  
  }
  return 0;
}
