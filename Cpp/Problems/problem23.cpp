//23
//pattern
//    1
//   22
//  333
// 4444
#include<iostream>
int main(){
 int n,row=1;
  std::cin>>n;
  while(row<=n){
    int space=n-row;
    while(space>=1){
      std::cout<<" ";
      space=space-1;
    }
    int col=row;
    while(col>=1){
      std::cout<<row;
      col=col-1;
    }
    std::cout<<"\n";
    row=row+1;
  }
  return 0;
}
