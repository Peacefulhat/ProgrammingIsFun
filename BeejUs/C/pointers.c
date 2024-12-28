// pointers:are variables that store the address of other variable/hold the address at which data resides.

#include<stdio.h>

int swap(int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
  return 0;
}

int main(){
  int a=0;
  int b=1;
  int *p=&a;
  int *p1=NULL;
 
  printf("%p\n",p);
  printf("%p\n",&a);
  printf("%p\n",&p);
  printf("Before:%d,%d\n",a,b);
  swap(&a,&b);
  printf("After:%d,%d\n",a,b);
  printf("%d",*p1);
  return 0;
}
