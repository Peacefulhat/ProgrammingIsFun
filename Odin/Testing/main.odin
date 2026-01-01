
package basic

import "core:fmt"

n_sum:: proc(n:int)-> int{
    if n == 0 {
        return 0;
    }
    return n + n_sum(n-1);
}

fib:: proc(n:int) -> int{
    if n==0 {
        return 0;
    }
    if n==1 {
        return 1;
        
    }
    
    return fib(n-1)+fib(n-2);
}


fibi:: proc(n:int){
    a:int = 0;

    b:int = 1;
    fmt.println("1",":",a);
    fmt.println("2",":",b);

    for i:=3; i<n+3; i+=1 {
        sum :=a+b;
        a = b;
        b = sum;
        fmt.println(i,":",sum);
    }
}

Person:: struct {
    age:int,
    name:string
}

State:: enum{
    OK=1,
    ERROR=0,
}

color:: struct{
    r:u8,
    g:u8,
    b:u8
}


main:: proc(){
    
    fibi(5);
    a := State.OK;
    b := 23;
    #partial switch a {
        
        case State.OK:
        fmt.println("OK");

        case State.ERROR:
        fmt.println("ERROR");
    }

    red := color{255,0,0};
    cp:^u8;
    cp = &red.r;
    fmt.println(cp^);
}
