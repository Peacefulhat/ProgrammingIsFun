// variables
/* it is said that "variable holds values". But another way to think about it is that "variable is a human readable name that refers to some data in memory".*/
#include<stdio.h>
#define true 1
#define false 0

typedef struct {
  char * arena;
  short capacity;
}my_type;

int main(void){
  
  int i;
  float f;
  
  const char *str="Hello,World!";
  printf("%s,%i,%f\n",str,i,f);

  // every thing is true is c,except 0
  if(NULL){
    printf("value is true\n");
  }
  
  if(-37){
    printf("value is true\n");
  }
  
   //int min=!false;
  //printf("int min: %d\n",min);
  
  if(!false){
    printf("value is true\n");
  }
  
  // ternary operator
  int x =(23%5)?23+1:23-1;
  printf("x=%d\n",x);

  // pre increment: value is computed before evaluation 
  int d=0;
  printf("pre-increment:%d\n",++d);
  
  //Conditional operatos // evaluate to 1 and 0
  int T=3;
  int F=2;
  int flag=T==F;
  printf("Conditional operatos:%d\n",flag);
  flag=T!=F;
  printf("%d\n",flag);

  // logical operatos. && , ! , ||
  !flag;
  printf("%d\n",flag);
  

  // sizeof return the size of type in bytes.
  my_type p;
  char * h=NULL;
  printf("%d",sizeof(p));
  printf("%d",sizeof(h));
  printf("%d",sizeof(short));

  //switch
  int sudo='a';
  printf("sudo=%d\n",sudo);
  switch(sudo){
    
  case 'a':// 97
    printf("0");
    break;
    
  case 1:
    printf("1");
    break;
    
   default:
    printf("-1");
  }
  return 0;
}
