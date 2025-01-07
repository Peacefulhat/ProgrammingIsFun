#include<iostream>
#include<string>
#include<algorithm>
//TODO
// reverse a string with the help of recursion
//ip = "abcde"
//op = "edcba"
void reverse(std::string &str, int i ,int j){
  // base case
  if(i>j){
    return ;
  }
  std:: swap(str[i],str[j]);
  i++;
  j--;
  reverse(str,i,j);
}

// fast exponentiation

int power(int a, int b){
  // base case
  if(b==0){
    return 1;
  }
  int ans=power(a,b/2);// recursive call
  if(b%2==0){// b is even
    return ans*ans;
  }else{
    // b is odd
    return a*ans*ans;
  }
}
int main(){
  std::string name ="babber";
  reverse(name,0,name.size()-1);
  std::cout<<name;
  return 0;
}
