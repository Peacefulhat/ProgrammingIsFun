#include<stdio.h>
int bitCount(int x){ // counts number of set bits;(1)
  int count;
  for(count=0;x!=0;x&=(x-1),count++);
  return count;
}
int rbitCount(int x,int count){// recursive bit cout of set bits(1);
  if(x==0){
    return count;
  }
 rbitCount(x&=(x-1),count+1);
}
int main(){
  printf("%d",rbitCount(10,0));
  return 0;
}
