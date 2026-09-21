#include<stdio.h>
#define MAX 100
void strCat(char *s,const char *t){
  while(*s!='\0'){s++;} 
  while((*s++ = *t++)!='\0');
}
int main(){
  char s[MAX]={'a','b','\0'};
  char t[]="heLLO";
  strCat(s,t); 
  printf("%s",s);
  return 0;
}
