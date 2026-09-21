// funciton prefix

#include <stdio.h>

#define FUNC_PREFIX_IMP
#define FUNC2_PREFIX_IMP
#include "functionPrefix.h"

int main(){
    Stack s;
    StackIni(&s,100);
    char str[] = "1 22 - 3 4 + *";
    Calculate(str, &s);
    
    return 0;
}


