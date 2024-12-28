//2
// sum of n number starting for 1 to n
#include<iostream>
int main(int argc,char** argv){
  int n;
  std::cin>>n;
  int i=1,sum=0;
  
  while(i<=n)
  {
   sum = sum+i;
    i=i+1;
  }

  std::cout<<sum;
  return 0;

}
