//15

//pattern
// A B C
// A B C
// A B C
#include<iostream>
int main(){
  int n;
  int rows=1;
  std::cin>>n;
  while(rows<=n){
    int cols=1;
    while(cols<=n){
      std::cout<<char(65+cols-1);
      cols=cols+1;
    }
    std::cout<<"\n";
    rows=rows+1;
  }
  return 0;
}
