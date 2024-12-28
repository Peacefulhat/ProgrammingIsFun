// functions in c

#include<stdio.h>
int sum(int,int);


//void foo();
//void foo(void); both are not same thing.
int plus_one(int n){
  return  n+1;
}

void time(void){
  printf("current_time:12:00AM\n");
}

int inc(int n){
  return n+1;
}
int main(){
  time();
  //  printf("%d",plus_one(2));
  int n=0;
  printf("inc:%d,n:%d",inc(n),n);
  printf("sum:%d",sum(2,3)); 
  return 0;
}

int sum(int a, int b){
  return a+b;
}
