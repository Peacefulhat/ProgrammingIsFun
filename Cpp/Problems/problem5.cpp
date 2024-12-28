//5
//check if a number is prime or not
#include<iostream>
int main(){
 int n;
  std::cin>>n;
  int i=2;
  while(n%i!=0){
    i=i+1;
  }
  if(n==i){
    std::cout<<"Prime";
  }else{
    std::cout<<"Not Prime";
  }
  return 0;
}
