#include <stdio.h>

#define BIT_ARRAY_SIZE 1
// currently im only using just an unsigned int but it can be used with arrays too.
// too lazy to implement.
// if pos is greter than 32 it will wrap and set first bit.
// i implemented really simple maksing. beacuse i was exploring bit// array still don't get the defination but , i think it is bits
// array and we are like utilizing every  bit in like unsigned int
// for rembering some state .

// not finished yet may be in future.
unsigned int BitArray[BIT_ARRAY_SIZE];

/*
Bytes bits |
4     (32) |
000000000000000000000000000000000
000000000000000000000000000000000
000000000000000000000000000000000
000000000000000000000000000000000
*/

void SetBit(int pos, unsigned int* BitArray)
{
  
    unsigned int Mask = 1 << (pos-1);
    BitArray[0] = BitArray[0] |  Mask;

}

void PrintBits(unsigned int * BitArray)
{
    unsigned int arr[1];
    arr[0] = BitArray[0];
    do
    {
        printf("%d",(arr[0] & 1));
        arr[0] >>=1;
    }while(arr[0] != 0);
    printf("\n");
}

void UnsetBit(int pos, unsigned int* BitArray)
{
    unsigned int Mask = ~(1 << (pos-1));
    BitArray[0] = BitArray[0] & Mask;
}

int main()
{
    BitArray[0] = 0;
    SetBit(3, BitArray);
    SetBit(6, BitArray);
    SetBit(5, BitArray);
    SetBit(7, BitArray);
    SetBit(8, BitArray);
    SetBit(23, BitArray);
    PrintBits(BitArray);
    UnsetBit(5, BitArray);
    UnsetBit(3, BitArray);

    PrintBits(BitArray);
    return 0;
}
