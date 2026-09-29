/*
Statements: are instructions that perform some action and do not return a value.
Expressions: evaluate to a resultant value.

Note:: Calling a function is an expression. Calling a macro is an expression. A new scope block created with curly brackets is an expression,
 */

#![allow(nonstandard_style)]

fn Func2(Y: i32) -> i32 {
    let X = { Y + 1 };
    X
}

fn Message(X: i32, Y: &str) {
    println!("Message function {X} + {Y}");
}

fn main() {
    println!("main function");
    Message(2, "hello");
    let Result = Func2(23);
    println!("{Result}");
}
