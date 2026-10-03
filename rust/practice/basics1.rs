#![allow(nonstandard_style)]
#![allow(unused)]

// function defination
fn MyFunctions() {
    println!("Hello, World");
}
// function with param
fn FuncParam(S: String) {
    println!("{S}");
}
// function with return value
fn StrLength(S: String) -> usize {
    if S.len() == 0 {
        return 0; // early return from function
    }
    S.len() // returning from function at the end
}

fn main() {
    const PI: f32 = 3.14159; // constant
                             // immutable variable
    let TypeInferedVar = 23; // type inferece variable decleration
    let TypeAnnotedVar: u32 = 54; // type annotated variable.
                                  // mutable variables
    let mut TypeInferedMutVar = 57;
    TypeInferedMutVar = 93;
    let mut TypeAnnotedMutVar: f32 = 3.5f32;
    TypeAnnotedMutVar = 983.393f32;
    println!("Immutable: {TypeInferedVar}");
    println!("Immutable: {TypeAnnotedVar}");
    println!("Mutable: {TypeInferedMutVar}");
    println!("Mutable: {TypeAnnotedMutVar}");
    // Shadowing
    let Var = "str"; // old variable
    let Var = 23; // new variable , new variable shadowed old
                  // old decleration and value are not visible to compiler when we define our new Var.
    println!("{Var}");

    // Scaler types: repersents a single value
    let Int: i32 = 1_000_00i32; // there is u32 and other int types
    let Float: f32 = 3.55f32; // f64 64-bit , f32 32-bit float
    let Boolean: bool = true; // true ,flase
    let Character: char = 'Z'; // utf-8 characters
                               //    let Character: char = 0x27f09f98;// utf-8 characters
    println!("{Character}");
    println!("{Int}");
    println!("{}", (((((Int + 5) * 2) / 5) + 1) % 5)); // numeric operations, same is true for floats

    // Compound Types
    let mut Array: [i32; 5] = [1, 3, 5, 7, 9]; // fixed length
    println!("{}", Array[2]);
    // println!("{}", Array[5]); out out bound , valid index 0 to n-1
    println!("{:?}", Array);
    let mut Tuple: (i32, f32, char) = (65, 65.0, 'A'); // fixed length once defined size can not be changed
    println!("{:?}", Tuple);
    Tuple.0 = 66;
    Tuple.1 = 66.0;
    Tuple.2 = 'B';
    println!("{:?}", Tuple);

    // Functions
    MyFunctions(); // function calling
    let Str = String::from("Function Paramters");
    FuncParam(Str);
    let Str = String::from("Function Return Value");
    let Length = StrLength(Str);
    println!("Length: {Length}");

    // control flow
    let mut X = 23;
    // if experssion
    if X == 23 {
        println!("Yeh");
    }
    // if-else experssion
    X = 27;
    if X == 23 {
        println!("Yeh");
    } else {
        println!("oH, Yeah");
    }

    // using if with let statement

    //    let Z = if X == 27{
    //        X + 1
    //    }; // error only works with if else;

    let Y = if X == 23 { X + 1 } else { X - 1 }; // if is an exp we can use it on the right side of let statement.
                                                 // Note: return value Type in both if and else block should be same other wise error
    if X == 23 {
        println!("Yeh");
    }
    // multiple conditions

    X = 22;
    if X == 23 {
        println!("Yeh");
    } else if X == 100 {
        println!("No, Yeh");
    } else {
        println!("Ok");
    }

    // Repetaions with loops
    let mut I = 1;
    loop {
        if (I > 5) {
            break;
        }
        println!("Print");
        I += 1;
    }
    // loop with let statement
    I = 1;
    let mut nSum = 0;
    let Sum = loop {
        if (I > 5) {
            break nSum; // returning value from loop
        }
        nSum += I;
        I += 1;
    };
    println!("{}", Sum);

    // Disambiguating the loop with loop lables
    let mut BreakCounter = 0;
    let mut Factor = 2;
    'OuterLoop: loop {
        let mut BreakCounter2 = 1;

        loop {
            if BreakCounter2 > 10 {
                break;
            }
            if BreakCounter > 23 {
                println!(
                    "Breakcounter: {}, Breakcounter2: {}, Factor: {}",
                    BreakCounter, BreakCounter2, Factor
                );
                break 'OuterLoop; // breaking out of the outer loop
            }
            BreakCounter = (BreakCounter2 * Factor) / 23;
            BreakCounter2 += 1;
        }
        Factor *= 2;
    }
    // while loop
    let mut WhileCondition: bool = true;
    while WhileCondition {
        println!("While, Hello");
        WhileCondition = false
    }
    let mut X = 0;
    let mut nSum = 0;
    let Sum = while X <= 5 {
        // here sum is unit type, ()
        nSum += X;
        X += 1;
        if X > 5 {
            // break nSum; // not possible
            //  nSum // you can not return value from while loop
        }
    };
    //    println!("{}", Sum);// error
    println!("{}", nSum);

    // looping through a collection;
    let mut Arr: [i32; 5] = [5, 4, 3, 2, 1];
    let mut Index = 0;
    while Index < Arr.len() { // this looping is error prone if
        // we hard code a value like 6, while having only 5,
        // element it will complie and fail at run time.
        // because we will try to access a memory region
        // that we are not suppose to touch.
        //        println!("{}",Tuple.Index); not possible
        println!("{}", Arr[Index]);
        Index += 1;
    }
    for element in (1..5){ // 1, 2, 3, 4 // [) interval
        println!("{}", element);
    }
    
    // looping through a collection with for loop. (to fix the above issue in while loop)
    let mut Arr: [i32; 5] = [93, 82, 829, 292, 29];
    for item in Arr{
        println!("{}", item);
    }
    
}
