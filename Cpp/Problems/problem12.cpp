//12
//pattern 
//1
//2 3
//3 4 5
//4 5 6 7


#include<iostream>
int main(){
  int rows=1,n;
  std::cin>>n;
  while(rows<=n){
    int cols=1;
   while(cols<=rows){
    std::cout<<rows+(cols-1);
      cols=cols+1;
    }
    std::cout<<"\n";
    rows=rows+1;
  }
  return 0;
}
