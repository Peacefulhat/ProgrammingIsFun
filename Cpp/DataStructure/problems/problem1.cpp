// find left most ocurrence and right most occurence of a element in a sorted array
//eg {0,1,3,3,3,5} key =3;
// output {2,4}
// key not present in array then return {-1,-1}
// total no of occurence of key element;
#include<iostream>
struct occur{
    int first,last;
};
int firstOccurence(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(key==arr[mid]){
            ans=mid;
            end=mid-1;
        }
        if(key>arr[mid]){
            start=mid+1;
        }
        if(key<arr[mid]){
            end=mid-1;
        }
    }
    return ans;
}
int LastOccurence(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(key==arr[mid]){
            ans=mid;
            start=mid+1;
        }
        if(key>arr[mid]){
            start=mid+1;
        }
        if(key<arr[mid]){
            end=mid-1;
        }
    }
    return ans;
}


occur firstLastOccurence(int arr[],int size,int key){
 occur store;
 store.first=firstOccurence(arr,size,key);
 store.last=LastOccurence(arr,size,key);
 return store;
}

int totalOccurence(occur store){
    return (store.last-store.first)+1;
}
int main(){
    int arr[5]={1,2,3,3,5};
    std::cout<<"first and last occurence of key: {";
    std::cout<<firstLastOccurence(arr,5,3).first<<",";
    std::cout<<firstLastOccurence(arr,5,3).last<<"}"<<std::endl;
    std::cout<<"total occurence : "<<totalOccurence(firstLastOccurence(arr,5,3));
 return 0;
}