package main;

import "core:fmt"

SolidRectangle ::proc(Width:u32,  Height:u32)
{
    for i in 0..<Height
    {
        for j in 0..<Width
        {
            fmt.print("* ");
        }
        fmt.print("\n");
    }

}

SolidRightTriangle ::proc(N: u32)
{
    for i in 0..<N
    {
        for j in 0..< i+1
        {
            fmt.print("* ");
        }
        fmt.print("\n");
    }

}

InvertedSolidRightTriangle ::proc(Width:u32,  Height:u32)
{
    for i in 0..<Height
    {
        for j in 0..< (Width - i)
        {
            fmt.print("* ");
        }
        fmt.print("\n");
    }

}

SolidSlantedRectangle ::proc(Width:u32, Height:u32)
{
    for i in 0..<Height
    {
        Space: u32 =  (Height - (i + 1));
        for space in 0..<Space
        {
            fmt.print(" ");
        }
        for j in 0..< Width
        {
            fmt.print("* ");
        }
        fmt.print("\n");
    }
}

SolidPyramid:: proc(N: u32)
{
    FirstTerm: u32 = 1;
       for i in 0..<N
    {
        Space: u32 =  (N - (i + 1));
        for space in 0..<Space
        {
            fmt.print("  ");
        }
        Stars:u32 = (FirstTerm + (i * 2)); // Ap
        for j in 0..< Stars
        {
            fmt.print("* ");
        }
        fmt.print("\n");
    }
}

InvertedSolidPyramid:: proc(N: u32)
{
    FirstTerm: u32 = (1 + (N - 1) * 2);

    for i in 0..<N
    {
        for space in 0..< i
        {
            fmt.print("  ");
        }

        Stars:u32 = u32(i32(FirstTerm) + (i32(i) * i32(-2))); // Ap

        for j in 0..< Stars
        {
            fmt.print("* ");
        }

        fmt.print("\n");
    }
}

Diamond:: proc(N:u32)
{
    SolidPyramid(N);
    FirstTerm: u32 = (1 + (N - 2) * 2);

    for i in 0..<N - 1
    {
        for space in 0..< i + 1
        {
            fmt.print("  ");
        }

        Stars:u32 = u32(i32(FirstTerm) + (i32(i) * i32(-2))); // Ap

        for j in 0..< Stars
        {
            fmt.print("* ");
        }

        fmt.print("\n");
    }

}

HollowRectangle:: proc(Width: u32 , Height: u32)
{
    for i in 0..<Height {
        Space: u32 ;
        if i == 0 || i == Height-1{
            Space = 0;
        }
        else{
            Space = Width - 2;
        }
        for j in 0..< Width - Space {

            if i == 0 || i == Height - 1
            {
                fmt.print("* ");
                continue;
            }

            fmt.print("* ");

            if(i >= 1)
            {
                for k in 0..< Space
                {
                    fmt.print("  ");
                }

            }

        }
        fmt.print("\n");
    }

}

HollowRightTriangle:: proc(N: u32)
{
    SpaceStart:u32 = 3 - 1;
    for i in 0..<N
    {
        for j in 0..<i + 1
        {
            if j == 0 || j == i|| i == N - 1
            {
                fmt.print("*");
            }
            else if i >= SpaceStart
            {
               fmt.print(" ");
            }
        }
        fmt.print("\n");
    }
}

HollowPyramid:: proc(N: u32)
{
    FirstTerm: u32 = 1;
    for i in 0..<N
    {
        Space: u32 =  (N - (i + 1));
        for space in 0..<Space
        {
            fmt.print("  ");
        }
        StarsWithSpace: u32 = (FirstTerm + (i * 2)); // Ap
        for j in 0..< StarsWithSpace
        {
            if j == 0  || i == N - 1 || j == StarsWithSpace - 1
            {
                fmt.print("* ");
            }
            else
            {
                fmt.print("  ");
            }
        }
        fmt.print("\n");
    }

}

HollowDiamond:: proc(N: u32)
{
  FirstTerm: u32 = 1;
       for i in 0..<N
    {
        Space: u32 =  (N - (i + 1));
        for space in 0..<Space
        {
            fmt.print("  ");
        }
        StarsWithSpace: u32 = (FirstTerm + (i * 2)); // Ap
        for j in 0..< StarsWithSpace
        {
            if j == 0 || j == StarsWithSpace - 1
            {
                fmt.print("* ");
            }
            else
            {
                fmt.print("  ");
            }
        }
        fmt.print("\n");
    }

    IFirstTerm: u32 = (1 + (N - 2) * 2);
    for i in 0..<N - 1
    {
        for space in 0..< i + 1
        {
            fmt.print("  ");
        }

        StarsWithSpace: u32 = u32(i32(IFirstTerm) + (i32(i) * i32(-2))); // Ap

        for j in 0..< StarsWithSpace
        {
            if j == 0 || j == StarsWithSpace - 1
            {
            fmt.print("* ");
            }
            else
            {
                fmt.print("  ");
            }
        }
        fmt.print("\n");
    }

}


Hpattern:: proc(N: u32)
{
    for i in 0..<N
    {
        for j in 0..<i + 1
        {
            fmt.print("* ");
        }

        for k in 0..< 2*(N - i - 1)
        {
            fmt.print("  ");
        }
        for j in 0..<i + 1
        {
            fmt.print("* ");
        }
        fmt.print("\n");
    }

    for i:u32 = N - 1; i > 0; i-=1
    {
        for j:u32 = i; j > 0; j-=1
        {
            fmt.print("* ");
        }

        for k in 0..< 2*(N - i)
        {
            fmt.print("  ");
        }
        for j:u32 = i; j > 0; j-=1
        {
            fmt.print("* ");
        }
        fmt.print("\n");
    }
}

PyramidN:: proc(N: u32)
{
    FirstTerm: u32 = 1;
        Num: u32 = 1;
       for i in 0..<N
    {
        Space: u32 =  (N - (i + 1));
        for space in 0..<Space
        {
            fmt.print("  ");
        }
        Stars:u32 = (FirstTerm + (i * 2)); // Ap
        for j in 0..< Stars
        {
            fmt.print(Num, "");
        }
        fmt.print("\n");
        Num += 1;
    }
}



main:: proc()
{
    HollowDiamond(7);
}
