//13
//pattern
// 1
// 2 1
// 3 2 1
// 4 3 2 1
#include<iostream>
int main(){
  int n;
  int rows=1;
  std::cin>>n;
  while(rows<=n){
  int cols=1;
    while(cols<=rows){
    std::cout<<rows+((cols-1)*(-1));
      cols=cols+1;
    }
    std::cout<<"\n";
    rows=rows+1;
  }
  return 0;
}
