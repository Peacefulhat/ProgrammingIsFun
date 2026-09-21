#include<stdio.h>
#define MAX 10
int strLen(const char* str){
  int i=0;
  while(str[i]!='\0'){
    i++;
  }
  return i;
}
int hexNumber(const char*str){
  int length=strLen(str)-1;
  int power=1;
  int decimalNumber=0;
  for(int i=length;i>=0;i--){
    if(str[i]>='A'&&str[i]<='F'){
      decimalNumber=decimalNumber+((str[i]-'0'-7)*power);
    }else{
      decimalNumber=decimalNumber+((str[i]-'0')*power);
    }
    power*=16;
  }

  return decimalNumber;
}
int main(){
  printf("%d",hexNumber("A"));
  return 0;
}
