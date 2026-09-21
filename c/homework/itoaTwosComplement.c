#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // Swap characters at start and end
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move indices towards the center
        start++;
        end--;
    }
}
char *itoa(int n,char s[]){
  int i,sign;
  if((sign=n)<0){
    n=-n;
  }
  i=0;
  do{
    s[i++]=n%10+'0';
  }while(n/=10);
  if(sign<0){
    s[i++]='-';
  }
  s[i]='\0';
  reverseString(s);
  return s;  
}
char *itoaTwosComplement(int n,char s[]){ // long long for handling larger neagtive value;
  int i;
  long long sign;
  if((sign=n)<0){
    n=-n;
  }
  i=0;
  do{
    s[i++]=n%10+'0';
  }while(n/=10);
  if(sign<0){
    s[i++]='-';
  }
  s[i]='\0';
  reverseString(s);
  return s;  
}

int main(){
  char arr[10];
  printf("%s",itoa(-23,arr));
  
  return 0;
}
