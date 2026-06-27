#include "dstype.h"
#include "lexer.h"

void PrintUsage(char** Argv)
{
    printf("USAGE: %s <path_to_file_to_compile>\n", Argv[0]);
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        PrintUsage(argv);
        exit(0);
    }

    char* FilePath = argv[1];
    char* Contents = FileContents(FilePath);
    //free(Contents);
    error Err = ParseExpr(Contents);
    //PrintError(Err);

    return (0);
}
