#include<iostream>
#include<string>
#define MAX 1024
#define WIDTH 20
#define unsigned int uint

void charArray(){
char name[WIDTH];
 std::cout<<"Enter your name "<<std::endl;
 std::cin>>name;
 name[2]='\0';
 std::cout<<name;
}

uint length(char arr[]){
uint size;
for( size=0;arr[size]!='\0';size++);
return size;
}

int main(){
    // integer array.
   // int block[MAX];
    //char name[WIDTH];
    //initilize
    //int block[MAX]={1,2,3,4};
    //char name[WIDTH]={'b','a','b','b','a','r','\0'};
// using loops.
//outputing 
//1)using index.
//std::cout<<name[3]<<' ';
//std::cout<<block[2]<<' ';
//2) or iterating over the arrays.
//std::cout<<name<<' '; //similar to printf("%s",name);
//for(int i=0;i<MAX;i++){
 //   std::cout<<block[i]<<" ";
//}

std::string str="name";
    return 0;
}