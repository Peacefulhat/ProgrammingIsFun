#include<stdio.h>
// function pointers;
int sum(int a,int b)
{
  return a+b;
}
int squar(int x){
  return x*x;
}
int main(){
  int (*sumpointer)(int,int)=&sum;
  printf("%d",squar(sumpointer(1,3)));
  return 0;
}
