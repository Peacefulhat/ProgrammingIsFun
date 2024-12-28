#include <stdio.h>
#define MAX 100
#define t int
int recent;
static int sp = -1;
static t stack[MAX];

void push(int n) {
    if (sp >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    sp++;
    stack[sp] = n;
}

int pop() {
    if (sp < 0) {
        printf("Stack Underflow\n");
        return -1; // You should handle underflow appropriately in your application
    }
    recent=stack[sp];
    return stack[sp--];
}
int peek(){
  recent=stack[sp];
  return stack[sp];
}
int recentValue(){return recent;}
void swap(){
  int temp=peek();
  pop();
  int tt=pop();
  push(temp);
  push(tt);
}
void operations(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        switch (str[i]) {
            case '-': {
                int value = pop();
                push(pop() - value);
                break;
            }
            case '+': {
                int value2 = pop();
                push(pop() + value2);
                break;
            }
            case '/': {
                int value3 = pop();
                if (value3 != 0) {
                    push(pop() / value3);
                } else {
                    printf("Error: Division by zero");
                    return;
                }
                break;
            }
            case '*': {
                int value4 = pop();
                push(pop() * value4);
                break;
            }
            case '%':
            int value5=pop();
            push(value5%pop());
            break;
            default: {
                int temp = 0;
                while (str[i] >= '0' && str[i] <= '9') {
                    temp = temp * 10 + (int)(str[i] - '0');
                    i++;
                }
                push(temp);
                continue;
            }
        }
        i++;
    }
    printf("%d", pop());
}

int main() {
   // char str[] = "1 22 - 3 4 + *";
   // operations(str);
  push(234);
  push(2311);
  push(2);
  push(23);
  //printf("%d",pop());
  //printf(" %d\n",peek());
  swap();
  printf("%d",peek());
  pop();
  printf(" %d",peek());
  printf("%d ",recentValue());
    return 0;
}
