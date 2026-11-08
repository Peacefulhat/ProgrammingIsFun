#define ARRAY_IMPLEMENTATION
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "Array/array.h"

int main()
{
    printf("First Pivot Index:\n");
    ARRAY_TYPE MyArr[15] = {13, 17, 20, -3, 7, 13, -18, -7, 12, -13, 5, 9, 17, -4, 19};
    int32 Element = PivotIndex(MyArr, 15);
    printf("Index: %d, Value: %d\n", Element, MyArr[Element]);

    return (0);
}
