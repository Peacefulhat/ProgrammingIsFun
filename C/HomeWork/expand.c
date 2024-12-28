#include<stdio.h>
#define MAX 50

void expand(const char s1[], char s2[]) {
    int k = 0;
    for (int i = 0; s1[i] != '\0';) {
        if (s1[i] >= 97 && s1[i] <= 'z' && s1[i + 1] == '-'&&s1[i]<=s1[i+2]) {
            for (int j = s1[i]; j < s1[i + 2]; j++) {
                s2[k++] = (char)j;
            }
      i=i+3;
        }else if(s1[i]=='-'){
          s2[k++]=s1[i];
      i++;
    }else{
      s2[k++]=s1[i];
      i++;
    }

    }
    s2[k] = '\0';
}

int main() {
    char s1[] = "-b";
    char s2[MAX];
    
    expand(s1, s2);
    printf("%s",s2); 
    return 0;
}
