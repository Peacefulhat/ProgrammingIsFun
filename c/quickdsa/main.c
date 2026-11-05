#define ARRAY_IMPLEMENTATION
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "Array/array.h"

int main()
{
    ARRAY_TYPE MyArr[7]= {0, 1, 2, 0, 1, 2, 0};
    PrintArray(MyArr, 7);
    return (0);
}
