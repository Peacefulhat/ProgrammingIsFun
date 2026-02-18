#ifndef BASIC_H
#define BASIC_H

#include <stdio.h>
#include "../dstype.h"
// Type defination for patterns.
typedef enum
{
    STAR = 0,// Rectangle and Square.
    STAR_LRTRIANGLE,// LeftRightTriangle.
    STAR_RRTRIANGLE,// RightRightTriangle.
    STAR_INVERTED_LRTRIANGLE,// Inverted LeftRightTriangle.
    STAR_INVERTED_RRTRIANGLE,// Inverted RightRightTriangle.
    NUMBER,// Rectangle and Square.
    NUMBER2,
    NUMBER3,
    LETTER,
    LETTER2,
    LETTER3,
    LETTER4,
    NUMBER_LRTRIANGLE,
    NUMBER2_LRTRIANGLE,
    NUMBER3_LRTRIANGLE,
    NUMBER4_LRTRIANGLE,
    NUMBER5_TRIANGLE,
    LETTER_LRTRIANGLE,
    LETTER2_LRTRIANGLE,
    LETTER3_LRTRIANGLE,
    LETTER4_LRTRIANGLE,
    SPECIAL_PATTERN,
    
}PatternKind;

// 1) check if given character is in lower case or uppercase.
void CheckCaseOfLetter(char Ch);
// 2) Sum of natural numbers using loops and without loop.
void SumOfNaturalNumbers(int32 Terms, bool32 IsLoopUsed);
// 3) Sum of Even Numbers;
void SumOfEvenNumbers(int32 Terms);
// 4) Patterns // consider Rows and Cols are Equal.
void Pattern(int32 N, PatternKind Kind);
// 5) fibonacci Series.
void Fib(int32 Terms);
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

