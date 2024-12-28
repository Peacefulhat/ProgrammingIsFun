//17

//pattern
//A B C
//B C D
//C D E
#include<iostream>
int main(){
  int n;
  int rows=1;
  std::cin>>n;
  char ch=65;
  while(rows<=n) {
  int cols=1;
    while(cols<=n){
      std::cout<<char((ch+cols-1)); 
      cols=cols+1;
    }
    ch=ch+1;
    std::cout<<"\n";
    rows=rows+1;
  }
  return 0;
}
