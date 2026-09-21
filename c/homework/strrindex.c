#include<stdio.h>
typedef struct {
  int start,end;
}index;
int strrindex(const char s[],char t[]){
  int start=-1;
  int j=0;
 for(int i=0;s[i]!='\0'&&t[j]!='\0';i++){
 if(s[i]==t[j]){
  if(start==-1){
        start=i;
      } 
    j++;
  }else{
  j=0;
  start=-1;
  }
}
 if(t[j]=='\0'){
    return start;
  }else{
    start=-1;
    return start;
  } 
}
int main(){
  char s[]="array";
  char t[]="ay";
  printf("%d",strrindex(s,t));
  return 0;
}
