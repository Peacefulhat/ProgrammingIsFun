//8
//pattern 
//1 2 3 4
//1 2 3 4 
//1 2 3 4
//1 2 3 4
#include<iostream>
int main(){
  int rows;
  std::cin>>rows;
  int start=1,i=1;
  while(start<=rows*rows){
    if(start%rows==0){
      std::cout<<i<<"\n";
      i=i+1;
    }else{
      std::cout<<i;
      i=i+1;
    }
    start=start+1;
  }
  return 0;
}
