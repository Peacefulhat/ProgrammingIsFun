//37

//intersection of arrays
#include<iostream>
#include<climits>
//brute force method
void findArrayInstersection(int arr[], int n,int arr2[] ,int m ){
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(arr[i]<arr2[j]){
            break;
        }
        if(arr[i]==arr2[j]){
            std::cout<<arr2[j]<<" ";
            arr2[j]=INT_MIN;
            break;
        }
    }
}}

//2 pointer approach
void findArrayInstersection2(int arr[],int n,int arr2[],int m){
    int i=0,j=0;
    while(i<n&&j<m){
       if(arr[i]<arr2[j]){
        i++;
       } 
       if(arr[i]==arr2[j]){
       std::cout<<arr[i]<<" " ;
        i++;
        j++;
       }
       if(arr[i]>arr2[j]){
        j++;
       }
    }
}


int main(){
    int arr[5]={1,2,3,4,3},arr2[2]={3,4};
    findArrayInstersection2(arr,5,arr2,2); 
    return 0;
}
