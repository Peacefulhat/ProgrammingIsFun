#ifndef ARRAY_H
#define ARRAY_H

#include "../dstype.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 100
#define ARRAY_TYPE int32
typedef struct
{
    int32 first, second;
}Pair;

void PrintArray(ARRAY_TYPE* arr, int32 Size);

// 1)  Min and Maximum value in an array.
Pair MinMaxArray(ARRAY_TYPE* arr, int32 Size);
// 2)  Linear Search.
int32 LinearSearch(ARRAY_TYPE* arr, int32 Size, int32 Key);
// 3)  Reverse an array.
void ReverseArray(ARRAY_TYPE* arr, int32 Size);
// 4)  Swap alternate.
void SwapAlternate(ARRAY_TYPE* arr, int32 Size);
// 5)  Find Unique Element (Code Studio).
int32 UniqueElement(ARRAY_TYPE* arr, int32 Size);
// 6)  Find Duplicate in a array (Code Studio).
int32 Duplicate(ARRAY_TYPE* arr, int32 Size);
// 7)  Intersection of arrays(Code Studio). 
void FindArrayInstersection(ARRAY_TYPE* arr, int32 N, ARRAY_TYPE* arr2, int32 M );
// 8)  Pair Sum (Code Studio).
void  PairSum(ARRAY_TYPE* arr, int32 Size, int32 sum);
// 9)  Triplet Sum(Code Studio).
void tripletSum(ARRAY_TYPE* arr, int32 Size, int32 Sum);
// 10) Sort 0 and 1.
void sort0and1(ARRAY_TYPE* arr, int32 Size);
// 11) Sort 0,1,2(Code Studio).
void sort012(ARRAY_TYPE* arr, int32 Size);

#endif



#ifdef ARRAY_IMPLEMENTATION
void PrintArray(ARRAY_TYPE* arr, int32 Size)
{
    for(int32 Index = 0; Index < Size; ++Index)
    {
        // change format specifer for different types.
        printf("%d ",arr[Index]);
    }
}

Pair MinMaxArray(int32* arr, int32 Size)
{
    Pair Result = {0};
    Result.first = INT_MAX;
    Result.second = INT_MIN;
    for(int32 Index = 0 ; Index < Size; ++Index)
    {
        if(Result.first > arr[Index])
        {
            Result.first = arr[Index];
        }
        if(Result.second < arr[Index])
        {
            Result.second = arr[Index];
        }
    }
    return Result;
}

bool32 LinearSearch(int32* arr, int32 Size, int32 Key)
{
    for(int32 Index = 0; Index < Size; ++Index)
    {
        if(Key == arr[Index]) return 1;
    }
    return 0;
}

void ReverseArray(ARRAY_TYPE* arr, int32 Size)
{
    int32 Start = 0;
    int32 End = Size - 1;
    while(Start < End)
    {
        int32 Swap = arr[Start];
        arr[Start] = arr[End];
        arr[End] = Swap;
        ++Start;
        --End;
    }
    printf("\n");
}

void SwapAlternate(ARRAY_TYPE* arr, int32 Size)
{
    for(int32 Start = 0; Start < Size; Start += 2)
    {
        // Bound Check
        if(Start + 1 < Size){
            int32 Swap = arr[Start];
            arr[Start] = arr[Start + 1];
            arr[Start + 1] = Swap;
        }
    }
    printf("\n");
}

// ##,##,##,##,##,M## ->N , N = 2m+1, 



int32 UniqueElement(ARRAY_TYPE* arr, int32 Size)
{
    int32 Unique = 0;
    for(int32 Index = 0; Index < Size; Index++){

        Unique = Unique ^ arr[Index]; // a^b^a = b , 0^a = a, 
    }
    return Unique; 
}

int32 Duplicate(ARRAY_TYPE* arr, int32 Size)
{
    if(Size == arr[0] == 0) return 0;
    int32 ArraySum = 0;
    for(int32 Index = 0; Index < Size; ++Index)
    {
        ArraySum += arr[Index];
    }
    return ArraySum - ((Size * (Size-1 ))/2);
}

void FindArrayInstersection(ARRAY_TYPE* arr, int32 N, ARRAY_TYPE* arr2, int32 M )
{
    // not finished yet
    // TODO:
        // duplicated remove and incrementing and value selecting in not happening properly.
        // for square matrix it's kind of working. not sure.
    // arrays are monotonically sorted(assending order).
    int32 Index = 0;
    int32 Index2 = 0;
    while(Index < N && Index2 < M)
    {
        if(arr[Index] == arr[Index2]){
            printf("%d ", arr[Index]);
            Index2++;
            Index++;
        }
         if(arr[Index] > arr2[Index]) Index2++;
        if(arr[Index] < arr2[Index2]) Index++;
       
        
    }
    printf("\n");
}

void  PairSum(ARRAY_TYPE* arr, int32 Size, int32 sum)
{
    
}

void tripletSum(ARRAY_TYPE* arr, int32 Size, int32 Sum)
{
    
}

void sort0and1(ARRAY_TYPE* arr, int32 Size)
{
    
}

void sort012(ARRAY_TYPE* arr, int32 Size)
{
    
}

#endif
