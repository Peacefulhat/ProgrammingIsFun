#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "../dstype.h"
#define TYPE int32

//BinarySearch
TYPE BinarySearch(TYPE* Array, int32 Size, TYPE Value);

#endif // BINARY_SEARCH_H

#ifdef BINARY_SEARCH_IMPLEMENTATION

TYPE BinarySearch(TYPE* Array, int32 Size, TYPE Value)
{
    int32 Start = 0;
    int32 End = Size - 1;
    // if End and Start get out of int range . 
    int32 Mid = Start + (End - Start) / 2;
    TYPE Ind = -1;
    while(Start <= End)
    {
        if(Array[Mid] == Value)
        {
            Ind = Mid;
            return Ind;
        }
        if(Value > Array[Mid]) Start = Mid + 1;
        if(Value < Array[Mid]) End = Mid - 1;
        Mid = Start + (End-Start) / 2;
    }
    return Ind;
}

#endif
