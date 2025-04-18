#include<stdio.h>
#define MAX 20

void itob(int n, char s[], int b) {
    int k = 0;
    switch (b) {
        case 10:
            char store[MAX/2];
            int len = 0;
            while (n != 0) {
                store[len++] = (char)(n % 10 + '0');
                n /= 10;
            }
            for (int i = len - 1; i >= 0; i--) {
                s[k++] = store[i];
            }
            s[k] = '\0';
            break;
        case 16:
            char store2[MAX/2];
            int len2 = 0;  // Initialize len2
            while (n != 0) {
                int remainder = n % 16;
                store2[len2++] = (remainder >= 10) ? (char)(remainder + 'A' - 10) : (char)(remainder + '0');
                n /= 16;
            }
            for (int i = len2 - 1; i >= 0; i--) {
                s[k++] = store2[i];
            }
            s[k] = '\0';
            break;
        case 2:
            char store3[MAX/2];
            int len3 = 0;  // Initialize len3
            while (n != 0) {
                store3[len3++] = (char)(n % 2 + '0');
                n /= 2;
            }
            for (int i = len3 - 1; i >= 0; i--) {
                s[k++] = store3[i];
            }
            s[k] = '\0';
            break;
        default:
            printf("Invalid base");
    }
}

int main() {
    char s[MAX] = {'a', '\0'};
    itob(1, s, 16);
    printf("%s", s);
    return 0;
}

