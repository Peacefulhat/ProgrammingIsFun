#include<stdio.h>
#include<string.h>
// in c, strings barely exist.
// string literals: are stored as an array of character terminated by null characater.
// string are enclosed by double quotes.

//Note: character are enclosed by single quotes.
void print(char*s){
  int i=0;
  while(s[i]!='\0'){
    printf("%c",s[i]);
    i++;
  }
  printf("\n");
}
int main(){
  // string variable;
  
    char *s ="Hello, world!";
 // Another option is this, nearly equivalent to the above char* usage:

//char s[14] = "Hello, world!";

// or, if we were properly lazy and have the compiler
// figure the length for us:

//char s[] = "Hello, world!";
 //s[0]='z';// we get undefined behaviour.
 //So remember: if you have a pointer to a string literal, don’t try to change it! And if you use a string in double quotes to initialize an array, that’s not actually a string literal.
    char t[]="Hello,Again!";
    t[0]='z';
    print(t);
    printf("string length: %d\n",strlen(t));
    char ss[100];
    strcpy(ss,t);// copy string (des,sourc)
    print(ss);
  return 0;
}
