package main;

import "core:fmt"

FirstUnsortedElem:: proc(Arr: []i32) ->(i32, bool)
{
    IsFound := false;
    Elem: i32 = Arr[0];
    Index: i32 = -1;
    for i: i32; i < i32(len(Arr)); i += 1
    {
        if(Elem > Arr[i])
        {
            IsFound = true;
            Index = i;
            break;
        }
        Elem = Arr[i];
    }
    return Index, IsFound;
}

// s < e 

ReverseArray:: proc(Arr: []i32)
{
    Start: i32 = 0;
    End: i32 = i32(len(Arr) - 1);
    for ; Start < End;
    {
        Temp: i32 = Arr[Start];
        Arr[Start] = Arr[End];
        Arr[End] = Temp;
        Start += 1;   
        End -= 1;
    }
}

ShiftRight:: proc(Arr: []i32, k: i32)
{
    Temp: i32 = Arr[0];
    i: i32 = 0;
    for ; i <  i32(len(Arr) -  int(k)); i+= 1
    {
        Temp2: i32 = Arr[i+k];
        Arr[i+k] = Temp;
        fmt.print("{old:", Temp, ", ");
        Temp = Temp2;
        fmt.print("new:", Temp, "}\n");
        
    }
    fmt.print( Temp, "}\n");
    Arr[i % i32(len(Arr) - int(k))] = Temp;
}


main:: proc()
{
    numbers := []i32 {1, 2, 3, 4,  5}; // 
    ShiftRight(numbers, 2);
    fmt.print(numbers);
}
