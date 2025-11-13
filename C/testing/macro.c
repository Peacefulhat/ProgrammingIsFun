#include<stdio.h>
// #define name replacement text
#define type double
// syntax for multiline macro;each line ends with \ except last line
#define Max(x,y,z) {\
int temp=x>y?x:y \
 temp=temp>z?temp:z\
}

// macor prefix to function


MACRO static int sum(int a, int b)
{
    return a + b;
}


int main(){
  type someValue=6.5;
  printf("%lf",someValue);
  int res = sum(2,3);
  printf("\n%d", res);
  return 0;
}
