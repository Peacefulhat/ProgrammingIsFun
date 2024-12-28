#include<stdio.h>
int any(const char*str,const char* str1){
  for(int i=0;str1[i]!='\0';i++){
    for(int j=0;str[j]!='\0';j++){
    if(str1[i]==str[j]){
        return j;
      }
    }
  }
  return -1;

}
int main(){
  char str[]="hfsdfa";
  char str1[]="afdasf";
  printf("%d",any(str,str1));
  return 0;
}
