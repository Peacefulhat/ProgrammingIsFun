// bubbleSort
#include<iostream>
#include<vector>
#define SWAP(a, b) \
    { \
        typeof(a) temp = a; \
        a = b; \
        b = temp; \
    }

using namespace std;

void bubbleSort(vector<int>&arr,int n){
for(int i=0;i<n-1;i++){//rounds
cout<<"number of iterations:"<<i+1<<"\n";
bool swapped=false;
for(int j=0;j<n-i-1;j++){
    //comparsions
if(arr[j]>arr[j+1]){
    SWAP(arr[j],arr[j+1]);
    swapped=true;
}
}
if(!swapped){
    break;
}
}
}


int main(){
    vector<int>arr={1,2,3,4,5};
    int n=arr.size();
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        if(i==n-1){
            cout<<arr[i];
        }else{

        cout<<arr[i]<<"\n";
        }
    }
    return 0;
}