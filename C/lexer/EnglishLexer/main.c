#define LEXER_IMPLEMENTATION
#include "lexer.h"

// No Freeing of Node list for now
int main()
{
    char* Buffer = ReadEntireFile("English.txt");
    string_view Sv = CstrAsSv(Buffer);
    /*
    while(Sv.Count )
    {
        string_view Line = SvChopByDelim(&Sv, '\n');
        Line = SvTrim(Line);
        while(Line.Count)
        {
            string_view ChopedValue = SvChopByDelim(&Line, ' ');
            PRINT_SV(ChopedValue);
        }
    }
    */
    return (0);
}
