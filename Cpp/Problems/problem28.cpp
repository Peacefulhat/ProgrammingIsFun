//28

// how many notes can we get if we have 100,50,20,1
// greedy approach
#include<iostream>
int main(){
  
  int k=0, n,totalnotes=0,i=100;
  std::cin>>n;
  std::cout<<"Notes 100,50,20 1 :";
  while(n){
    switch(i){

      case 100:
      k=n/100;
      n=n-(k*100);
      //totalnotes+=k;
      std::cout<<k<<" ";
      i=50;
      break;

      case 50:
      k=n/50;
      n=n-(k*50);
      //totalnotes+=k;
      std::cout<<k<<" ";
      i=20;
      break;

      case 20:
      k=n/20;
      n=n-(k*20);
      //totalnotes+=k;
      std::cout<<k<<" ";
      i=1;
      break;

      case 1:
      k=n/1;
      n=n-(k*1);
      //totalnotes+=k;
      std::cout<<k<<" ";
      i=0;
      break;

      case 0:
      exit(0);
    }
  }
  return 0;
}

