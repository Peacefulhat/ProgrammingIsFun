//3
// find sum of all even number from 0 to n
#include<iostream>
int main(){
  int n;
  std::cin>>n;
  int i=0,sum=0;
  while(i<=n){
    sum=sum+i;
    i=i+2;
  }
  std::cout<<sum;
  return 0;
}
