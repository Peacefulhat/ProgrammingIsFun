#ifndef DSTYPE_H
#define DSTYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

typedef int8_t  int8;
typedef int8_t   schar;
typedef int16_t int16;
typedef int32_t int32;
typedef int32_t bool32;
typedef int64_t int64;

typedef uint8_t  uchar;
typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef float  real32;
typedef double real64;

typedef struct {
    char* Start;
    int32 Count;
}string_view;

// File Reading
int64 FileSize(FILE* File)
{
    if(!File)
    {
        return (0);
    }

    fpos_t Original;

    if(fgetpos(File, &Original ) != 0)
    {
        printf("fgetpos() failed: %i\n", errno);
        return (0);
    }

    fseek(File, 0, SEEK_END);
    int64 Out = ftell(File);

    if(fsetpos(File, &Original) != 0)
    {
        printf("fsetpos() failed: %i\n", errno);
    }

    return (Out);
}

char* FileContents(char* FilePath)
{
    FILE* File = fopen(FilePath, "r");
    if(!File)
    {
        printf("Could not open file at %s \n", FilePath);

    }

    int64 Size = FileSize(File);
    char * FContents = (char*) malloc(Size + 1);
    size_t BytesRead = fread(FContents, 1, Size, File);
    if(BytesRead != Size)
    {
        free(FContents);
        return (NULL);
    }

    FContents[Size] = '\0';
    return (FContents);
}


//Error Type
typedef struct {

enum
{
    ERROR_NONE = 0,
    ERROR_ARGUMENT,
    ERROR_TYPE,
    ERROR_GENERIC,
    ERROR_SYNTAX,
    ERROR_TODO,
}error_type;

char* Message;

}error;


#define ERROR_CREATE(Name, Type, Message) error(Name) = {(Type), (Message)}

#define ERROR_PREP(Name, Type, Msg)     \
do{                                     \
    (Name).error_type = (Type);         \
    (Name).Message =  (Msg);            \
}                                       \
while(0)                                \

void PrintError(error Err)
{
    if(Err.error_type == ERROR_NONE)
    {
        return;
    }

    printf("ERROR: ");
    switch(Err.error_type)
    {

        case ERROR_ARGUMENT:
        {
            printf("Invalid Arguments");
        }break;

        case ERROR_TYPE:
        {
            printf("Mismatched types ");
        }break;

        case ERROR_GENERIC:
        {

        }break;

        case ERROR_SYNTAX:
        {
            printf("Invalid Syntax");
        }break;

        case ERROR_TODO:
        {
            printf("TODO (Not Implemented)");
        }break;

        default:
        {
            printf("Unknown Error Type");
        }
    }

    if(Err.Message)
    {
        printf("\n > %s\n", Err.Message);
    }
}


#endif //DSTYPE_H