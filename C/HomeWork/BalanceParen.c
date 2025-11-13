#include <stdio.h>
#include <stdlib.h>

typedef enum{
    OpenParen  = '(',
    CloseParen = ')',
    OpenCurly  = '{',
    CloseCurly = '}',
    OpenSquar = '[',
    CloseSquar = ']',
}Symbols;


typedef struct {
    int Sp;
    char* Buffer;
    int Capacity;
}Stack;


void StackIni(Stack* s, int capacity ){
    s->Sp = -1;
    s->Capacity = capacity;
    s->Buffer = malloc(sizeof(char)*capacity);
}

void StackBufferFree(Stack* s){
    s->Sp = -1;
    s->Capacity = 0;
    free(s->Buffer);
}   


void Push(Stack* s, char value){
    if(s->Sp >= s->Capacity - 1 ){
        printf("Stack Overflow\n");
        return ;
    }
    s->Buffer[++s->Sp] = value;
}

void Pop(Stack* s){
    if(s->Sp < 0 ){
        printf("Stack Underflow\n");
        return ;
    }
    s->Buffer[s->Sp] = 0; // random value for freed stack frame.
    s->Sp--;
}

char Top(Stack* s){
    return s->Buffer[s->Sp];
}


void SwapTop(Stack *s){
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

void Print(Stack *s){
    printf("Stack::\n");
    for(int i = 0; i < s->Sp; ++i){
        printf("%c",s->Buffer[i]); 
    }
    printf("\n");
    
}

void MatchParen(Stack *s, char str){
    switch(str){
    case CloseParen : {
        if(Top(s) == OpenParen){
            Pop(s);
        }else{
            Push(s, str);
        }
    }break;

    case CloseCurly: {
        if(Top(s) == OpenCurly){
            Pop(s);
        }else{
            Push(s, str);
        }

    }break;
    case CloseSquar: {
        if(Top(s) == OpenSquar){
            Pop(s);
        }else{
            Push(s, str);
        }

    }break;

default:
    {
        Push(s,str);
    }
}        

}

int IsEmpty(Stack* s){
    return s->Sp < 0;
}

void BalanceParen(Stack *s, char str[]){
    printf("\nBalance Parens::\n");
    for(int i = 0 ; str[i]!='\0'; ++i){
        MatchParen(s, str[i]);
    }        

    if(IsEmpty(s)){
        printf("True");
    }else{
        printf("False");
    }

}

int main()
{
    Stack s;
    char str[] = "([{]})";
    StackIni(&s, 10);
    printf("Parens List:: \n%s\n",str);
    BalanceParen(&s, str);
    
    return 0;
}
