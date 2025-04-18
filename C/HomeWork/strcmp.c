#include <stdio.h>
int strCmp(char *s,char*t,int n){
int count=0;
for(int i=0;i<n;i++){
  if(*(s+i)==*(t+i)){//s[i] t[i];
    count++;
    }
  }
return count==n;
}
int main(){
  char s[]="hellow";
  char t[]="tello";
  printf("%d",strCmp(s,t,4));
  return 0;
}
