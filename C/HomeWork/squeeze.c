#include<stdio.h>

void squeeze(char first[], const char second[]) {
  int k;
    for (int i = 0; second[i] != '\0'; i++) {
        for (int j =k=0; first[j] != '\0'; j++) {
            if (first[j] != second[i]) {
                first[k] = first[j];
                k++;      
      }
        }
        first[k] = '\0';
    }

    printf("%s\n", first);
}
int main() {
    char str[12];
    scanf("%s", str);

    const char str1[] = "abc";
    squeeze(str, str1);

    return 0;
}
