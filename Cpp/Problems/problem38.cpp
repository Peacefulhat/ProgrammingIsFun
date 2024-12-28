//38

// pair sum;
#include<iostream>

void  pairSum(int arr[],int size,int sum){
 for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        if(arr[i]+arr[j]==sum){
            std::cout<<"{"<<arr[i]<<","<<arr[j]<<"} ";
        }
    }
 }
}
// triplet sum;
void tripletSum(int arr[],int size,int sum){
for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        for(int k=j+1;k<size;k++){
         if(sum==arr[i]+arr[j]+arr[k]){
            
          std::cout<<"{"<<arr[i]<<","<<arr[j]<<","<<arr[k]<<"} ";
         }    
        }
    }
}
}
int main(){
    int arr[6]={1,2,3,1,2,3};
   // pairSum(arr,5,5);
    tripletSum(arr,5,6);
    return 0;
}
