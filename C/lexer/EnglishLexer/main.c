#define LEXER_IMPLEMENTATION

#include "lexer.h"

int main()
{
    char * File = ReadEntireFile("English.txt");
    TokenList(File);
    PrintTokenList(TokenListHead);
    return 0;
}
