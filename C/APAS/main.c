#include<stdio.h>
// Two sum
// not optimized solution
// it can be optimized with hashmap 
typedef struct{
  int x,y;
}pair;

pair twosum(int *arr, int size,int k){
  pair index={-1,-1};
  for(int i=0;i<size;i++){
    if(arr[i]>k){
      break;
    }
    if(arr[i]<k){
      for(int j=i+1;j<size;j++){
	if(arr[j]>k){break;}
	if(arr[i]+arr[j]==k){
	  index.x=i;
	  index.y=j;
	  break;
	}
      }
    }
  }
  return index;
}
int main(){
  int arr[4]={2,7,11,15};
  pair temp=twosum(arr, 4, 13);
  printf("%d %d",temp.x,temp.y);
  return 0;
}
