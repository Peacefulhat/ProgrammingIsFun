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
    // 90 degree rotated think of this matrix as as cube or a square (in geometry)
    /*
        7 8 9
        4 5 6
        1 2 3
    */
    PrintArray2D((int32*)arr, 3, 3);
    int32 A = 23;
    int32  B = 929;
    printf("A: %d, B: %d\n", A, B);
    SwapInt32(&A, &B);
    printf("A: %d, B: %d\n", A, B);
    return 0;
}
