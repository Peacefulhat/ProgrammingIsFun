//1
// to check if given character is in lower case or uppercase
#include<iostream>
int main(int argc,char** argv){
  char ch;
  std::cin>>ch;
  if(ch>='a'&&ch<='z'){
    std::cout<<"This is lowerCase";

  }else if(ch>='A'&&ch<='Z'){
    std::cout<<"This is upperCase";
  }else{
    std::cout<<"This is numeric";
  }
  std::cout<<" ";
  return 0;
}
