// Selection sort
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void selectionSort(vector<int>&arr,int n){
for(int i=0;i<n-1;i++){
int minIndex=i;// find minindex 
for(int j=i+1;j<n;j++){
if(arr[minIndex]>arr[j]){ // check if there is smaller minindex in the remaing space

      minIndex=j; 
}
}//swap minIndex value and the arr[i];value
if(minIndex!=i){
swap(arr[minIndex],arr[i]);
}
}
for(int i=0;i<n;i++){
    cout<<arr[i]<<"\n";
}
}

int main(){
    vector<int>a={64,25,12,22,11,2};
    int n=6;
    selectionSort(a,n);
    return 0;
}