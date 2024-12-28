#include<iostream>
int power(int,int);//function signature and fucntion declaration
int power(int a,int b){
  int ans=1;               //function body;
  for(int i=1;i<=b;i++){
    ans=ans*a;
  }
  return ans;
}
//1->Even 
//0->Odd
bool isEven(int a){
 if(a&1){
    return 0;
  }
  return 1;
}

int factorial(int n){
  int fact=1;
  for(int i=1; i<=n;i++){
    fact*=i;
  }
  return fact;
}

int nCr(int n,int r){

  int num=factorial(n);
  int denom=factorial(r)*factorial(n-r);
  return num/denom;
}

void printCounting(int n){
  for(int i=1;i<=n;i++){
    std::cout<<i<<" ";
  }
}
//1-> prime
//0->not pirme
bool isPrime(int n){
for(int i=2;i<n;i++){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
} 

// pass by value
void dummy(int n){
  n++;
  std::cout<<"n is "<<n<<std::endl;
  
}
int main(){
  int a,b;
  //function calling
 // std::cout<<power(a,b)<<"\n";
 // std::cout<<isEven(a)<<"\n";
 // std::cout<<nCr(a,b)<<"\n";
 // printCounting(a)<<"\n";
  std::cin>>a;
  dummy(a);
  std::cout<<a;
  return 0;
}
