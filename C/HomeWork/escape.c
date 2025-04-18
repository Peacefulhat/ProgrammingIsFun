#include<stdio.h>
#define MAX 20
void escape(char s[],const char t[]){
  int i=0;
  for(i=0;s[i]!='\0';i++);
  for(int j=0;t[j]!='\0';j++){
    switch(t[j]){
      case '\n':
        s[i++]='\\';
        s[i++]='n';
        break;
      case '\t':
        s[i++]='\\';
          s[i++]='t';
        break;
      default:
        s[i++]=t[j];

    }
  }
  s[i]='\0';
}
void unescape(char s[],const char t[]){
int i;
for(i=0;s[i]!='\0';i++);
for(int j=0;t[j]!='\0';j++){
     switch(t[j]){
      case '\\':
        if(t[j+1]!='\0'){
      if(t[j+1]=='n'){
          s[i++]='\n';
        }else {
        s[i++]='\t';
        }
        }
      break;
      default:
        s[i++]=t[j];
    }
  }
  s[i]='\0';
}
int main(){
  char str[MAX]={'a','b','c','d','\0'};
  char t[]="hello\\nword\\tgooogle";
 // escape(str,t);
  //printf("%s",t);
  unescape(str,t);
  printf("%s",str);
  return 0;
}
