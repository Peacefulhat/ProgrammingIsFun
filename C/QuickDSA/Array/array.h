#ifndef ARRAY_H
#define ARRAY_H
#include "../dstype.h"

#define ARRAY_TYPE int32
typedef struct {
    int32 First;
    int32 Second;
}Pair;

// 1)  Min and Maximum value in an array.
Pair MinMaxArray(ARRAY_TYPE* arr, int32 Size);
// 2)  Linear Search.
bool32 LinearSearch(ARRAY_TYPE* arr, int32 Size, int32 Key);
// 3)  Reverse an array.
void ReverseArray(ARRAY_TYPE* arr, int32 Size);
// 4)  Swap alternate.
void SwapAlternate(ARRAY_TYPE* arr, int32 Size);
// 5)  Find Unique Element (Code Studio).
int32 UniqueElement(ARRAY_TYPE* arr, int32 Size);
// 6) Unique Number of Occurences(LeetCode).
bool32 UniqueOccurences(ARRAY_TYPE* arr, int32 Size);
// 7)  Find Duplicate in a array (Code Studio).
int32 Duplicate(ARRAY_TYPE* arr, int32 Size);
// 8) Find All Duplicates in an Array(LeetCode).
int32* FindDuplicate(int32* Nums, int32 Size, int32* ReturnSize);
// 9)  Intersection of arrays(Code Studio). 
void FindArrayInstersection(ARRAY_TYPE* arr, int32 N, ARRAY_TYPE* arr2, int32 M );
// 10)  Pair Sum (Code Studio).
void  PairSum(ARRAY_TYPE* arr, int32 Size, int32 Sum);
// 11)  Triplet Sum(Code Studio).
void TripletSum(ARRAY_TYPE* arr, int32 Size, int32 Sum);
// 12) Sort 0 and 1.
void Sort0And1(ARRAY_TYPE* arr, int32 Size);
// 13) Sort 0,1,2(Code Studio).
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
    Result.First = INT_MAX;
    Result.Second = INT_MIN;
    for(int32 Index = 0 ; Index < Size; ++Index)
    {
        if(Result.First > arr[Index])
        {
            Result.First = arr[Index];
        }
        if(Result.Second < arr[Index])
        {
            Result.Second = arr[Index];
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


// Revist this problems once learn't advance data structure.
bool32 UniqueOccurences(int32* arr, int32 Size)
{
    // pure brute force solution, if you want to effiecnt solution , you can use hashtable with sets.
    // using direct access hash table approach.
    //Time: O(n)
    //Space: O(n)
int32* buffer = (int32*)malloc(sizeof(int32) * 2001);
memset(buffer, 0, sizeof(int32) * 2001);

for(int32 Index = 0; Index < Size; ++Index)
{
    if(arr[Index] < 0)
    {
        buffer[abs(arr[Index])]++;
    }
    
    if(arr[Index] > 0)
    {
        buffer[1000 + arr[Index]]++;
    }
    if(arr[Index] == 0)
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

int32 Duplicate(ARRAY_TYPE* arr, int32 Size)
{
    if(Size == arr[0] == 0) return 0;
    int32 ArraySum = 0;
    for(int32 Index = 0; Index < Size; ++Index)
    {
        ArraySum += arr[Index];
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

void FindArrayInstersection(ARRAY_TYPE* arr, int32 N, ARRAY_TYPE* arr2, int32 M )
{
    int32 Index = 0;
    int32 Index2 = 0;
    bool32 NoIntersection = 1;
    while(Index < N && Index2 < M)
    {
        // make sure if are in this order.
       
        if(arr[Index]==arr2[Index2])
        {
            NoIntersection = 0;
            printf("%d ", arr[Index]);
            Index++;
            Index2++;
        }
           if(arr[Index] < arr2[Index2])Index++;
           if(arr[Index] > arr2[Index2]) Index2++;
    }
    if(NoIntersection) printf("-1");
    printf("\n");
}



void  PairSum(ARRAY_TYPE* arr, int32 Size, int32 Sum)
{
    //TODO:: can i use binary serach to solve this.
    for(int32 First = 0; First < Size; ++First)
    {
        for(int32 Second = 0; Second < Size; ++Second)
        {
            if(arr[First] + arr[Second] == Sum && arr[First] < arr[Second]){
                printf("{%d, %d}\n", arr[First], arr[Second]);
                
            }
        }
    }
    
}

void TripletSum(ARRAY_TYPE* arr, int32 Size, int32 Sum)
{
    for(int32 First = 0; First < Size; ++First)
    {
        for(int32 Second = First + 1; Second < Size; ++Second)
        {
            for(int32 Third = Second + 1; Third < Size; ++Third){
                if(arr[First] + arr[Second] + arr[Third] == Sum ){
                    printf("{%d, %d, %d}\n", arr[First], arr[Second], arr[Third]);
                    
                }
            }
        }
    }
}

void Sort0And1(ARRAY_TYPE* arr, int32 Size)
{
    int32 Start = 0;
    int32 End = Size - 1;
    while(Start < End)
    {
        while(arr[Start] == 0 && Start < End) Start++;
        while(arr[End] == 1 && Start < End) End--;

        if(arr[Start] == 1 &&  arr[End] == 0 && Start < End)
        {
            SwapInt32(arr + Start, arr + End);
            End--;
            Start++;
        }

    }
}


// Todo: // Do this problem.
void sort012(ARRAY_TYPE* arr, int32 Size)
{
    
}

#endif
