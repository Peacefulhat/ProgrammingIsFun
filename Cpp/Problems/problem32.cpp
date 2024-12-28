//32

//max and min value in array
#include<iostream>
#include<climits>
void maxMin(int arr[],int size){
int max=arr[0];
int min=arr[0];
for(int i=0;i<size;i++){
 if(arr[i]>max){
      max=arr[i];
    }
  if(arr[i]<min){
      min=arr[i];
    }
  }
  std::cout<<"Min and Max value of array: "<<min<<" "<<max;
}
int main(){
  int size;
  std::cin>>size;
  int arr[100];
  for(int i=0;i<size;i++){
    std::cin>>arr[i];
  }
  maxMin(arr,size);
  return 0;
}
