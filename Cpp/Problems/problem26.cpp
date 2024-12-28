//26

//pattern
//   1
//  121
// 12321
//1234321
#include<iostream>
int main(){
  int n,row=1;
  std::cin>>n;
  while(row<=n){
    int space=n-row;
    while(space>=1){
      std::cout<<"  ";
      space=space-1;
    }
    int col,k;
    col=1;
    while(col<=row){
      std::cout<<col<<" ";
      col=col+1;
    }
    k=1;
    while(k<=row){
      if(row>1){
        int a=(row-1)+((k-1)*(-1));
        if(a){
        std::cout<<a<<" ";
        }
       }
      k=k+1;
    }std::cout<<"\n";
    row=row+1;
  } 
  return 0;
}
