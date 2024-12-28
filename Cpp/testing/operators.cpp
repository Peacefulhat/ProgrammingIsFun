//Bitwise operators
#include<iostream>
const char* primeornot(int n){
  int i;
  bool isprime=1;
  for( i=2;i<n;i++){
    if(n%i==0){
      isprime=0;
      break;
    }
  }
 return isprime?"Prime":"Not Prime"; 
}
void fib(int n){
  int a=0,b=1,c;
  std::cout<<a<<' '<<b<<' ';
  for(int i=1;i<=n;i++){
    c=a+b;
    std::cout<<c<<" ";
    a=b;
    b=c;
  }
}
int main(){
  int a,b;
  std::cin>>a>>b;
  std::cout<<"NOT of a: "<<~a<<"\n";
  std::cout<<"OR of a and b: "<<(a|b)<<"\n";
  std::cout<<"AND of a and b: "<<(a&b)<<"\n";
  std::cout<<"XOR of a and b: "<<(a^b)<<"\n";
  std::cout<<"LeftShift of a by b: "<<(a<<b)<<"\n";
  std::cout<<"RightShift of a by b: "<<(a>>b)<<"\n";
 int i=7;
  std::cout<<(++i)<<std::endl;
  //i=8
  std::cout<<(i++)<<std::endl;
  //8,i=9;
  std::cout<<(i--)<<std::endl;
  //9, i=8
  std::cout<<(--i)<<std::endl;
  // 7
  int sum=0;
  for(int i=1;i<=23;i++){
    sum+=i;
  }
  std::cout<<sum<<std::endl;
  fib(10);
  std::cout<<std::endl;
  int some;
  std::cin>>some;
  std::cout<<primeornot(some);
  for(int i=0;i<5;i++){
    std::cout<<i<<std::endl;
    std::cout<<"hey"<<std::endl;
    continue;
    std::cout<<"Reply";
  }
return 0;

}
