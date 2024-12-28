//22

//pattern 
// 1111
//  222
//   33
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
    int col=n-row+1;
    while(col>=1){
      std::cout<<row;
      col=col-1;
    }
    std::cout<<"\n";
    row=row+1;
  }
  return 0;
}
