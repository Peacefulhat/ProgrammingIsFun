// Resource: https://en.wikipedia.org/wiki/NaN
// Tsoding Daily: Virtal Machine in C EP 2 : NaN - Boxing.
// This was implemented using the video, i don't own anything.
// I am just learning why its useful and how its implemented.
// Scuffed Reflection.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

void print_bits(uint8_t* Bytes, size_t BytesSize)
{
    for(int Y = BytesSize - 1; Y >= 0; --Y) {
        uint8_t Byte = Bytes[Y];
        for(int  X = 7; X >= 0; --X ) {
            printf("%d", !!(Byte & (1 << X)));

        }
        printf(" ");
    }
    printf("\n");
}


#define INSPECT_VALUE(Type, Value, Lable)            \
{                                                    \
    Type Name = (Type)(Value);                       \
    printf("%s: \n\t", Lable);                       \
    print_bits((uint8_t*)&Name, sizeof(Name));       \
    printf("    is nan = %d\n", IsNaN(Name));        \
}                                                    \


#define EXP_MASK (((1LL << 11LL) - 1) << 52LL) // -1 for that one bit (think to know).
#define FRACTION_MASK ((1LL << 52LL) - 1L)
#define SIGN_MASK (1LL << 63LL)
#define TYPE_MASK (((1LL << 4LL) - 1LL) <<48LL)
#define VALUE_MASK  ((1LL << 48LL) - 1LL)
#define TYPE(N) ((1LL << 3LL) + N)

double MakeInf(void)
{
    uint64_t Result = EXP_MASK;
    return *(double*)&Result;
}

double SetType(double X, uint64_t Type)
{
    uint64_t Cast = *(uint64_t*)&X;
    Cast = (Cast & (~TYPE_MASK))| (((TYPE_MASK >> 48LL) & Type ) << 48LL);
    return *(double*)&Cast;
}

double SetValue(double X, uint64_t Value)
{
    uint64_t Cast = *(uint64_t*)&X;
    Cast = (Cast & (~VALUE_MASK))|(Value & VALUE_MASK);
    return *(double*)&Cast;

}

uint64_t GetType(double X)
{
    uint64_t Cast = (*(uint64_t*)&X);
    return (Cast & TYPE_MASK) >> 48LL;
}

uint64_t GetValue(double X)
{
    uint64_t Cast = (*(uint64_t*)&X);
    return (Cast & VALUE_MASK);

}

int IsNaN(double X)
{
    uint64_t Cast = (*(uint64_t*)&X) ;
    return ((Cast & EXP_MASK) == EXP_MASK) && (Cast & FRACTION_MASK) != 0;
}

#define DOUBLE_TYPE  0
#define INTEGER_TYPE 1
#define POINTER_TYPE 2

int IsDouble(double X)
{
    return !IsNaN(X);
}

int IsInteger(double X)
{
    return IsNaN(X) && GetType(X) == TYPE(INTEGER_TYPE);
}

int IsPointer(double X)
{
    return IsNaN(X) && GetType(X) == TYPE(POINTER_TYPE);
}

double AsDouble(double X)
{
    return(X);
}

uint64_t AsInteger(double X)
{
    return(GetValue(X));
}

void* AsPointer(double X)
{
    return (void*)(GetValue(X));
}

double BoxDouble(double X)
{
    return (X);
}

double BoxInteger(double X)
{
    return (SetValue(SetType(MakeInf(), TYPE(INTEGER_TYPE)), X));
}

double BoxPointer(void* X)
{
    return (SetValue(SetType(MakeInf(), TYPE(POINTER_TYPE)), (uint64_t)X));
}

#define VALUES_CAPACITY 256
double Values[VALUES_CAPACITY];
int  ValueSize = 0;

int IsInf(double X)
{
    uint64_t Cast = (*(uint64_t*)&X) ;
    return ((Cast & EXP_MASK) == EXP_MASK) &&
           ((Cast & FRACTION_MASK) == 0) &&
           ((Cast & SIGN_MASK) == 0);
}


int main2(void)
{
    double Pi = 3.14159265359;
    assert(Pi         ==  AsDouble(BoxDouble(Pi)));
    assert(12345678LL ==  AsInteger(BoxInteger(12345678LL)));
    assert(&Pi        ==  AsPointer(BoxPointer(&Pi)));
    printf("OK\n");
    return (0);
}

int main(void)
{
    //INSPECT_VALUE(double,  3.14159265359, "3.14159265359");
    //INSPECT_VALUE(double,  nan("0"), "nan(0)");
    //INSPECT_VALUE(double,  nan("1"), "nan(1)");
    //INSPECT_VALUE(double,  nan("2"), "nan(2)");
    /*
    for(int i = 0; i < ValueSize; ++i)
    {
    printf("{\n");
    printf("\t%d: is double  == %d\n", i, IsDouble(Values[i]));
    printf("\t%d: is integer == %d\n", i, IsInteger(Values[i]));
    printf("\t%d: is pointer == %d\n", i, IsPointer(Values[i]));
    printf("}\n");
    }
    */

    for(uint64_t i = 0; i < 8; ++i) {
        INSPECT_VALUE(double, SetValue(SetType(MakeInf(), TYPE(i)), 1234567LL), "0");
    }

    return (0);
}
