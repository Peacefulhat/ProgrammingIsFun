#include<stdio.h>
void sizeofDataTypes(){
  printf("Size of long long: %d\n",sizeof(long long));
  printf("Size of long int: %d\n",sizeof(long int));
  printf("Size of float: %d\n",sizeof(float));
  printf("Size of double: %d\n",sizeof(double));
  printf("Size of long double: %d\n",sizeof(long double));
  printf("Size of short: %d\n",sizeof(short));
  printf("Size of char: %d\n",sizeof(char));
  printf("Size of unsigned long int: %d\n",sizeof(unsigned long int));
  printf("Size of unisgned char: %d\n",sizeof(unsigned char));
  printf("Size of long: %d",sizeof(long));
}
void constantLiteralAndFormatSpecifiers(){
  int first=123;
  long long second =13423424LL;// or 2341242342ll;
  unsigned long long third=24124321342ULL ;//or 3242342ull;
  float fourth=342.23f;
  double fifth=234.23L;
  char sixth=65;
  short seventh=244;
  unsigned short eighth=23;
  unsigned long ninth=34;
  unsigned int tenth =234;
  long double eleventh=234.34;
  void * ptr;
  char * str="hsdfka";
  printf("\n\n");
  // Format specifiers for printf()/scanf();
  printf("The first value is: %d\n",first);
  printf("The second value is: %lld\n",second);
  printf("The third value is: %llu\n",third);
  printf("The fourth value is: %f\n",fourth);
  printf("The fifth value is: %lf\n",fifth);  
  printf("The sixth value is: %c\n",sixth);
  printf("The seventh value is: %hd\n",seventh);
  printf("The eighth value is: %hu\n",eighth);
  printf("The ninth value is: %lu\n",ninth);  
  printf("The tenth value is: %u\n",tenth);
  printf("The eleventh value is: %Lf\n",eleventh);
  printf("MrVoidpointer: %p\n",ptr);
  printf("String: %s\n",str);
  

}
int main(){
  sizeofDataTypes();
  constantLiteralAndFormatSpecifiers();
  return 0;
}
