// Arithmetic ,relational and logical operators.

#include<stdio.h>
void arithmeticOperators(int first , int second){
int addition,subtraction,multipication,modulas_remainder,division;
addition =first+second;
printf("Addition: %d\n",addition);
subtraction=first-second;
printf("Subtraction: %d\n",subtraction);
multipication=first*second;
printf("Multipication: %d\n",multipication);
division=first/second;
printf("Division: %d\n",division);
modulas_remainder=first%second;
printf("Remainder: %d",modulas_remainder);
}
void relationalOperators(int first,int second){
  int greaterThan,lessThan,greaterThanEqualTo,lessThanEqualTo,notEqualto;
  greaterThan=first>second;
  printf("First is greater than second: %d\n",greaterThan);
  lessThan=first<second;
  printf("First is less than second: %d\n",lessThan);
  greaterThanEqualTo=first>=second;
  printf("First is greater than equal to second: %d\n",greaterThanEqualTo);
  lessThanEqualTo=first<=second;
  printf("First is less than equal to second: %d\n",lessThanEqualTo);
  notEqualto=first!=second;
  printf("First is not equal to second: %d\n",notEqualto);
}
void logicalOperators(int first, int second){
// basically mathematical connectors;
int someValue=first&&second;
  printf("First and Second: %d\n",someValue);
  someValue=first||second;
  printf("First or Second: %d\n",someValue);
  printf("Not (First && second): %d\n",!(someValue));
}
int main(){
  arithmeticOperators(4,2);
  relationalOperators(0,1);
  logicalOperators(0,1);
  return 0;
}
