//31

// fibonaci by funciton.
#include<iostream>

int fibonaci(int n){
  int a=0;
  int b=1;
  int c;
  for(int i=1;i<=n;i++){
  c=a+b;
  a=b;
  b=c;
  }
  return c;
}

int main(){
  
  int a;
  std::cin>>a;
  std::cout<<fibonaci(a);
  return 0;

}
