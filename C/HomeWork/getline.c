#include <stdio.h>
#define MAX 100
void getLine(char buffer[],int size){
  int i=0;
  int c;
  while((c=getchar())!=EOF&&size>0){
  if(c=='\n'){
      continue;
    }
  buffer[i++]=c; 
  size--;
  }
  buffer[i]='\0';
}
int main(){
  char buffer[MAX];
  int n;
  printf("Enter buffer size: ");
  scanf("%d",&n);
  getLine(buffer,n);
  printf("%s",buffer);
  return 0;
}
