#include<stdio.h>
enum errorFlags{
  Ok,Err
};
// good way to use enums is that you just have to 
enum errorFlags stateOfMachine(enum errorFlags flag){
  return flag;
}
struct pageState{
  enum errorFlags state;
  int*pagePointer;
};
enum errorFlags*Global=NULL;
int main(){
  int baseMemoryAddress=0x23fa;
  enum errorFlags finite=Ok;// this is allowed in c but its consider a bad practice beacuse it will store non defined value{tha is not present in enum type } and lead to less readable and maintainable code .
  //printf("%d",stateOfMachine(finite));
  Global=&finite;
  printf("%d\n",*Global);
  struct pageState memoryPage;
  memoryPage.state=stateOfMachine(finite);
  memoryPage.pagePointer=&baseMemoryAddress;
  printf("page state: %d\n",memoryPage.state);
  printf("Address of base page in memory: %p",memoryPage.pagePointer);
  return 0;
}
