//39

//sort 0 and 1
#include<iostream>
// 2pointer approach
void sort0and1(int arr[],int size){
    int i=0,j=size-1;
    while(i<j){
    while(arr[i]==0&&i<j){
        i++;
    }
    while(arr[j]==1&&i<j){
        j--;
    }
    if(arr[i]==0&&arr[j]==1&&i<j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    i++;
    j--;
    }
    }
}
void sort0and1Version2(int arr[],int size){
    for(int i=0,j=size-1;i<j;){
        if(i<j){
            while(arr[i]==0){
                i++;
            }
            while(arr[j]==1){
             j--;
          }
          int temp =arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
          i++;
          j--;
        }

    }
}
void printArray(int arr[],int size){
    std::cout<<"{";
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<",";
    }
    std::cout<<"}\n";
}

int main(){
    int arr[5]={0,0,1,1,0};
    printArray(arr,5);
    sort0and1Version2(arr,5);
    printArray(arr,5);
    return 0;
}
