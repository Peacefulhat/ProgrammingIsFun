#include "dstype.h"

void SwapInt32(int32* A , int32* B)
{
    int32 Temp = *A;
    *A  = *B;
    *B = Temp;
}
