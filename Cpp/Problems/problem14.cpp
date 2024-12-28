//14

//pattern
// AAA
// BBB
// CCC
#include<iostream>
int main(){
  int n;
  int rows=1;
  std::cin>>n;
   char ch=65;
  while(rows<=n){
  int cols=1;
    while(cols<=n){
    std::cout<<ch;
    cols=cols+1;
    }
    ch=ch+1;
    std::cout<<"\n";
    rows=rows+1;
  }
  return 0;
}
