//18

//pattern
//D 
//C D 
//B C D 
//A B C D

#include<iostream>
int main(){
  int n;
  std::cin>>n;
  int ch='A'+n-1;
  int rows=1;
  while(rows<=n){
  int cols=rows;
    while(cols>=1){
      std::cout<<char(ch+((cols-1)*(-1)));
      cols=cols-1;
    }
    std::cout<<"\n";
    rows=rows+1;

  }
  return 0;
}
