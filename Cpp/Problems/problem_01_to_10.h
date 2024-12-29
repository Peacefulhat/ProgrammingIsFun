#pragma once
#include<iostream>
#include<vector>
#include<string>

// problem 1 to 10.

//1
// to check if given character is lowercase or uppercase or a number.
void characte_checker(char ch){
   if(ch>='a'&&ch<='z'){
    std::cout<<"This is lowerCase";
    return;
  }
    if(ch>='A'&&ch<='Z'){
    std::cout<<"This is lowerCase";
    return;
  }
    if(ch>='0'&&ch<='9'){
    std::cout<<"This is lowerCase";
    return;
  }
}


//2
// sum of n number starting from 1 to n

int sum_of_numbers(int n){
  int sum=0;
  for(int i=1;i<=n;i++){
    sum+=i;
  }
  return sum;
}


//3
// find sum of all even numbers from 0 to n

int even_sum(int n){
  int sum=0;
  for(int i=2;i<=n;i+=2){
    sum+=i;
  }
  return sum;
}

//4
// Farenheit to Celsius

float farenheit_to_celsius(float farenheit)
{
  return ((farenheit-32)*5)/9.0;  
}

//5
//check if a number is prime or not

bool is_prime(int n){
 int i=2;
 while(i<=n-1){
   if(n%i==0){
  return false;
    }
   i=i+1;
 }
  return true;
}

//6
//pattern
//****
//****
//****
//****

void pattern1(int rows){
  int start =1;
 while(start<=rows*rows){
 if(start%rows==0){
   std::cout<<"*\n";
 }else{
   std::cout<<"*";
 }
 start=start+1;
}
}

//7
//pattern rows =colomns
//1 1 1
//2 2 2 
//3 3 3
//n n n

void pattern2(int rows){
  int start=1;
  int i=1;
 while(start<=rows*rows){
  if(start%rows==0){
      std::cout<<i<<"\n";
      i++;
    }else{
      std::cout<<i;
    } 
    start=start+1;
  }
}


//8
//pattern 
//1 2 3 4
//1 2 3 4 
//1 2 3 4
//1 2 3 4

void pattern3(int rows){
 int start=1,i=1;
  while(start<=rows*rows){
    if(start%rows==0){
      std::cout<<i<<"\n";
      i=i+1;
    }else{
      std::cout<<i;
      i=i+1;
    }
    start=start+1;
  }
}


//9
//pattern
//*
//**
//***
//****
//*****
void pattern4(int rows){
   int i=1;
  while(i<=rows){
    int j=1;
    while(j<=i){
    std::cout<<"*";
    j=j+1;
    }
    std::cout<<"\n";
    i=i+1;
  
  }
}

//10
//pattern 
//1
//2 2
//3 3 3 
//4 4 4 4
void pattern5(int n){
  int rows=1;
  while(rows<=n){
  int cols=1;
  while(cols<=rows){
      std::cout<<rows;
      cols=cols+1;
    }
    std::cout<<"\n";
    rows=rows+1;
  }
}

