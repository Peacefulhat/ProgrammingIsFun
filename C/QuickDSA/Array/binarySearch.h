#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "../dstype.h"
#define TYPE int32

//BinarySearch
TYPE BinarySearch(TYPE* Array, int32 Size, TYPE Value);
// UpperBoundLowerBound(alternate sol)
//find lower bound first and the upper bound in
// Two different functions
Pair UpperBoundLowerBound(TYPE* Array, int32 Size, TYPE K);
//Search insert position of K in Sorted array.
TYPE SeachInsertPosition(TYPE* Array, int32 Size, TYPE Value);
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

Pair UpperBoundLowerBound(TYPE* Array, int32 Size, TYPE K)
{
    Pair Result = {-1, -1};
    int32 Start = 0;
    int32 End = Size - 1;
    // if End and Start get out of int range .
    int32 Mid = Start + (End - Start) / 2;

    while(Start <= End)
    {
        if(Array[Mid] > K )
        {
            Result.Second = Mid;
            End = Mid - 1;

        }
        if(Array[Mid] <= K)
        {
            Result.First = Mid;
            Start = Mid + 1;

        }
        Mid = Start + (End-Start) / 2;
    }

    return Result;
}

TYPE SeachInsertPosition(TYPE* Array, int32 Size, TYPE K)
{
    int32 Save = 0;
    int32 Start = 0;
    int32 End = Size - 1;
    int32 Mid = Start + ((End-Start)/2);
    while(Start <= End)
    {

        if(Array[Mid] == K)
        {
            return Mid;
        }
        if(Array[Mid] > K)
        {
            Save = Mid;
            End = Mid - 1;
        }
        if(Array[Mid] < K)
        {
            Save = Mid;
            Start = Mid + 1;
        }
        Mid = Start + ((End-Start)/2);
    }
    if(Array[Save] < K){

        Save +=1;
    }
    return Save;
}
#endif
