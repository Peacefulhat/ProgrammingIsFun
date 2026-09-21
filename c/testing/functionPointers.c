#include <stdio.h>
// function pointers;
int sum(int a,int b)
{
    return a+b;
}

typedef enum {
    LOG,
    WARNNING,
    PRINT
}Switch;

typedef struct {
    char *msg;
    Switch s;
}Message;

int PrintMessage(Message *msg, Switch sw)
{
    switch(sw){
    case LOG:{
        if(msg->s == LOG){
            printf("THIS IS A LOG\n");
        }
    }
    break;
        case WARNNING:{
        if(msg->s == WARNNING){
            printf("THIS IS A WARNNING\n");
        }
    }
    break;
        case PRINT:{
        if(msg->s == PRINT){
            printf("THIS IS A PRINT\n");
        }
    }
    break;
    
    default: {
        printf("HELLO,WORLD\n");
    }
}
return 0;
}

// macro that expands to a function signature for typedef
#define PRINT_MESSAGE(name) int name (Message *msg, Switch sw)

// function type
typedef PRINT_MESSAGE(print_message);

// stub function
PRINT_MESSAGE(print_message_){
    return 0;
}

print_message * PrintMessage_ = print_message_;



int squar(int x){
    return x*x;
}

int main(){
    
    int (*sumpointer)(int,int)=&sum;
    
    printf("%d\n",squar(sumpointer(1,3)));
    Message msg = {};
    PrintMessage_ = PrintMessage;
    printf("%d\n", PrintMessage_(&msg, LOG));
    
    
    return 0;
    
}
