#![allow(nonstandard_style)]
#![allow(unused_variables)]

fn main() {
    println!("\nControl Flow:\n");
    // if are expression in rust not statement

    // using like a expression
    let X = if !true { 23 + 3 } else { 23 - 3 };
    // using like a statement
    if X != 23 {
        println!("Helo");
    } else {
        println!("Jelo");
    }

    // dealing with multiple condition with else if
    if X > 23 {
        println!("kelo");
    } else if X > 23 {
        println!("oelo");
    } else {
        println!("neither");
    }
    const TERMS:u32 = 10;
    let mut Sum2 = 0;
    let Sum = loop{
        Sum2 = Sum2 + 1;
        println!("Intermediate Sum: {}", Sum2);
        if Sum2 > (TERMS * TERMS) {
            break Sum2;
        }

    };
    println!("Last Sum: {}", Sum);
}
