#ifndef ARRAY_H
#define ARRAY_H
#define DSTYPE_IMPLEMENTATION

#include "../dstype.h"

#define ARRAY_TYPE int32
// 0) Print Array
void PrintArray(ARRAY_TYPE* ARR, int32 Size);
// 1)  Min and Maximum value in an array.
Pair MinMaxArray(ARRAY_TYPE* Arr, int32 Size);
// 2)  Linear Search.
bool32 LinearSearch(ARRAY_TYPE* Arr, int32 Size, int32 Key);
// 3)  Reverse an array.
void ReverseArray(ARRAY_TYPE* Arr, int32 Size);
// 4)  Swap alternate.
void SwapAlternate(ARRAY_TYPE* Arr, int32 Size);
// 5)  Find Unique Element (Code Studio).
int32 UniqueElement(ARRAY_TYPE* Arr, int32 Size);
// 6) Unique Number of Occurences(LeetCode).
bool32 UniqueOccurences(ARRAY_TYPE* arr, int32 Size);
// 7)  Find Duplicate in a array (Code Studio).
int32 Duplicate(ARRAY_TYPE* Arr, int32 Size);
// 8) Find All Duplicates in an Array(LeetCode).
int32* FindDuplicate(int32* Nums, int32 Size, int32* ReturnSize);
// 9)  Intersection of arrays(Code Studio).
void FindArrayInstersection(ARRAY_TYPE* Arr, int32 N, ARRAY_TYPE* Arr2, int32 M );
// 10)  Pair Sum (Code Studio).
void  PairSum(ARRAY_TYPE* Arr, int32 Size, int32 Sum);
// 11)  Triplet Sum(Code Studio).
void TripletSum(ARRAY_TYPE* Arr, int32 Size, int32 Sum);
// 12) Sort 0 and 1.
void Sort0And1(ARRAY_TYPE* Arr, int32 Size);
// 13) Sort 0,1,2(Code Studio).
void Sort012(ARRAY_TYPE* Arr, int32 Size);
//14) Running Sum.
void RunningSum(ARRAY_TYPE* Arr, int32 Size);
//15) Shift Right (Shift every element to right by one position).
void ShiftRight(ARRAY_TYPE* Arr, int32 Size);

#endif

#ifdef ARRAY_IMPLEMENTATION

void PrintArray(ARRAY_TYPE* Arr, int32 Size)
{
    for(int32 Index = 0; Index < Size; ++Index)
    {
        // change format specifer for different types.
        printf("%d ",Arr[Index]);
    }
}

Pair MinMaxArray(int32* Arr, int32 Size)
{
    Pair Result = {0};
    Result.First = INT_MAX;
    Result.Second = INT_MIN;
    for(int32 Index = 0 ; Index < Size; ++Index)
    {
        if(Result.First > Arr[Index])
        {
            Result.First = Arr[Index];
        }
        if(Result.Second < Arr[Index])
        {
            Result.Second = Arr[Index];
        }
    }
    return Result;
}

bool32 LinearSearch(int32* Arr, int32 Size, int32 Key)
{
    for(int32 Index = 0; Index < Size; ++Index)
    {
        if(Key == Arr[Index]) return 1;
    }
    return 0;
}

void ReverseArray(ARRAY_TYPE* Arr, int32 Size)
{
    int32 Start = 0;
    int32 End = Size - 1;
    while(Start < End)
    {
        int32 Swap = Arr[Start];
        Arr[Start] = Arr[End];
        Arr[End] = Swap;
        ++Start;
        --End;
    }
}

void SwapAlternate(ARRAY_TYPE* Arr, int32 Size)
{
    for(int32 Start = 0; Start < Size; Start += 2)
    {
        // Bound Check
        if(Start + 1 < Size){
            int32 Swap = Arr[Start];
            Arr[Start] = Arr[Start + 1];
            Arr[Start + 1] = Swap;
        }
    }
    printf("\n");
}

// ##,##,##,##,##,M## ->N , N = 2m+1,



int32 UniqueElement(ARRAY_TYPE* Arr, int32 Size)
{
    int32 Unique = 0;
    for(int32 Index = 0; Index < Size; Index++){

        Unique = Unique ^ Arr[Index]; // a^b^a = b , 0^a = a,
    }
    return Unique;
}


// Revist this problems once learn't advance data structure.
bool32 UniqueOccurences(int32* Arr, int32 Size)
{
    // pure brute force solution, if you want to effiecnt solution , you can use hashtable with sets.
    // using direct access hash table approach.
    //Time: O(n)
    //Space: O(n)
    int32* buffer = (int32*)malloc(sizeof(int32) * 2001);
    memset(buffer, 0, sizeof(int32) * 2001);

    for(int32 Index = 0; Index < Size; ++Index)
    {
        if(Arr[Index] < 0)
        {
            buffer[abs(Arr[Index])]++;
        }

        if(Arr[Index] > 0)
        {
            buffer[1000 + Arr[Index]]++;
        }

        if(Arr[Index] == 0)
        {
            buffer[0]++;
        }
    }

    // Time: O(n)
    // Space: O(n)
    int32* Counters = (int32*)malloc(sizeof(int32) * 2001);
    int32 j = 0;
    for(int32 i = 0; i < 2001; ++i)
    {
        if(buffer[i] == 0){
            continue;
        }

        if(buffer[i]){
            Counters[j] = buffer[i];
            j++;
        }
    }
    // Time: O(n^2)
    bool32 Unique = 1;
    for(int32 i = 0; i < j; ++i){
        for(int32 k = i+1; k < j; ++k){
            if(Counters[i] == Counters[k]){
                Unique = 0;
            }
        }
    }
    free(buffer);
    free(Counters);
    return Unique;
}

