#include<iostream>
int main(){
  int a =3;
  std::cout<<a<<std::endl;
  if(true){
    int b=5;//only exits inside if block
    std::cout<<b<<std::endl;
  }
  int b=1; 
  //int b=2; redefination not allowed 
  std::cout<<b<<std::endl;
  int i=8;
 for(;i<8;i++){
    std::cout<<"HI"<<std::endl;
  }
  return 0;
}
