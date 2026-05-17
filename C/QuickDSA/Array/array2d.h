#ifndef ARRAY2D_H
#define ARRAY2D_H

#include "../dstype.h"
#define ARRAY_TYPE int32

void RowSum(ARRAY_TYPE* Arr, int32 Rows, int32 Cols);
void ColSum(ARRAY_TYPE* Arr, int32 Rows, int32 Cols);
void WaveForm(ARRAY_TYPE* Arr, int32 Rows, int32 Cols);
#endif

#ifdef ARRAY2D_IMPLEMENTATION

void RowSum(ARRAY_TYPE* Arr, int32 Rows, int32 Cols)
{
    printf("[ ");
    for(int32 Y = 0; Y < Rows; ++Y)
    {
        int32 RowSum = 0;
        for(int32 X = 0; X < Cols; ++X)
        {
            RowSum += Arr[Y * Cols + X];
        }
        printf("%d ",RowSum);
        RowSum = 0;
    }
    printf("]\n");

}

void ColSum(ARRAY_TYPE* Arr, int32 Rows, int32 Cols)
{
    printf("[ ");
    for(int32 Y = 0; Y < Rows; ++Y)
    {
        int32 ColSum = 0;
        for(int32 X = 0; X < Cols; ++X)
        {
            ColSum += Arr[X * Cols + Y];
        }
        printf("%d ",ColSum);
        ColSum = 0;
    }
    printf("]\n");

}

void WaveForm(ARRAY_TYPE* Arr, int32 Rows, int32 Cols)
{
    for(int32 Y = 0; Y < Cols; ++Y)
    {
        printf("[ ");
        if( Y % 2 == 0){
            for(int32 X = 0; X < Rows; ++X)
            {
                printf("%d ", Arr[X * Cols + Y]);
            }
        }
        else
        {
            for(int32 X = Rows - 1; X >=0; --X)
            {
                printf("%d ", Arr[X * Cols + Y]);
            }

        }
        printf("]\n");
    }
}
#endif