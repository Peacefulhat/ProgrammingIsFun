//44

// Book Allocation problem
//refer to notes for full disciption (code studio.)
#include<iostream>
#include<vector>
using namespace std;

// find  if the allocation of pages is possible.
bool isPosssible( vector<int>arr, int n, int m, int mid){
int studentCount = 1;
int pageSum = 0;
for(int i=0 ; i< n; i++){
if( pageSum + arr[i] <= mid ){
pageSum += arr[i];
}
else{
studentCount++;
if( studentCount > m || arr[i] > mid ){
    return false;
}
pageSum = arr[i];

}
}
return true;
}


int allocate(vector<int> arr, int n , int m) {
    for(int i = 0; i < n; i++) {
    }
    cout << endl;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i]; 
    }
    int ans = -1;
    int start = 0;
    int end = sum;
    int mid = start + (end - start) / 2;
    while(start <= end) {
        if(isPosssible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}



int main(){
vector<int>arr = {12,34,67,90};
int n = 4;
int m = 2;
cout<< allocate(arr, n, m);
return 0;
}
