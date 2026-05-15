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
    STAR_SLANTED_RECTANGLE,
    INVERTED_SOLID_PYRAMID,
    DIAMOND,
    HOLLOW_DIAMOND,
    HOLLOW_SQUARE,
    HOLLOW_RIGHTTRIANGLE,
    HOLLOW_PYRAMID,
    HPATTERN
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
// 6) Prime number.
bool32 IsPrime(int32 N);
// 7) Subtract the Product and Sum of Digits of an Integer(LeetCode).
int32 ProductSumDifference(int32 N);
// 8) Number of 1 Bits (LeetCode).
int32 OneBitCount(uint32 N);
// 9) Decimal to Binary.(-ve Numbers are include.)
int32 DecimalToBinary(int32 N, bool32 IsNegative);
// 10) Reverse Integer (LeetCode).
int32 ReverseInteger(int32 N);
// 11) Complement of Base 10 Integer(LeetCode).
int32 ComplementOfInteger(int32 N);
//12) Power of Two(LeetCode).
bool32 IsPowerOfTwo(int32 N, int32 S);
//13) How many notes can we get if we have 100,50,20,1
void Notes(int32 Amount);
//14 Find nth term from AP 3*n + 7
int32 NthTerm(int N);
//15 Find total setbits in a & b.
int32 TotalSetBits(int32 A, int32 B);

#endif

