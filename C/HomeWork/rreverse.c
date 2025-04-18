#include<stdio.h>
void rreverse(char str[],int start,int end){
  if(start>=end){
    return;
  }
  end--;
  char c=str[start];
  str[start]=str[end];
  str[end]=c;
  rreverse(str,start+1,end);
}
void ritoa(int n,char s[],int i){
  if(n==0){
    return;
  }
  s[i]=(char)(n%10)+'0';
  ritoa(n/10,s,i+1);
}
int main(){
  //char str[12]={'A','b','c','d','e','f','\0'};
  //rreverse(str,0,6);
  //printf("%s",str);
  char s[10];
  ritoa(1234,s,0);
  printf("%s",s);
  return 0;
}
