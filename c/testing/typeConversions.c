#include<stdio.h>
// larger type can't be converted to smaller type.
// it can be done but we may loose some part of data.
// this process is known as downcasting or narrowing conversion.
int atoi(const char *str){
  int number=0;
  for(int i=0;str[i]>='0'&&str[i]<='9';i++){
    number=number*10+((int)(str[i]-'0'));
  }
  return number;
}
int lower(int n){
  return (n>=65&&n<=91)?n+32:n;
}

int main(){
  long long largerType=2345145153145154;
  int smallerType=(int)(largerType);
  printf("%lld\n",largerType);
  printf("%d\n",smallerType);
  char small='A';
  int large=(int)small;
  // smaller larger type can be done and this won't lead to data loss.
  printf("%d\n",small);
  printf("%d\n",large);
  printf("%d\n",atoi("1234"));
  char c=(char)(lower(77));
  printf("%c\n",c);
  return 0;
}
