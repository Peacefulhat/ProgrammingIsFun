//24

//pattern
// 1234
//  234
//   34
//    4
#include<iostream>
int main(){
  int n,row=1;
  std::cin>>n;
  while(row<=n){
   int space=row-1;
    while(space>=1){
      std::cout<<" ";
      space=space-1;
    }
    int col=1;
     while(col<=n-row+1){
     std::cout<<row+(col-1);
      col=col+1;
    }
    std::cout<<'\n';
    row=row+1;
  }
  return 0;
}
