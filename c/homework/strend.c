#include<stdio.h>
int strEnd(char *s, char*t){
  int j=0;
  int k=0;
  int index=0;
  while(*(s+k)!='\0'){k++;}
  for( int i=0;*(s+i)!='\0'&&*(t+j)!='\0';i++){
  if(*(s+i)==*(t+j)){
      index=i;
      j++;
    }else{
      index=0;
      j=0;
    }
  }
  k--;// for stirng length -1;
 return (k-index)==0?1:0;
}
int main(){
  char s[]="helloworlda";
  char t[]="orld";
  printf("%d",strEnd(s,t));  
}
