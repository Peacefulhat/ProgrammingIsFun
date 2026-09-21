#include<stdio.h>

int itoaWidth(int n, char s[], int fWidth) {
    int i = 0, padding = 0;

    // Convert the number to a string in reverse order
    while (n != 0) {
        s[i++] = n % 10 + '0';
        n /= 10;
    }

    // Add padding spaces if necessary
    if (i < fWidth) {
        padding = fWidth - i;
        for (int j = 0; j < padding; j++) {
            s[i++] = ' ';
        }
    }
    // Reverse the string
    int j = 0;
    for (int k = i - 1; k >= j; k--,j++) {
        char swap = s[j];
        s[j] = s[k];
        s[k] = swap;
    }

    s[i] = '\0';
    return i;
}
int main(){
  char arr[20];
  int length=itoaWidth(42343,arr,8);
  printf("%s %d",arr,length);
  return 0;
}
