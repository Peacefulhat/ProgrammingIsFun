// Brian Kernighan's algorithm for counting set bits
#include<stdio.h>
#include<stddef.h>

size_t rec_count(int n){
  if(n==0)return 0;
  return (n&1)+rec_count(n>>1);
}

// only if  n greater than or equal to 0
size_t naive_count(int n){
  size_t count=0;
  while(n){
    count+=(n&1);
    n=n>>1;
  }
  return count;
}

//brian karnighans count bits,
// n=n&(n-1);
// q=n&m , n, m=n-1; n=m+1
// 
size_t bCountSetBits(int n){
  size_t count=0;
  while(n){
    n&=(n-1);
    count++;
}
  return count;
}

int main(){
  printf("Bit Count :: %d",bCountSetBits(5));
  return 0;
}



