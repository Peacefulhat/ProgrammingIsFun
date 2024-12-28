//36

// find duplicate in array
#include<iostream>

int duplicate(int arr[],int size){
int sum =0;
sum = ((size-1)*(size))/2;
int sum2=0;
for(int i=0;i<size;i++){
sum2+=arr[i];
}
return sum2-sum;

}

int duplicateWithXor(int arr[]){
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];
    }
    for(int i=1;i<size;i++){
        ans=ans^i;
    }
    return ans;
}


int main(){
int arr[7]={6,3,1,5,4,3,2};
std::cout<<duplicate(arr,7);
 return 0;
}
