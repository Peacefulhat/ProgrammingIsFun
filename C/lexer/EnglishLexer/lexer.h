#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

typedef int8_t  int8;
typedef uint8_t uint8;
typedef int32_t int32;
typedef int64_t int64;
typedef uint64_t uint64;

typedef struct
{
    const char* Data;
    int32 Count;
}string_view;

string_view CstrAsSv(const char* Cstr);
string_view SvTrimLeft(string_view Sv);
string_view SvTrimRight(string_view Sv);
string_view SvTrim(string_view Sv);
string_view SvChopByDelim(string_view* Sv, char Delim);
void SvLeft(string_view* Sv, int N);
int SvEq(string_view A, string_view B);

// File Reading
int64 GetFileSize(FILE* File);
char* ReadEntireFile(char* FilePath);

// Token
typedef struct line line;

struct line
{
    string_view* Word;
    int32 WordCount;
    line* Next;
};

typedef struct
{
    line* Begin;
    line* End;
    int32 LineCount;
}eng_token;

#endif


#ifdef LEXER_IMPLEMENTATION

int64 GetFileSize(FILE* File)
{
    if(!File)
    {
        return (0);
    }

    if(fseek(File, 0, SEEK_END) != 0)
    {
        return (0);
    }
    int64 Size = ftell(File);
    return (Size);
}

char* ReadEntireFile(char* FilePath)
{
    FILE* File = fopen(FilePath, "r");
    if(!File)
    {
        return (NULL);
    }

    int64 Size = GetFileSize(File);
    fseek(File, 0, SEEK_SET);
    char* FContents = (char*)malloc(Size + 1);

    if(fread(FContents, 1, Size, File) != Size)
    {
        return (NULL);
    }
    FContents[Size] = '\0';
    return (FContents);
}


#define PRINT_SV(Sv) printf("|%.*s|\n", (Sv).Count, (Sv).Data)

string_view CstrAsSv(const char* Cstr)
{
    return (string_view){
        .Data = Cstr,
        .Count = strlen(Cstr)
    };
}

string_view SvTrimLeft(string_view Sv)
{
    int32 Index = 0;
    while(Index < Sv.Count && Sv.Data[Index] == ' ')
    {
        ++Index;
        
    }
    return (string_view){
        .Data = Sv.Data + Index,
        .Count = Sv.Count - Index
    };
}

string_view SvTrimRight(string_view Sv)
{
    int32 Index = 0;
    while(Index < Sv.Count && isspace(Sv.Data[Sv.Count - 1 - Index]))
    {
        ++Index;
    }    return (string_view){
        .Data = Sv.Data,
        .Count = Sv.Count - Index
    };
}

string_view SvTrim(string_view Sv)
{
    return (SvTrimRight(SvTrimLeft(Sv)));
}

// chop By string or something
// string_view SvChopBySv(string_view*Sv, string_view Sv);
// string_view SvChopByDelim(string_view*Sv, char* Delim);

string_view SvChopByDelim(string_view* Sv, char Delim)
{
    int32 Index = 0;
    while(Index < Sv->Count && (Sv->Data[Index] != Delim ))
    {
        Index++;
    }
    string_view Result = {Sv->Data, Index};
    if(Index < Sv->Count)
    {
        Sv->Data+=Index + 1;
        Sv->Count-= Index + 1;
    }
    else // return what every there is left
    {
        Sv->Count -= Index ;
        Sv->Data += Index ;
    }
    return (Result);
}

void SvLeft(string_view* Sv, int N)
{
    if(Sv != NULL)
    {
        Sv->Data += N;
        Sv->Count -= N;
    }
}

int SvEq(string_view A, string_view B)
{
    if(A.Count != B.Count)
    {
        // if length are not equal.
        return (-1);
    }
    return (strncmp(A.Data, B.Data, A.Count) == 0);
}



#endif
