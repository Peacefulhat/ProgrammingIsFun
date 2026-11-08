#define ARRAY_IMPLEMENTATION
#include "../../libds/common.h"
#include "../array.h"


int main()
{
    // Pair Sum
    {
        printf("Pair Sum:\n");
        ARRAY_TYPE MyArr[7]= {1, 5, 3, 4, 5, 6, 7};
        PairSum(MyArr, 7, 10);
        printf("\n");
    }

    // Triplet Sum
    {
        printf("Triplet Sum:\n");
        ARRAY_TYPE MyArr[7]= {1, 2, 3, 4, 5, 6, 7};
        TripletSum(MyArr, 7, 11);
        printf("\n");
    }

    // Remove Duplicate Element from sorted array
    {
        printf("Remove Duplicate:\n");
        ARRAY_TYPE MyArr[8] = {1, 3,3, 5, 5, 6, 7, 8};
        int32 Length = RemoveDuplicates(MyArr, 8 );
        printf("Length: %d\n", Length);
        printf("Updated Array:\n");
        PrintArray(MyArr, Length);
        printf("\n");
    }

    // First Repeating Element in an array
    {
        printf("First Repeating Element:\n");
        ARRAY_TYPE MyArr[7] = {2, 4, 8, 6, 7, 6, 8};
        int32 Element = FristRepeatingElement(MyArr, 7);
        printf("Index: %d, Value: %d\n\n", Element, MyArr[Element]);

    }

    // Find Pivot Index (index at which right part sum and left part sum are equal)
    
    {
        printf("First Pivot Index:\n");
        ARRAY_TYPE MyArr[15] = {13, 17, 20, -3, 7, 13, -18, -7, 12, -13, 5, 9, 17, -4, 19};
        int32 Element = PivotIndex(MyArr, 15);
        printf("Index: %d, Value: %d\n", Element, MyArr[Element]);

    }

}
