#ifndef FUNC_PREFIX_H
#define FUNC_PREFIX_H

#include <stdio.h>
#include <stdlib.h>
// Reverse Polish Evaluator
typedef enum{
    PLUS          = '+',
    MINUS         = '-',
    DIVIDE        = '/',
    MUTIPLICATION = '*',
    MODULS        = '%',
    SPACE         = ' '
}Symbols;

typedef struct {
    int Sp;
    int* Buffer;
    int Capacity;
}Stack;


 void StackIni(Stack* s, int capacity );
 void Push(Stack* s, int value);
 void StackBufferFree(Stack* s);
 void Pop(Stack* s);
 int Top(Stack* s);
 void SwapTop(Stack* s);
 void Print(Stack* s);
 void Calculate(char Str[], Stack* s);
#endif //FUNC_PREFIX_H

#ifdef FUNC_PREFIX_IMP

#define FUNC

FUNC void StackIni(Stack* s, int capacity ){
    s->Sp = -1;
    s->Capacity = capacity;
    s->Buffer = malloc(sizeof(int)*capacity);
 }

FUNC void StackBufferFree(Stack* s){
    s->Sp = -1;
    s->Capacity = 0;
    free(s->Buffer);
}   


FUNC void Push(Stack* s, int value){
    if(s->Sp >= s->Capacity - 1 ){
        printf("Stack Overflow\n");
        return ;
    }
    s->Buffer[++s->Sp] = value;
}

FUNC void Pop(Stack* s){
    if(s->Sp < 0 ){
        printf("Stack Underflow\n");
        return ;
    }
    s->Buffer[s->Sp] = 0; // random value for freed stack frame.
    s->Sp--;
}

FUNC int Top(Stack* s){
    return s->Buffer[s->Sp];
}


FUNC void SwapTop(Stack *s){
    if(s->Sp < 1){
        printf("Needed Two items on stack");
        return ;
    }
    int Temp = Top(s);
    Pop(s);
    int Temp2 = Top(s);
    Pop(s);
    Push(s, Temp);
    Push(s, Temp2);

    
}

FUNC void Print(Stack *s){
    printf("Stack::\n");
    while (s->Sp != -1){
        printf("%d ", Top(s));
        Pop(s);
    }
    printf("\n");
}
#endif


#ifdef FUNC2_PREFIX_IMP
#define FUNC2

FUNC2 void Calculate(char Str[], Stack* s) {
    for (int i = 0; Str[i] != '\0'; ++i) {
        switch (Str[i]) {
            case SPACE:
                break;

            case MINUS: {
                int b = Top(s); Pop(s);
                int a = Top(s); Pop(s);
                Push(s, a - b);
                break;
            }

            case PLUS: {
                int b = Top(s); Pop(s);
                int a = Top(s); Pop(s);
                Push(s, a + b);
                break;
            }

            case DIVIDE: {
                int b = Top(s); Pop(s);
                int a = Top(s); Pop(s);
                if (b == 0) {
                    printf("Division by zero\n");
                    return;
                }
                Push(s, a / b);
                break;
            }

            case MUTIPLICATION: {
                int b = Top(s); Pop(s);
                int a = Top(s); Pop(s);
                Push(s, a * b);
                break;
            }

            case MODULS: {
                int b = Top(s); Pop(s);
                int a = Top(s); Pop(s);
                Push(s, a % b);
                break;
            }

            default: {
                if (Str[i] >= '0' && Str[i] <= '9') {
                    int Temp = 0;
                    while (Str[i] >= '0' && Str[i] <= '9') {
                        Temp = Temp * 10 + (Str[i] - '0');
                        i++;
                    }
                    Push(s, Temp);
                
                }
                i--; // because loop will increment
                break;
            }
        }
    }
    printf("Result:: %d\n", Top(s));
}


#endif


