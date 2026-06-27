#ifndef LEXER_H
#define LEXER_H
#include "dstype.h"

const char* WhiteSpace = " \r";

// Delimeter is something that ends the statement;
const char* Delimeter = "\r\n";

int32 RemoveSpace(char* Src)
{
    uint32 Index = 0;
    int32 IsFound = 0;
    while(*Src++ != ST_END)
    {
        if(*Src == SPACE)
        {
            IsFound = 1;
            break;
        }
    }
  /*  for(; Src[Index] != ST_END; Index++)
    {
        if(Src[Index] == SPACE)
        {
            IsFound = 1;
            break;
        }
    }
    */
    return (IsFound);
}
error Ok = {ERROR_NONE, NULL};

error Lex(char* Source, char** Beg, char** End)
{
    error Err = Ok;
    if(!Source || !Beg || !End)
    {
        ERROR_PREP(Err, ERROR_ARGUMENT, "Can not Lex Emtpy Source.");
        return (Err);
    }
    *Beg = Source;
    *Beg += strspn(*Beg, WhiteSpace);
    *End = *Beg;
    // Seek past the whitespace.
    *End += strcspn(*Beg,  Delimeter);
    return (Ok);
}

error ParseExpr(char* Source)
{
    char* Beg = Source;
    char* End = Source;
    error Err = Ok;
    while((Err = Lex(End, &Beg, &End)).error_type == ERROR_NONE)
    {
        if(End - Beg == 0) break;
        printf("Lexed: %.*s\n", End - Beg, Beg);
    }

    return (Err);

}
#endif // LEXER_H
