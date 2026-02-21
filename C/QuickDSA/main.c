#define ARRAY_IMPLEMENTATION 
#include "Array/array.h"

int main(int argc, char** argv)
{
    
    int32 arr[4] = {2,3,4,5};
    int32 arr2[4]= {2,3,3,5};
    FindArrayInstersection(arr, 4, arr2, 4);
    return 0;
}
