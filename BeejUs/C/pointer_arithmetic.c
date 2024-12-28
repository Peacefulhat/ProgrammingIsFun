#include<stdio.h>
#include<string.h>
// pointer arithmetic.
// we can do is add and subtract pointers
/*In short, if you have a pointer to a type, adding one to the pointer moves to the next item of that type directly after it in memory.
It’s important to remember that as we move pointers around and look at different places in memory, we need to make sure that we’re always pointing to a valid place in memory before we dereference. If we’re off in the weeds and we try to see what’s there, the behavior is undefined and a crash is a common result.
*/

void aprint(void*ptr,int size){// void pointer to funcitons
  for(int i=0;i<size;i++){
    printf("%d ",*(((int*)ptr)+i));
  }
  printf("\n");
}
int slen(char *s){
  char *p=s;
  int i=0;
  while(*s!='\0')s++;
  return s-p;
}

typedef struct node{
  int val;
 struct node* next;
}node;

node a={2,NULL};
node b={3,NULL};
void *ptd=NULL;
// a.next=&b; at global scope not valid because global varibale value must be known at compile time in c . because we can not get memory address with out running program we get error to fix this define this kind of address assignment inside a funciton .



int main(){
  int df[4]={1,2,3,4};
  aprint(df,4);
  a.next=&b;
  ptd=&a;
  printf("%d\n",a);
  printf("%d\n",((struct node*)ptd)->val);// make sure to cast properly to access the address.
  //  printf("%x\n%x\n",&b,a.next);
  int a[5]={11,22,33,44,55};
  int *p=&a[0];// int *p=a; both are valid.

  printf("%d\n",*(p+0));
  printf("%d\n",*(p+3));// baseadd+some constant.
  printf("array:\n");
  for(int i=0;i<5;i++){
    if(i!=4){
      printf("{address:%p,value:%d}\n",(p+i),*(p+i));
    continue;
    }
    printf("{address:%p,value:%d}\n",(p+i),*(p+i));
  }
  
  printf("\n");
  for(int i=4;i>=0;i--){
    printf("{address:%p,value:%d}\n",(p+i),*(p+i));
  }
  p=(p+2);
  printf("{address:%p,value:%d}\n",(p-2),*(p-2));

  printf("%d",slen("Hello"));

  // a[b] == *(a+b);

  void *ptr=NULL;// void pointer;
  // Sometimes it’s useful to have a pointer to a thing that you don’t know the type of.
  char s[]="Goats!";
  char ts[100]="hello\0";
  memcpy(ts,s,7*sizeof(char));
  //1. You cannot do pointer arithmetic on a void*. 2. You cannot dereference a void*. 3. You cannot use the arrow operator on a void*, since it’s also a dereference. 4. You cannot use array notation on a void*, since it’s also a dereference, as well87.
  printf("%s",ts);
     return 0;
}
