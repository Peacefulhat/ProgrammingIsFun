#pragma once
#include<iostream>
#include<vector>
#include<string>

//11
//pattern
//1
//2 3
//4 5 6
//7 8 9

void pattern6(int n){
  int rows=1;
  int i=1;
  while(rows<=n){
    int cols=1;
    while(cols<=rows){
      std::cout<<i;
      i=i+1;
      cols=cols+1;
    }
    std::cout<<"\n";
    rows=rows+1;
  }
}

//12
//pattern 
//1
//2 3
//3 4 5
//4 5 6 7

void pattern7(int n){
int main(){
  int rows=1;
  while(rows<=n){
    int cols=1;
   while(cols<=rows){
    std::cout<<rows+(cols-1);
      cols=cols+1;
    }
    std::cout<<"\n";
    rows=rows+1;
  }
}

//13
//pattern
// 1
// 2 1
// 3 2 1
// 4 3 2 1

 void pattern8(int n){
  int rows=1;
  while(rows<=n){
  int cols=1;
    while(cols<=rows){
    std::cout<<rows+((cols-1)*(-1));
      cols=cols+1;
    }
    std::cout<<"\n";
    rows=rows+1;
  }
}

 
//14
//pattern
// AAA
// BBB
// CCC

 void pattern9(int n){
  int rows=1;
  char ch=65;
  while(rows<=n){
  int cols=1;
    while(cols<=n){
    std::cout<<ch;
    cols=cols+1;
    }
    ch=ch+1;
    std::cout<<"\n";
    rows=rows+1;
  }
}

//15
//pattern
// A B C
// A B C
// A B C
 void pattern10(int n){
 int rows=1;
  while(rows<=n){
   int cols=1;
    while(cols<=n){
      std::cout<<char(65+cols-1);
      cols=cols+1;
    }
    std::cout<<"\n";
    rows=rows+1;
  }
}

 //16
//pattern
// A B C
// D E F
// G H I

void pattern11(int n){
  int rows=1;
  char ch = 65;
  while(rows<=n){
    int cols=1;
    while(cols<=n){
      std::cout<<ch;
      ch=ch+1;
      cols=cols+1;
    }
    std::cout<<"\n";
    rows=rows+1;
  }
}


 //17
//pattern
//A B C
//B C D
//C D E

void pattern12(int n){
  int rows=1;
  char ch=65;
  while(rows<=n) {
  int cols=1;
    while(cols<=n){
      std::cout<<char((ch+cols-1)); 
      cols=cols+1;
    }
    ch=ch+1;
    std::cout<<"\n";
    rows=rows+1;
  }
}

//18
//pattern
//D 
//C D 
//B C D 
//A B C D

 void pattern13(int n){
  int ch='A'+n-1;
  int rows=1;
  while(rows<=n){
  int cols=rows;
    while(cols>=1){
      std::cout<<char(ch+((cols-1)*(-1)));
      cols=cols-1;
    }
    std::cout<<"\n";
    rows=rows+1;
  }
}

//19
//pattern
//         *
//        **
//       ***
//      ****

 void pattern14(int n){
  int rows=1;
  while(rows<=n){
  int space=n-rows;
  while(space>=1){
    std::cout<<" ";
      space=space-1;
  }
    int col=1;
  while(col<=rows){
      std::cout<<"*";
      col=col+1;
    }
    std::cout<<"\n";
  rows=rows+1;
  }
}


//20
//pattern
//****
//***
//**
//*

 void pattern15(int n){
  int rows=n;
  while(rows>=1){
   int col=rows;
    while(col>=1){
      std::cout<<"*";
      col=col-1;
    }
    std::cout<<"\n";
    rows=rows-1;
  }
}

 
