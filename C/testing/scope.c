#include<stdio.h>
extern int someValue;
int someValue=32;
// static varible insde a funcition will persiste across multiple function calls.
void reverse(int n){
  static int rev;
  if(n==0){
    printf("%d",rev);
    return;
  }
  rev=rev*10+(n%10);
  reverse(n/10); 
}
//static functions are only visibal to the transtaltion unit in which they are defined.
static void rv(int n){
  printf("%d",n);
}
// same goes for static global variable are only visible to the translation unit in which they are defind.
static int global;
int main(){
  printf("%d\n",someValue);
  reverse(234);
  return 0;
}
