#![allow(nonstandard_style)]
#![allow(unused_variables)]

fn main() {
    println!("\nControl Flow:\n");
    // if are expression in rust not statement

    // using like a expression
    let x = if !true { 23 + 3 } else { 23 - 3 };
    // using like a statement
    if x != 23 {
        println!("Helo");
    } else {
        println!("Jelo");
    }

    // dealing with multiple condition with else if
    if x > 23 {
        println!("kelo");
    } else if x > 23 {
        println!("oelo");
    } else {
        println!("neither");
    }
}
