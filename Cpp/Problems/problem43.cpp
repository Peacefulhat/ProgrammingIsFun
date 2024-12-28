//49

#include<iostream>
// sqrt of number using binary search .(leet code).
int sqrt_of_number(int n){// integer only
int s=0;
int e=n;
long long int mid=s+(e-s)/2;// to handle the interger overflow long long int.
long long int ans=-1;
while(s<=e){
if(mid*mid==num){
return mid;
}
if(mid*mid>n){
e=mid-1;
}
if(mid*mid<n){
   ans=mid; 
    s=mid+1;
}
mid=s+(e-s)/2;
}
return ans;
}

// have decimal values also
double real_sqrt(int n,int precision, int tempsol){
double factor=1;
double ans=tempsol;
for(int i=0;i<precision;i++){
factor=factor/10;
for(double j=ans;j*j<n;j=j+factor){
ans=j;
}
}
return ans;
}

int main(){
return 0;
}
