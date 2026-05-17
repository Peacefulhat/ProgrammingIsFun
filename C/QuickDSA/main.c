#define ARRAY2D_IMPLEMENTATION
#include "Array/array2d.h"


int main()
{
    int32 arr[3][3] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    WaveForm((int32*)arr, 3, 3);
    return 0;
}
