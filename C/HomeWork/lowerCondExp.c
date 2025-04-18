#include<stdio.h>


void lower(char str[]) {
  int k = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] < 97 ? str[k] = str[i] + 32 : (str[k] = str[i]);
    k++;
  }
}

int main() {
  char name[] = "HeFaA";
  lower(name);
  printf("%s", name);
  return 0;
}

