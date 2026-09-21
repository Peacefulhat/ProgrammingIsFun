#include<stdio.h>
#define BUFFERSIZE 100
char buf[BUFFERSIZE];
int bufp=-1;
int getCh(void){

  return (bufp>0)?buf[--bufp]:EOF;
}
void ungetCh(int c){
  if(bufp>BUFFERSIZE||c==EOF){return;}
  buf[++bufp]=(char)c;
}
void ungetS(char s[]){
  if(bufp>BUFFERSIZE){
    printf("overflow");
    return;
  }
  for(int i=0;s[i]!='\0';i++){
    buf[++bufp]=s[i];
  }
  buf[++bufp]='\0';
}
void ungetS2(char s[]){
  for(int i=0;s[i]!='\0';i++){
    ungetCh(s[i]);
  }
}
int main(){
  char Text[]="heel";
  ungetS2(Text);
  printf("%s",buf);

  return 0;
}
