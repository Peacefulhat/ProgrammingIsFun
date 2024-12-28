//11
//pattern
//1
//2 3
//4 5 6
//7 8 9
#include<iostream>
int main(){
  int rows=1;
  int n;
  int i=1;
  std::cin>>n;
  while(rows<=n){
    int cols=1;
    while(cols<=rows){
      std::cout<<i;
      i=i+1;
      cols=cols+1;
    }
    std::cout<<"\n";
    rows=rows+1;
  }
  return 0;
}
