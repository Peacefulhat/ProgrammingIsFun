#define ARRAY2D_IMPLEMENTATION
#include "Array/array2d.h"
#include "Basic/basic.h"


int main()
{
    int32 arr[3][3] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    // 90 degree rotated think of this matrix as as cube or a square (in geometry)
    /*
        7 8 9
        4 5 6
        1 2 3
    */
    PrintArray2D((int32*)arr, 3, 3);
    return 0;
}