#ifdef BASIC_IMPLEMENTATION

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
            for(int32 Y = 1; Y <= N; ++Y)
            {
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

        case STAR_SLANTED_RECTANGLE:
        {
            for(uint32 Y =  0; Y < N; ++Y)
            {
                for (uint32 Space = 0; Space < N - (Y + 1); ++Space)
                {
                    printf(" ");
                }
                for(uint32 X = 0; X < N; ++X)
                {
                    printf("* ");
                }
                printf("\n");
            }

        }break;


        case INVERTED_SOLID_PYRAMID:
        {
            uint32 FirstTerm = (1 + (N - 1) * 2);
            for (int32 Y = 0; Y < N; ++Y)
            {
                for(int32 Space = 0; Space < Y; ++Space)
                {
                    printf("  ");
                }

                uint32 Stars = (FirstTerm + (Y * -2)); // Ap
                for(int32 X = 0; X < Stars; ++X)
                {
                    printf("* ");
                }
                printf("\n");
            }

        }break;

        case DIAMOND:
        {
            // Upper Pyramid
            uint32 FirstTerm = 1;
            for (int32 Y = 0; Y < N; ++Y)
            {
                for (int32 X = 0; X < N - (Y + 1); ++X)
                {
                    printf("  ");
                }
                uint32 Stars = (FirstTerm + (Y * 2)); // Ap
                for (int32 Z = 0; Z < Stars; ++Z)
                {
                    printf("* ");
                }
                printf("\n");
            }

            // Lower Pyramid
            uint32 FFirstTerm = (1 + (N - 2) * 2);
            for(int32 Y = 0; Y < N - 1; ++Y)
            {
                for (int32 Space = 0; Space < Y + 1; ++Space)
                {
                    printf("  ");
                }

                uint32 SStars = FFirstTerm +( Y * -2); // Ap

                for(int32 X = 0; X < SStars; ++X)
                {
                    printf("* ");
                }
                printf("\n");
            }

        }break;

        case HOLLOW_SQUARE:
        {

            for (int32 Y = 0; Y< N; ++Y){
                uint32 Space;
                if (Y == 0 || Y == N - 1){
                    Space = 0;
                }
                else{
                    Space = N - 2;
                }
                for (int32 X = 0; X < N - Space; ++X){

                    if( Y == 0 || Y == N - 1)
                    {
                        printf("* ");
                        continue;
                    }

                    printf("* ");

                    if(Y >= 1)
                    {
                        for (int32 Z = 0; Z < Space; ++Z)
                        {
                            printf("  ");
                        }
                    }
                }
                printf("\n");
            }

        }break;

        case HOLLOW_RIGHTTRIANGLE:
        {

            int32 SpaceStart = 2;
            for (int32 Y = 0; Y < N; ++Y)
            {
                for (int32 X = 0; X< Y + 1; ++X)
                {
                    if(X == 0 || X == Y|| Y == N - 1)
                    {
                        printf("*");
                    }
                    else if (Y >= SpaceStart)
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }


        }break;


        case HOLLOW_PYRAMID:
        {

            uint32 FirstTerm = 1;
            for (int32 Y = 0; Y < N; ++Y)
            {
                for(int32 Space = 0; Space < (N - (Y + 1)); ++Space)
                {
                    printf("  ");
                }
                uint32 StarsWithSpace = (FirstTerm + (Y * 2)); // Ap
                for(int32 X = 0; X < StarsWithSpace; ++X)
                {
                    if(X == 0  || Y == N - 1 || X == StarsWithSpace - 1)
                    {
                        printf("* ");
                    }
                    else
                    {
                        printf("  ");
                    }
                }
                printf("\n");
            }
        }break;

        case HOLLOW_DIAMOND:
        {

            uint32 FirstTerm =  1;
            for(int32 Y = 0; Y< N; ++Y)
            {
                for(int32 Space = 0; Space < (N - (Y + 1)); ++Space)
                {
                    printf("  ");
                }
                uint32 StarsWithSpace = (FirstTerm + (Y * 2)); // Ap
                for (int32 X = 0; X< StarsWithSpace; ++X)
                {
                    if(X == 0 || X == StarsWithSpace - 1)
                    {
                        printf("* ");
                    }
                    else
                    {
                        printf("  ");
                    }
                }
                printf("\n");
            }

            uint32 IFirstTerm = (1 + (N - 2) * 2);
            for (int32 Y = 0; Y < N - 1; ++Y)
            {
                for(int32 Space = 0; Space < Y + 1; ++Space)
                {
                    printf("  ");
                }

                uint32 StarsWithSpace = IFirstTerm + (Y * -2); // Ap

                for (int32 X = 0; X< StarsWithSpace; ++X)
                {
                    if( X == 0 || X == StarsWithSpace - 1)
                    {
                        printf("* ");
                    }
                    else
                    {
                        printf("  ");
                    }
                }
                printf("\n");
            }

        }break;

        case HPATTERN:
        {

            for(int32 Y = 0; Y < N; ++Y)
            {
                for(int32 X = 0; X < Y + 1; ++X)
                {
                    printf("* ");
                }

                for(int32 Z = 0; Z < 2*(N - Y - 1); ++Z)
                {
                    printf("  ");
                }

                for(int32 X = 0; X < Y + 1; ++X)
                {
                    printf("* ");
                }

                printf("\n");
            }

            for(uint32 Y = N - 1; Y > 0; --Y)
            {
                for (uint32 X = Y; X > 0; --X)
                {
                    printf("* ");
                }

                for( int32 Z = 0;  Z < 2*(N - Y); ++Z)
                {
                    printf("  ");
                }
                for (uint32 X = Y; X > 0; --X)
                {
                    printf("* ");
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

bool32 IsPrime(int32 N)
{
    bool32 Prime = 1;
    for(int32 Divisor = 2; Divisor < N; Divisor++)
    {
        if(N % Divisor == 0)
        {
            Prime = 0;
            break;
        }
    }
    return Prime;
}

int32 DigitProductSumDifference(int32 N)
{
    int32 DigitSum = 0;
    int32 DigitProduct = 1;
    while(N != 0)
    {
        DigitProduct *= N%10;
        DigitSum += N%10;
        N /= 10;
    }
    return DigitProduct - DigitSum;
}

int32 OneBitCount(uint32 N)
{
    int32 Count = 0;
    while(N != 0)
    {
        if(N & 1) Count++;
        N >>= 1;
    }
    return Count;
}


int32 DecimalToBinary(int32 N, bool32 IsNegative)
{
    //TODO:: Implement things for negative numbers.
    int32 Binary = 0;
    int32 i = 0;
    while(N != 0)
    {
        Binary += ((N & 1) * pow(10,i));
        N >>= 1;
        i++;
    }
    return Binary;
}

int32 ReverseInteger(int32 N)
{
    int32 Reverse = 0;
    while(N !=0 )
    {
        /* Edge case::its like we are checking if in next iteration the number is going to exceed the range of integer.*/
        if(Reverse  > INT_MAX/10 || Reverse < INT_MIN/10)
        {
            return 0;
        }
        Reverse = (Reverse*10) + (N % 10);
        N /= 10;
    }
    return Reverse;

}

int32 ComplementOfInteger(int32 N)
{
    if(N == 0 ) return 1;
    int32 Mask = 0;
    int32 Temp = N;
    while(N != 0)
    {
        Mask = (Mask << 1) | 1;
        N >>= 1;
    }
    return ((~Temp) & Mask);
}

bool32 IsPowerOfTwo(int32 N, int32 S)
{
    // 1
    switch(S){
        case 0:
        {
            if(N < 1) return 0;
            return ((N & (N-1)) == 0);
        }break;
        //2
        case 1:
        {
            int32 BitCount = 0;
            while(N != 0)
            {
                if(N & 1) ++BitCount;
                N >>=1;
            }
            return BitCount == 1;
        }break;
        default : return 0;
    }
}

void Notes(int Amount)
{
    int K = 0;
    int32 TotalNotes = 0;
    int32 NoteDivisor = 100;
    while(Amount){
        switch(NoteDivisor){
            case 100:
            {
                K = Amount / 100;
                Amount = Amount - (K * 100);
                TotalNotes += K;
                printf("Note of Hundreds:: %d\n", K);
                NoteDivisor = 50;
            } break;
            case 50:
            {
                K= Amount / 50;
                Amount = Amount - (K * 50);
                TotalNotes += K;
                printf("Note of Fifty:: %d\n", K);
                NoteDivisor = 20;
            }  break;
            case 20:
            {
                K= Amount / 20;
                Amount = Amount - (K * 20);
                TotalNotes += K;
                printf("Note of Twenty:: %d\n", K);
                NoteDivisor = 1;
            }  break;
            case 1:
            {
                K = Amount / 1;
                Amount = Amount - (K * 1);
                TotalNotes += K;
                printf("Note of Ones:: %d\n", K);
                NoteDivisor = 0;
            }break;
            case 0:
            {
                Amount = 0;
            }
        }
    }
    printf("Total Number of Notes:: %d\n", TotalNotes);
}


int32 NthTerm(int N)
{
    return ((3 * N) + 7);
}

int32 TotalSetBits(int32 A, int32 B)
{
    int32 TotalBits = OneBitCount((int32)A) + OneBitCount((int32)B);
    return TotalBits;
}


#endif
