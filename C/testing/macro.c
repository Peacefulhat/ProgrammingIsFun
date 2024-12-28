#include<stdio.h>
// #define name replacement text
#define type double
// syntax for multiline macro;each line ends with \ except last line
#define Max(x,y,z) {\
int temp=x>y?x:y \
 temp=temp>z?temp:z\
}
int main(){
  type someValue=6.5;
  printf("%lf",someValue);
  return 0;
}
