#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef int8_t  int8;
typedef uint8_t uint8;
typedef int32_t int32;
// using long as int64
typedef int64_t int64;
typedef uint64_t uint64;

typedef enum
{
    WORD,
    SENTENCE
}kind;

kind NodeKind = WORD;

typedef struct
{
    char* Start;
    int32 Count;
}string_view;

typedef struct token token;

struct token
{
    string_view Sv;
    token* Next;
};

token* Head = NULL;
token* Tail = NULL;

int64 GetFileSize(FILE* File);
char* ReadEntireFile(char* FilePath);
void Append(token* Token);
void Tokenizer(char* FileContents, kind NodeKind);
void PrintTokenList(token* Head);

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

void Append(token* Token)
{
     if(Head == NULL  && Tail == NULL)
     {
        Head = Token;
        Tail = Token;
        return;
     }

    Tail->Next = Token;
    Tail = Token;
}

static void PrintStringView(string_view Sv)
{
    int64 Index = 0;
    while(Index < Sv.Count)
    {
        printf("%c",Sv.Start[Index]);
        ++Index;
    }
}
static string_view GetStringView(char* Begin, kind NodeKind)
{
    string_view Sv = {Begin, 0};
    int64 i = 0;
    switch(NodeKind)
    {
        case WORD:
        {
            while(Begin[Sv.Count++] != ' ');

        }break;

        case SENTENCE:
        {
            while(Begin[Sv.Count++] != '\n');

        }break;
    }
    PrintStringView(Sv);
    return (Sv);
}

static token* GetTokenNode(string_view Sv)
{
    token* Token = (token*) malloc(sizeof(*Token));
    Token->Sv = Sv;
    Token->Next = NULL;
    return (Token);

}

void Tokenizer(char* FileContents, kind NodeKind)
{
    int64 Index = 0;
    while(Index < strlen(FileContents))
    {
        string_view Sv = GetStringView(&FileContents[Index], NodeKind);
        token* Token = GetTokenNode(Sv);
        Append(Token);
        Index += Sv.Count;
    }
}



void PrintTokenList(token* Head)
{
    token* Temp = Head;
    while(Temp != NULL)
    {
        PrintStringView(Temp->Sv);
        printf("\n");
        Temp = Temp->Next;

    }
}

#endif
