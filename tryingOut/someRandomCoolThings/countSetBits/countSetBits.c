
#include<stdio.h>
#include<stddef.h>

// count bits one by one
size_t rec_count(int n){
  if(n==0)return 0;
  return (n&1)+rec_count(n>>1);
}


size_t naive_count(int n){
  size_t count=0;
  while(n){
    count+=(n&1);
    n=n>>1;
  }
  return count;
}

//brian karnighans count bits,
//count bits one by one if number i odd or even (until number becomes zero)kind of like O(n) , but for mutiple of two its O(1)

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



