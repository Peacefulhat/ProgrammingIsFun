#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// word number and occurence of word and and the word itself.
// returns index(start,end) of t in s ,-1 if not found;
typedef struct {
  int start, end;
} index;
index strrindex(char s[], const char t[]) {
  index store;
  int j = 0;
  store.start = store.end = -1;
  for (int i = 0; s[i] != '\0'&&t[j]!='\0'; i++) {
    if (s[i] == t[j]) {
      if (store.start == -1) {
        store.start = i;
      }
      store.end = i;
      j++;
    } else {
      j=0;
      store.start = store.end = -1;
    }
  }
  if (t[j] == '\0') {
    return store; // Pattern found
  } else {
    store.start = store.end = -1; // Pattern not found
    return store;
  }
}
// converts stirng s to double.
int power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * power(base, exp - 1);
}

long double atof3(const char s[]) {
    long double store = 0;
    int period = 0;  // Initialize period to 0
    short set = 0;
    int i = 0;
    
    while (s[i] != '\0') {
        if (s[i] == '.') {
            set = 1;
            i++;  // Move to the digit after the decimal point
            continue;
        } else {
            store = store * 10 + (double)(s[i] - '0');
        }
        
        if (set == 1) {
            period++;
        }
        i++;
    }
    
    return store / (long double)(power(10, period));
}

long double atof2(const char s[]) {
    long double store = 0;
    int period = 0;
    short set = 0;
    int i = 0;
    int sign = 1;  // Sign for the exponent part
    long double powerOf10 = 1.0;
    int exponent = 0;
    
    while (s[i] != '\0') {
        if (s[i] == '.') {
            set = 1;
            i++;
            continue;
        } else if (s[i] == 'e' || s[i] == 'E') {
            set = 0;
            i++;
            if (s[i] == '-') {
                sign = -1;
                i++;
            } else if (s[i] == '+') {
                i++;
            }

            // Read the exponent
            while (s[i] >= '0' && s[i] <= '9') {
                exponent = exponent * 10 + (s[i] - '0');
                i++;
            }

            break;
        } else {
            store = store * 10 + (s[i] - '0');
        }
        
        if (set == 1) {
            period++;
            powerOf10 *= 10.0;  // Adjust the power of 10 for the fractional part
        }
        i++;
    }

    return sign * (store / powerOf10) * powl(10, exponent);
}
int main() {
  //char str[] = "hello,world";
  //char t[] = "ello";
  //printf("start: %d end: %d",strrindex(str,t).start,strrindex(str,t).end);
  const char s[]= "123.45e-6";
  printf("%LE",atof2(s));
  return 0;
}
