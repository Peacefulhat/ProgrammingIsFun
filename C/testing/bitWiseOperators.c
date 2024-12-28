#include <stdio.h>
int setbits(int x,int p,int n, int y){
  if(p<n){return 0;}// it does not make sense because if this happes we will be changing bits of excding the postion p.
  int bitMask=(1<<n)-1;
  x=x&(~(bitMask<<(p-n)));// (~(bitMask<<(p-n))); will clear the replaceing bits from x;
  x=x|(y&bitMask);// y&bitMask will give n bits from y;
  return x;
}
int getbits(int x, int p,int n){
  if(n>p){
    return 0;
  }
  int bitMask=(1<<n)-1;
  x=x>>(p-n);
  x=x&bitMask;
  return x;
}
int invert(int x, int p, int n) {
    int invertMask = ((1 << n) - 1);
    invertMask=invertMask<<(p-n);
    x = x ^ invertMask; 
    return x;  
}

int rightrot(int x,int n){
  // not done yet.
}

int main() {
  printf("%d",rotateBits(27,3));
  return 0;
}