void Pattern(int32 N, PatternKind Kind)
{

    switch(Kind)
    {
        case STAR:
            {
                for(int32 Y = 0; Y < N; ++Y)
                {
                    for(int32 X = 0; X < N; ++X)
                    {
                        printf("*");
                    }
                    printf("\n");
                }
            }break;
            
        case STAR_LRTRIANGLE:
            {
                for(int32 Y = 0; Y < N; ++Y)
                {
                    for(int32 X = 0; X <= Y; ++X)
                    {
                        printf("*");
                    }
                    printf("\n");
                    
                }
            } break;
        case STAR_RRTRIANGLE:
            {
                for(int32 Y = 0; Y < N; ++Y)
                {
                    int32 Space = N - (Y+1);
                    for(int32 K = 0; K < Space; K++){printf(" ");}
                    for(int32 X = 0; X <(N - Space); ++X)
                    {
                        printf("*");
                    }

                        printf("\n");
                }

            } break;
        case STAR_INVERTED_LRTRIANGLE:
            {
                int32 Cols = N;
                for(int32 Y = 0; Y < N; ++Y)
                {
                    for(int32 X = Cols; X >0; --X)
                    {
                        printf("*");
                    }
                    --Cols;
                    printf("\n");
                }
            } break;
        case STAR_INVERTED_RRTRIANGLE:
            {
                int32 Cols = N;
                for(int32 Y = 0; Y < N; ++Y)
                {
                    int32 Space = Y;
                    for(int32 K = 0; K < Space; ++K){printf(" ");}
                    for(int32 X = (N-Y); X >0; --X)
                    {
                        printf("*");
                    }
                    printf("\n");
                }
            } break;
        case NUMBER:
            {
                for(int32 Y = 0; Y < N; ++Y)
                {
                    for(int32 X = 0; X < N; ++X)
                    {
                        printf("%d", Y);
                    }
                    printf("\n");
                }
            } break;
        case NUMBER2:
            {
                for(int32 Y = 0; Y < N; ++Y)
                {
                    for(int32 X = 0; X < N; ++X)
                    {
                        printf("%d", X);
                    }
                    printf("\n");
                }

            } break;
        case NUMBER3:
            {
                int32 Count = 0;
                for(int32 Y = 0; Y < N; ++Y)
                {
                    for(int32 X = 0; X < N; ++X)
                    {
                        printf("%d", Count);
                        ++Count;
                    }
                    printf("\n");
                }

            } break;
        case LETTER:
            {
                schar Letter = 65;
                for(int32 Y = 0; Y < N; ++Y)
                {
                    for(int32 X = 0; X < N; ++X)
                    {
                        printf("%c", Letter);
                    }
                    ++Letter;
                    printf("\n");
                }
                
            } break;
        case LETTER2:
            {
                for(int32 Y = 0; Y < N; ++Y)
                {
                    schar Letter = 65;
                    for(int32 X = 0; X < N; ++X)
                    {
                        printf("%c", Letter);
                        ++Letter;
                    }
                    printf("\n");
                }

            } break;
        case LETTER3:
            {
                schar Letter = 65;
                for(int32 Y = 0; Y < N; ++Y)
                {
                    for(int32 X = 0; X < N; ++X)
                    {
                        printf("%c", Letter);
                        ++Letter;
                    }
                    printf("\n");
                }
            } break;
            
        case LETTER4:
            {
                schar Letter = 65;
                for(int32 Y = 0; Y < N; ++Y)
                {
                    schar Letter2 = Letter;
                    for(int32 X = 0; X < N; ++X)
                    {
                        printf("%c", Letter2);
                        ++Letter2;
                    }
                    ++Letter;
                    printf("\n");
                }

            } break;
        case NUMBER_LRTRIANGLE:
            {
                for(int32 Y = 0; Y < N; ++Y)
                {
                    for(int32 X = 0; X <= Y; ++X)
                    {
                        printf("%d", Y);
                    }
                    printf("\n");
                }
            } break;
        case NUMBER2_LRTRIANGLE:
            {
                int32 Count = 0;
                for(int32 Y = 0; Y < N; ++Y)
                {
                    for(int32 X = 0; X <= Y; ++X)
                    {
                        printf("%d", Count);
                        ++Count;
                    }
                    printf("\n");
                }
            } break;
        case NUMBER3_LRTRIANGLE:
            {

                for(int32 Y = 0; Y < N; ++Y)
                {
                    int32 Count = Y;
                    for(int32 X = 0; X <= Y; ++X)
                    {
                        printf("%d", Count);
                        ++Count;
                    }
                    printf("\n");
                }
                
            } break;
        case NUMBER4_LRTRIANGLE:
            {
                for(int32 Y = 0; Y < N; ++Y)
                {
                    int32 Count = Y;
                    for(int32 X = Count; X >=0; --X)
                    {
                        printf("%d", X);

                    }
                    printf("\n");
                }
            } break;
        case NUMBER5_TRIANGLE:
            {
                for(int32 Y = 1; Y <= N; ++Y){
                    int Space = N - Y;
                    for(int32 K = 0; K < Space; ++K){printf(" ");}
                    for(int32 X = 1; X <= Y; ++X){
                        printf("%d", X);
                    }
                   for(int32 Z = 1; Z <= Y; ++Z){
                        if(Y > 1){
                            int32 A = (Y-1)+((Z - 1)*(-1));
                            if(A)
                            {
                                printf("%d", A);
                            }
                        }

                    }
                    printf("\n");
                } 
            }break;
            
        case LETTER_LRTRIANGLE:
            {
                schar Letter = 65;
                for(int32 Y = 0; Y < N; ++Y)
                {
                    for(int32 X = 0; X <= Y; ++X)
                    {
                        printf("%c", Letter);
                    }
                    ++Letter;
                    printf("\n");
                }
            } break;
        case LETTER2_LRTRIANGLE:
            {
                schar Letter = 65;
                for(int32 Y = 0; Y < N; ++Y)
                {
                    for(int32 X = 0; X <= Y; ++X)
                    {
                        printf("%c", Letter);
                        ++Letter;
                    }
                    printf("\n");
                }
            } break;
        case LETTER3_LRTRIANGLE:
            {
                schar Letter = 65;
                for(int32 Y = 0; Y < N; ++Y)
                {  schar Letter2 = Letter;
                for(int32 X = 0; X <= Y; ++X)
                {
                    printf("%c", Letter2);
                    ++Letter2;
                }
                ++Letter;
                printf("\n");
            }
        } break;
    case LETTER4_LRTRIANGLE:
        {
            schar Letter = 65 + N - 1;
            for(int32 Y = 0; Y < N; ++Y)
            {  schar Letter2 = Letter;
            for(int32 X = 0; X <= Y; ++X)
            {
                printf("%c", Letter2);
                ++Letter2;
            }
            --Letter;
            printf("\n");
        }
    } break;
    
case SPECIAL_PATTERN:
    {
        for(int32 Y = 1; Y <= N; ++Y){
            int32 X = 1;
            for(; X <= N; ++X){
                
                if(X >= (N - Y + 2))
                {
                    printf("*"); 
                }
                else
                {
                    printf("%d", X);
                }
            }

            for(int32 Z = N; Z >= 1; --Z){
                
                if(Z >= (N - Y + 2))
                {
                    printf("*");
                }
                else
                {
                    printf("%d", Z);
                } 
            }
            printf("\n");
        }
    }break;
    
default:
    {
        printf("Not a correct kind for pattern");
    }
}

}
void Fib(int32 Terms)
{
    int32 First = 0;
    int32 Second = 1;
    printf("Fibonacci Series:: %d %d ", First, Second);
    for(int Term = 0; Term < Terms - 2; Term++) // we have to print 2 less terms.
    {
        int32 Third = First + Second;
        printf("%d ", Third);
        First = Second;
        Second = Third;
    }
    printf("\n");
}

#endif
