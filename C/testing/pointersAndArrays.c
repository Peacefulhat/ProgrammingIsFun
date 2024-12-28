#include <stdio.h>
#define BUFFERSIZE 100

char buffer[BUFFERSIZE];
int bufp = 0;

int getch() {
  return bufp > 0 ? buffer[--bufp] : -1;
}

void ungetch(int c) {
  if (bufp < BUFFERSIZE)
    buffer[bufp++] = c;
  else
    printf("overflow\n");
}

void pointers() {
  int x = 1, y = 2, z[10];
  int *ip = NULL; // ip points to int type variable or array;
  printf("%p\n", (void *)ip);
  ip = &x; // ip points to variable x;
  printf("%p\n", (void *)ip);
  y = *ip; // ip getting the value at x and assigning it to y;
  printf("%d\n", y);
  ip = &z[0]; // ip pointing to array's first element;
  printf("%p\n", (void *)ip);
}

void pointersandfunctionarguments(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void getInt(int *pn) {// not done yet
    int c, sign = 1;
    *pn = 0; // Initialize pn to 0
    while ((c = getchar()) == ' ' || c == '\t') {
        // skip whitespace
    }
    if (c == '+' || c == '-') {
        sign = (c == '-') ? -1 : 1;
        c = getchar(); // move to the next character
    }
    while (c >= '0' && c <= '9') {
        *pn = *pn * 10 + (c - '0');
        c = getchar();
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
}
  int power(int base, int exp){
  int result=1;
  for(int i=exp;i>=0;i--){
  result*=base;
}
  return result;
}
void getFloat(float *pn){//only postive floats.
  int c;
  int i,set=0;
while((c=getchar())!=EOF&&c!='\n'){
  if(c=='.'){set=1;}else{ungetch(c);}
  if(set==1){i++;}
}
while((c=getch())!=-1){
  *pn=*pn*10+(c-'0');
}
  *pn=*pn/(power(10,((i-(i-2)))));
}

void pointersAndArray(int arr[]){
for(int i=0;i<4;i++){
printf("{%d,%p,%d}\n",i,arr+i,*(arr+i));
}
}
void tst(int arr[]){
for(int i=4;i>=-23;i--){
printf("{%d,%p,%d}\n",i,arr+i,*(arr+i));
}
}
//stack based custom allocator;
static char allocbuf[BUFFERSIZE];
static char *allocp=allocbuf;
char *alloc(int n){
  if((allocbuf+BUFFERSIZE)-(allocp)>=n){// first allocp=(allocbuf+0)
    allocp+=n;
    return allocp-n;
  }else{
    return 0;
  }
}
void allocfree(char*p){
  if(p>=allocbuf&&p<allocbuf+BUFFERSIZE){
    allocp=p;
  }
}
void allocfreewhole(){
  for(int i=0;i<BUFFERSIZE;i++){
    allocfree(allocbuf+i);
  }
  allocp=allocbuf;
}
//pointerArithmetics.
void pointerArithmetics(int *arr){
//pointercomparision can be done under certain circumstances. if P and Q points to member same array, then relation like ==,!=,<,>=,etc..works properly :eg; p<q; is true if p points to earlier member of the array than q does.
// Any pointer can be meaningfully compared for equality or inequality with zero. but the arithmetic comparision is not defined if pointer are not the member of same array.
  int *p=arr;
  int *q=arr+1;
  int *t=(int*)(q-p);
  if(p<q){printf("q is greater\n");}
  int n=5;
  int s=allocbuf+BUFFERSIZE-allocp;
  if(s>=n){
    printf("%d\n",s);
  }
  allocp+=n;
  n=6;
  s=allocbuf+BUFFERSIZE-allocp;
  if(s>=n){
    printf("%d",s);
  }
 // printf("%d",t);
}
// character Pointers and Function;
void charPointer(){
  char message[]="this is a message";// this will make array and initilize it with characters and end it with '\0' internally;
  char *pmessage="this is a pointer message"; 
  //this is a character pointer that points a string constant more specifically the first charater.
printf("%s\n",message);
printf("%s",pmessage);
}
int main() {
  int arr[4]={43,24,31,47};
  //pointerArithmetics(arr); 
  charPointer();
  return 0;
}

