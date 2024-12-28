//30

// count set bits of a and b;
#include<iostream>
int setbits(int a,int b){
  int totalsetbits=0;
  while(a&&b){
    if(a!=0){
      totalsetbits+=a&1;
      a=a>>1;
    }
    if(b!=0){
      totalsetbits+=b&1;
      b=b>>1;
    }
  }
  return totalsetbits;
}
int main(){
  int a,b;
  std::cin>>a>>b;
  std::cout<<setbits(a,b);
  return 0;
}
