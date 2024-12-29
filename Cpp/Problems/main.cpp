#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void reverseArray(vector<int> &arr , int m){
    int start=m;
    int end=arr.size()-1;
    std::cout<<end<<std::endl;
    while(start<end){
      std::cout<<"{"<<start<<","<<end<<"}\n";
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        end--;
        start++;
    }    	
}

int main(){
  vector<int>a={1,2,3,4,5,6};
  reverseArray(a,3);
  for(int i=0;i<a.size();i++){
    std::cout<<a[i]<<" ";
  }
  return 0;
}
