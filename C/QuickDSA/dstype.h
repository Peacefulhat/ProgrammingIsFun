#ifndef DSTYPE_H
#define DSTYPE_H

#include <stdint.h>
#include <math.h>
typedef int8_t  int8;
typedef int16_t int16; 
typedef int32_t int32;
typedef int32_t bool32;
typedef int8_t   schar;
typedef uint8_t  uchar;
typedef uint8_t  uint8;
typedef uint16_t uint16;  
typedef uint32_t uint32;
typedef float  real32; 
typedef double real64;

#define INT_MIN -2147483648
#define INT_MAX  2147483647

void SwapInt32(int* A , int* B)
{
    int32 Temp = *A;
    *A = *B;
    *B = Temp;
}


#endif
