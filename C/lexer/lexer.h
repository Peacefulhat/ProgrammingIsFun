#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    // Storage Classes and others
    C_TOKEN_AUTO,
    C_TOKEN_CONST,
    C_TOKEN_DEFAULT,
    C_TOKEN_REGISTER,
    C_TOKEN_SIZEOF,
    C_TOKEN_STATIC,
    C_TOKEN_TYPEDEF,
    C_TOKEN_VOLATILE,
    C_TOKEN_EXTERN,
    C_TOKEN_RETURN,

    // Types
    C_TOKEN_CHAR,
    C_TOKEN_VOID,
    C_TOKEN_SHORT,
    C_TOKEN_SIGNED,
    C_TOKEN_UNSIGNED,
    C_TOKEN_INT,
    C_TOKEN_LONG,
    C_TOKEN_FLOAT,
    C_TOKEN_DOUBLE,
    C_TOKEN_STRUCT,
    C_TOKEN_ENUM,
    C_TOKEN_UNION,
    
    // Statements
    C_TOKEN_WHILE,
    C_TOKEN_DO,
    C_TOKEN_FOR,
    C_TOKEN_CONTINUE,
    C_TOKEN_GOTO,
    C_TOKEN_IF,
    C_TOKEN_ELSE,
    C_TOKEN_SWITCH,
    C_TOKEN_BREAK,
    C_TOKEN_CASE,

}Keywords;

typedef enum {
    ADD,
    SUB,
    DIV,
    MOD,
    MUL,
    ADDEQUAL,
    SUBEQUAL,
    DIVEQUAL,
    MODEQUAL,
    MULEQUAL,
    DOUBLEEQUAL,
    
    
    
}Operators;

char ValidToken(char *Token, int Length);

#endif

#ifdef LEXER_IMPLIMENTATION


#endif//LEXER_IMPLIMENTATION
