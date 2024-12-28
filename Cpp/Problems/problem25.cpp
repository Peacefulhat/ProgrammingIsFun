//25

//pattern
//    1
//   23
//  456
// 78910
#include<iostream>
int main(){
 int n,row=1,i=1;
  std::cin>>n;
 while(row<=n){
   int space=n-row+1; 
  while(space>=1){
      std::cout<<" ";
      space=space-1;
    }
    int col=row;
    while(col>=1){
      std::cout<<i;
      i=i+1;
      col=col-1;
    }
    std::cout<<"\n";
    row=row+1;  
  }
 return 0; 
}
