#define LEXER_IMPLEMENTATION
#include "lexer.h"

// No Freeing of Node list for now
int main()
{
    char* File = ReadEntireFile("English.txt");
    Tokenizer(File, WORD);
    PrintTokenList(Head);
    return (0);
}
