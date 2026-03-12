#define BINARY_SEARCH_IMPLEMENTATION 
#include "Array/binarySearch.h"

int main(int argc, char** argv)
{
    int32 Even[6] = {4, 6, 10, 12, 18, 20};
    int32 Size = 6;
    Pair Result = UpperBoundLowerBound(Even, 6, 20);
    printf("[LowerBound:: %d, UpperBound:: %d]", Result.First, Result.Second);
    return 0;
}
