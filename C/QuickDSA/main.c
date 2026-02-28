#define ARRAY_IMPLEMENTATION 
#include "Array/array.h"

int main(int argc, char** argv)
{
    int32 arr[7] = {1, 2, 3, 4, 5, 6, 7};
    ReverseArray(arr, 7);
    PrintArray(arr, 7);
    return 0;
}
