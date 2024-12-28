//19

//pattern
//         *
//        **
//       ***
//      ****
#include<iostream>
int main(){
  int n;
  std::cin>>n;
  int rows=1;
  
  while(rows<=n){
  int space=n-rows;
  while(space>=1){
    std::cout<<" ";
      space=space-1;
  }
    int col=1;
  while(col<=rows){
      std::cout<<"*";
      col=col+1;
    }
    std::cout<<"\n";
  rows=rows+1;
  }
  return 0;
}
