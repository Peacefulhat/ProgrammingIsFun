#include<stdio.h>
#include<string.h>
//Echo. Command mimic in c 
int main(int argc, char *argv[]){
  for(int i=0;i<argc;i++){
    printf("%s",argv[i]);
  } 
  printf("\n");
  return 0;
}
