#include<iostream>

bool linearSearch(int arr[],int size,int n){
for(int i=0;i<size;i++){
    if(arr[i]==n){
     return true;
    }
  }
  return false;
}

int main(){
  int arr[10]={5,7,-2,10,22,-2,0,5,22,1};
  int key;
  std::cin>>key;
  if(linearSearch(arr,10,key)){
    std::cout<<"key is present";
  }else{
    std::cout<<"key is absent";
  }

 return 0;
}
