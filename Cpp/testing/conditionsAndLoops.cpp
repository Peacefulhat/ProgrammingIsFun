#include<iostream>

int main(int argc,char**argv){
 /*int a,b;
  a=3,b=2;
  if(a>b){
    std::cout<<"A";
  }else{
    std::cout<<"B";
  }*/
  /*int n;
  std::cin>>n;
  it(n>0){
    std::cout<<"N is +ve";
  }else if(n<0){
    std::cout<<"N is -ve";
  }else{
    std::cout<<"N is zero";
  }*/
  int c = 1;
  switch(c){
    case 1: std::cout<<"GoodNight,World!";
            break;
  }

  int n;
  std::cin>>n;
  int i=1;
  while(i<=n){
    std::cout<<i<<" ";
    i=i+1;
  }
  for(int i=0;i<n;i++){
    std::cout<<i<<" ";
  }
 i=0;
  do{
    std::cout<<i<<" ";
    i++;
  }while(i<n);
  return 0;
}
