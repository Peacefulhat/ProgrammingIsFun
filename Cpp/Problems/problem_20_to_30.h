#pragma once

#include<iostream>
#include<string>
#include<vector>

//21
//pattern
//****
// ***
//  **
//   *
void pattern16(int n){
  int row=1;
  while(row<=n){
  int space =row-1;
  while(space>=1){
      std::cout<<" ";
      space=space-1;
    }
    int col=n-row+1;
    while(col>=1){
      std::cout<<"*";
      col=col-1;
    }
    std::cout<<'\n';
    row=row+1;
  }
}

//22
//pattern 
// 1111
//  222
//   33
//    4

void pattern17(int n){
  int row=1;
  while(row<=n){
    int space=row-1;
    while(space>=1){
      std::cout<<" ";
      space=space-1;
    }
    int col=n-row+1;
    while(col>=1){
      std::cout<<row;
      col=col-1;
    }
    std::cout<<"\n";
    row=row+1;
  }
}

//23
//pattern
//    1
//   22
//  333
// 4444

void pattern18(int n){
 int row=1;
  while(row<=n){
    int space=n-row;
    while(space>=1){
      std::cout<<" ";
      space=space-1;
    }
    int col=row;
    while(col>=1){
      std::cout<<row;
      col=col-1;
    }
    std::cout<<"\n";
    row=row+1;
  }
}

  //24
//pattern
// 1234
//  234
//   34
//    4

void pattern19(int n){

  int row=1;
  while(row<=n){
   int space=row-1;
    while(space>=1){
      std::cout<<" ";
      space=space-1;
    }
    int col=1;
     while(col<=n-row+1){
     std::cout<<row+(col-1);
      col=col+1;
    }
    std::cout<<'\n';
    row=row+1;
  }
}

//25
//pattern
//    1
//   23
//  456
// 78910

void pattern20(int n){
 int row=1,i=1;
 while(row<=n){
   int space=n-row+1; 
  while(space>=1){
      std::cout<<" ";
      space=space-1;
    }
    int col=row;
    while(col>=1){
      std::cout<<i;
      i=i+1;
      col=col-1;
    }
    std::cout<<"\n";
    row=row+1;  
  }
}


//26
//pattern
//   1
//  121
// 12321
//1234321
void pattern21(int n){
  int row=1;
  while(row<=n){
    int space=n-row;
    while(space>=1){
      std::cout<<"  ";
      space=space-1;
    }
    int col,k;
    col=1;
    while(col<=row){
      std::cout<<col<<" ";
      col=col+1;
    }
    k=1;
    while(k<=row){
      if(row>1){
        int a=(row-1)+((k-1)*(-1));
        if(a){
        std::cout<<a<<" ";
        }
       }
      k=k+1;
    }std::cout<<"\n";
    row=row+1;
  } 
}

//27
//pattern
// 1234554321
// 1234**4321
// 123****321
// 12******21
// 1********1
void pattern22(int n){
  int i=0;
  int row=1;
  for(;row<=n;row++){
    for(int start=1;start<=n;start++){
      if(start>=(n-row+2)){
        std::cout<<"*"; 
      }else{
        std::cout<<start;
      }
    }

    for(int End=n;End>=1;End--){
      
    if(End>=(n-row+2)){
        std::cout<<"*";
      }else{
        std::cout<<(End);
      } 
    }
    std::cout<<"\n";
    }
}


//28

// how many notes can we get if we have 100,50,20,1
// greedy approach
void notes(int n){
int main(){
  int k=0, n,totalnotes=0,i=100;
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
}

//29
// Arithmetic progression
// ap = 3*n+7;

int ap(int n){
  return (3*n)+7;
}


//30
// count set bits of a and b;
 
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
