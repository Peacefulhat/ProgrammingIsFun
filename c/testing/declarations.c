#include<stdio.h>
#define MAX 23
int main(){
  int lower,upper,step;// declaration of variable in one line. (with out value assignment);
  // variable declaration in multiple lines.
  int lower_bound;
  int upper_bound;
  int tangent;
  char point;
  const char*line;
  // varible assignment;
  lower_bound=3;
  upper_bound=11;
  tangent=2;
  point='A';
  line="intersection";
  const double e=2.71828;
  const char message[]="GoodNight,World!";
  // int strlen(const char* str)// the const declartion can also be used with array arguments, to indicate that the function does not change  that array.
  printf("%c\n",*line);
  printf("%c",*message);
  return 0;
}

