#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Token Token;

 struct Token
{
    char* Value;
    Token* Next;
};

char* ReadEntireFile(char* FilePath);
Token* CreateTokenNode(char* value);
void TokenList(char * File);
void FreeFile(char *File);
void PrintTokenList(Token *Head);
#endif

#ifdef LEXER_IMPLEMENTATION

void FreeFile(char *File)
{
  if(File)
    {
      free(File);
    }
  return;
}

Token* TokenListHead = NULL;
Token* TokenListTail = NULL;

char* ReadEntireFile(char* FilePath)
{
    FILE* ReadFile = fopen(FilePath, "r");
    unsigned char* File = (unsigned char*)malloc(1024);
    int i = 0;
    int ch = 0;
    while((ch = fgetc(ReadFile))!=EOF){
      File[i] = (unsigned char)ch;
        i++;
      }
    File[++i] = '\0';
    
    return File;
}

Token* CreateTokenNode(char* value)
{
  Token* token = (Token*)malloc(sizeof(Token));
  token->Value = value;
  token->Next = NULL;
  return token;
}

void PrintTokenList(Token *Head)
{
    Token* Temp = Head;
    int i = 0;
    while(Temp!=NULL)
    {
        printf("%d: %s\n",i,Temp->Value);
        i++;
        Temp=Temp->Next;
    }
}

void TokenAppend(Token* TokenNode)
{
    if(!TokenListHead)
    {
        TokenListHead = TokenNode;
        TokenListTail = TokenNode;
    }
    TokenListTail->Next = TokenNode;
    TokenListTail = TokenNode;
}

void TokenList(char * File)
{
  int i = 0;
  Token* TknLst;
  int j = -1;
  char* Tkn = (char*)malloc(10);
  while(File[i]!='\0')
  {
      if(File[i] == ' ' ||  File[i] == '\n')
      {
          if(j == -1 && File[i] == ' ')
          {
              i++;
              continue;
          }
          Tkn[++j] = '\0';
          j = -1;
          TknLst = CreateTokenNode(Tkn);
          TokenAppend(TknLst);
          Tkn = (char*)malloc(20);
          i++;
          continue;
      }
      Tkn[++j] = File[i];      
      i++;
    }
}

#endif
