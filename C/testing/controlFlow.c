#include<stdio.h>
typedef enum{
  ok,warn,err
}stateOfProcess;
void statementsAndBlock(){
  // statement; end with a termination (;)
  int x=526725;
  printf("%d\n",x);
  // blocks; {} are use to define blocks and thing that defined inside the block exits only inside blocks;
  {
    const char name[]="peacefulhat";
    int bitIndex=2;
    printf("%s %d\n",name,bitIndex);
  }
  int bitIndex=1;
  printf("%d\n",bitIndex);
}
void conditionalControlFlow(){
  // if statements;
  int x;
  int y;
  if(x>y){
    printf("x is greater than y\n");
  }
  // if else statements;
  if(x>y){
    printf("x is greater than y\n");
  }else{
    printf("y is greater tha x\n");
  }
  //if else if statements;
  if(x>y){
    printf("x is greater than y\n");
  }else if( x==y){
    printf("x and y are both equal\n");
  }else{
    printf("y is greater than x\n");
  }
  // nested if statement;
  
  if(x>y){
    y=y*y;
   if(y>x){
      printf("y became greater than x\n");
    }else{
      printf("x is still greater than y\n");
    }
  }else{
    x=x*x;
    if(x>y){
      printf("x became greater than y\n");
    }else{
      printf("y is still greater than x\n");
    }
  }

  // switch case statement;
  stateOfProcess processOne=ok;
  switch (processOne) {
    case ok:
      printf("Working fine\n");
      break;
    case warn:
      printf("Not working fine\n");
      break;
    case err:
      printf("Error are present\n");
      break;
    default:
      printf("Something went wrong");
      break;
  }
}

int main(){
  statementsAndBlock();
  conditionalControlFlow();
  return 0;
}
