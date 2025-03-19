#include<stdio.h>
// in printf there is a thing called width of element you are printing.
int main(){
  int a=23;
  // for this to work we should now padding at compile time
  // left padd
  printf("%3d",a);// here the size of the entire element (23) is three , it paded it with spaces.(3d) characters
  printf("%10d",a);
  // right padd
  printf("|%-3d|",a);
  // padding with some chracter;
  
  printf("%05d",a);
  // now what if i want to know this padding at run time
  int b;
  // this kind of this can be done with compile time know variable value.
  scanf("%d",&b);
  printf("%0*d",b,a);
  // this kind of thing not only works with number with string as well.

  printf("%*s",b,"hello");
  
  
  return 0;
}
