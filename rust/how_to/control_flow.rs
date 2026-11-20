#![allow(nonstandard_style)]
#![allow(unused_variables)]
//#![allow(unused_labels)]

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

    // loop in rust
    /*
        const TERMS: u32 = 10;
        let mut Sum2 = 0;
        let Sum = loop {
            Sum2 = Sum2 + 1;
            println!("Intermediate Sum: {}", Sum2);
            if Sum2 > (TERMS * TERMS) {
                break Sum2;
            }
        };
        println!("Last Sum: {}", Sum);
    */
    // loop lables
    /*    const TABLE_SET_MAX: u32 = 10;
        let mut TableSetNumber = 1;
        const MAX_COUNT: u32 = 10;
        'TableSet: loop {
            if TableSetNumber <= TABLE_SET_MAX {
                println!("Table of {}:", TableSetNumber);
            }

            let mut Counter = 1;
            loop {
                if TableSetNumber > TABLE_SET_MAX {
                    break 'TableSet;
                }
                println!(
                    "{0} x {1} = {2}",
                    TableSetNumber,
                    Counter,
                    (TableSetNumber * Counter)
                );
                if Counter == MAX_COUNT {
                    break;
                }
                Counter += 1;
            }
            TableSetNumber += 1;
        }
    */
    // while loop
    // Note: while loop expects you to return unit type '()' absence of anything like empty.

    while true {
        println!("Hello, from while loop");
        break;
    }
    let mut X = 1;
    let Ap: () = while X != 2 {
        println!("Hello, from while loop");
        X += 1;
    };
    println!("{:?}", Ap);

    // Looping through a collection with while
    let Arr: [i32; 5] = [1, 2, 3, 4, 5];
    let mut Index = 0;
    while Index < 5 {
        println!("{}", Arr[Index]);
        Index += 1;
    }

    // Looping through a collection with for
    /*
    for item in Arr {
        println!("{}", item);
    }
     */
    // this is inclusive on first item 0 and exclusive on last 4
    // [0,4)
    // if we go in reverse direcion it still same.
    for item in (0..4).rev() {
        println!("{}", item);
    }
}
