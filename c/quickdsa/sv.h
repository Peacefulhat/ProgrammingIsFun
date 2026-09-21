// currently every kind of data is being repersented as string views.
#ifndef SV_H
#define SV_H

typedef struct
{
    const char* Data;
    int32 Count;
}string_view;


#define PRINT_SV(Sv) printf("%.*s\n", (Sv).Count, (Sv).Data)

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
        return (-1);
    }
    return (strncmp(A.Data, B.Data, A.Count) == 0);
}

#endif