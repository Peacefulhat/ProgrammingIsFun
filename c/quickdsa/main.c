#define ARRAY_IMPLEMENTATION
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "Array/array.h"

int main()
{
    ARRAY_TYPE MyArr[7]= {1,2,3,4,5, 6, 7};
    ARRAY_TYPE MyArr2[7]= {1,2,3,4,5, 6, 7};
    FindArrayInstersection(MyArr, 7, MyArr2, 7);
    return (0);
}
