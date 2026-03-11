#define BINARY_SEARCH_IMPLEMENTATION 
#include "Array/binarySearch.h"

int main(int argc, char** argv)
{
    int32 Even[6] = {2,3,4,5,6,7};
    int32 Odd[5] = {8,9,10,11,12};
    int32 Size = 6;
    int32 SearchValue = 23;
    int32 Index = BinarySearch(Even, Size, SearchValue);
    printf("[Index:: %d, Value:: %d]", Index, SearchValue);
    return 0;
}
