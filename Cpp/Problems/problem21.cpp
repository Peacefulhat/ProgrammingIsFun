//21

//pattern
//****
// ***
//  **
//   *
#include<iostream>
int main(){
  int n;
  std::cin>>n;
  int row=1;
  while(row<=n){
  int space =row-1;
  while(space>=1){
      std::cout<<" ";
      space=space-1;
    }
    int col=n-row+1;
    while(col>=1){
      std::cout<<"*";
      col=col-1;
    }
    std::cout<<'\n';
    row=row+1;
  }
  return 0;
}
