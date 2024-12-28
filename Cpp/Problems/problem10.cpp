//10
//pattern 
//1
//2 2
//3 3 3 
//4 4 4 4
#include<iostream>
int main(){
  int n,rows=1;
  std::cin>>n;
  while(rows<=n){
  int cols=1;
  while(cols<=rows){
      std::cout<<rows;
      cols=cols+1;
    }
    std::cout<<"\n";
    rows=rows+1;
  }
  return 0;
}
