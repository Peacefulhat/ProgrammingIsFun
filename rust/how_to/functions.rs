/*
Statements: are instructions that perform some action and do not return a value.
example: let x = 232;
if condition [
// do some thing
}
etc
Expressions: evaluate to a resultant value.
example: let x = {
let y= 2;
y
}

Note:: Calling a function is an expression. Calling a macro is an expression. A new scope block created with curly brackets is an expression
Note:: expression do not include ending semicolon
 */

#![allow(nonstandard_style)]

fn Func2(Y: i32) -> i32 {
    let X = { Y + 1 };
    X
}

fn Func3(X: i32) -> i32 {
    if X < 0 {
        return X; // returning early from function using return keyword
    }
    X + 3 // last expression which will result in a value that the function will return
}

fn Message(X: i32, Y: &str) {
    println!("Message function {X} + {Y}");
}

fn main() {
    println!("\nFunctions:\n");
    Message(2, "hello");
    let Result = Func2(23);
    println!("{Result}");
    let Result = Func3(-2);
    println!("{Result}");
    let Result = Func3(23);
    println!("{Result}");
}