int32 Duplicate(ARRAY_TYPE* Arr, int32 Size)
{
    if(Size == Arr[0] == 0) return 0;
    int32 ArraySum = 0;
    for(int32 Index = 0; Index < Size; ++Index)
    {
        ArraySum += Arr[Index];
    }
    return ArraySum - ((Size * (Size - 1 ))/2);
}

// Revist this problems once learn't advance data structure.
//int32* FindDuplicate(int32* Nums, int32 Size, int*returnSize)
int32* FindDuplicate(int32* Nums, int32 Size, int32* ReturnSize)
{
    // can be optimized using Hashtables.
    int32* Buffer = (int32*)malloc(sizeof(int32) * 100000);
    memset(Buffer, 0, sizeof(int32) * 100000);

    for(int32 Index = 0; Index < Size; ++Index)
    {
        Buffer[Nums[Index]]++;
    }

    int32* NewBuffer = (int32*)malloc(sizeof(int32) * 100000);
    memset(NewBuffer, 0, sizeof(int32) * 100000);
    int j = 0;

    for(int32 i = 0; i < 100000; ++i)
    {
        if(Buffer[i] == 2)
        {
            NewBuffer[j] = i;
            j++;
        }
    }
    printf("[");
    for(int32 i = 0; i < j ; i++)
    {
        if(i<j-1){
            printf("%d,", NewBuffer[i]);
            continue;
        }
        printf("%d", NewBuffer[i]);
    }
    printf("]");
    *ReturnSize = j;
    free(Buffer);
    free(NewBuffer);
    //NotFix: NewBuffer is not working for some reason if retruned from this function and used in PrintArray.
    return NULL;
}

void FindArrayInstersection(ARRAY_TYPE* Arr, int32 N, ARRAY_TYPE* Arr2, int32 M )
{
    int32 Index = 0;
    int32 Index2 = 0;
    bool32 NoIntersection = 1;
    while(Index < N && Index2 < M)
    {
        // make sure if are in this order.
        if(Arr[Index] == Arr2[Index2])
        {
            NoIntersection = 0;
            printf("%d ", Arr[Index]);
            Index++;
            Index2++;
        }
        if(Arr[Index] < Arr2[Index2])Index++;
        if(Arr[Index] > Arr2[Index2]) Index2++;
    }
    if(NoIntersection) printf("-1");
    printf("\n");
}



void  PairSum(ARRAY_TYPE* Arr, int32 Size, int32 Sum)
{
    //TODO:: can i use binary serach to solve this.
    for(int32 First = 0; First < Size; ++First)
    {
        for(int32 Second = 0; Second < Size; ++Second)
        {
            if(Arr[First] + Arr[Second] == Sum && Arr[First] < Arr[Second]){
                printf("{%d, %d}\n", Arr[First], Arr[Second]);
            }
        }
    }

}

void TripletSum(ARRAY_TYPE* Arr, int32 Size, int32 Sum)
{
    for(int32 First = 0; First < Size; ++First)
    {
        for(int32 Second = First + 1; Second < Size; ++Second)
        {
            for(int32 Third = Second + 1; Third < Size; ++Third){
                if(Arr[First] + Arr[Second] + Arr[Third] == Sum ){
                    printf("{%d, %d, %d}\n", Arr[First], Arr[Second], Arr[Third]);

                }
            }
        }
    }
}

void Sort0And1(ARRAY_TYPE* Arr, int32 Size)
{
    int32 Start = 0;
    int32 End = Size - 1;
    while(Start < End)
    {
        while(Arr[Start] == 0 && Start < End) Start++;
        while(Arr[End] == 1 && Start < End) End--;

        if(Arr[Start] == 1 &&  Arr[End] == 0 && Start < End)
        {
            SwapInt32(Arr + Start, Arr + End);
            End--;
            Start++;
        }

    }
}


// Todo: // Do this problem.
void Sort012(ARRAY_TYPE* Arr, int32 Size)
{
}

void RunningSum(ARRAY_TYPE* Arr, int32 Size)
{
    for(int32 Index = 1; Index < Size; ++Index)
    {
        Arr[Index] += Arr[Index - 1];
    }
}

void ShiftRight(ARRAY_TYPE* Arr, int32 Size)
{
    int32 Temp = Arr[0];
    uint32 i = 0;
    for(; i < Size; ++i)
    {
        int32 Temp2 = Arr[i];
        Arr[i] = Temp;
        Temp = Temp2;
    }
    Arr[i % Size] = Temp;
}

#endif
