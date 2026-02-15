#ifndef BASIC_H
#define BASIC_H

#include <stdio.h>
#include "../dstype.h"

// 1) check if given character is in lower case or uppercase.
void CheckCaseOfLetter(char Ch);
// 2) Sum of natural numbers using loops and without loop.
void SumOfNaturalNumbers(int32 Terms, bool32 IsLoopUsed);
//3) Sum of Even Numbers;
void SumOfEvenNumbers(int32 Terms);
//4) Square Star Pattern
void SquareStar(int32 Row, int32 Cols);

#endif

#ifdef BASIC_IMPLEMENTAION

void CheckCaseOfLetter(char Ch)
{
    if(Ch >= 'a' && Ch <= 'z')
    {
        printf("This is LowerCase\n");
        return;
    }
    
    if(Ch >= 'A' && Ch <= 'Z')
    {
        printf("This is UpperCase\n");
        return;
    }
    printf("This is not a Letter\n");
}

void SumOfNaturalNumbers(int32 Terms, bool32 IsLoopUsed)
{
    #define NSum(Terms) ((Terms) * (Terms + 1)) / 2
    if(IsLoopUsed)
    {
        printf("Sum of Natural Numbers: %d\n", NSum(Terms));
        return;
    }
    int32 Sum = 0;
    for(int32 i = 1; i <= Terms; ++i)
    {
        Sum +=i;
    }
    printf("Sum of Natural Numbers: %d\n", Sum);
}

void SumOfEvenNumbers(int32 Terms)
{
    int32 SumOfEvens = 0;
    for(int32 i = 2; Terms >= 0 && Terms--; i += 2)
    {
        SumOfEvens += i;
    }
    printf("Sum of Even Numbers: %d\n", SumOfEvens);
}

void SquareStar(int32 Rows, int32 Cols)
{
    for(int Y = 0; Y < Rows; ++Y)
    {
        for(int X = 0; X < Cols; ++X)
        {
            printf("*");
        }
        printf("\n");
    }
}

#endif
