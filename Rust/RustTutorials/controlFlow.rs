//Control Flow

//The ability to run some code depending on whether a condition is true and to run some code repeatedly while a condition is true are basic building blocks in most programming languages

fn if_statement(value: bool) -> bool {
    //if Expressions

    //An if expression allows you to branch your code depending on conditions. You provide a condition and then state, “If this condition is met, run this block of code. If the condition is not met, do not run this block of code.”

    //{{{NOTE: condition must be always boolean :}}}
    // let m = 3;
    //if m {
    //    println!("value was three");
    //}
    //error
    // if m { ^ expected `bool`, found integer
    if value {
        println!("noice work");
    }
    if value {
        true
    } else {
        false
    }
}
fn else_if(value: i8) {
    println!("value from else_if function: ");
    if value % 4 == 0 {
        println!("number is divisible by 4");
    } else if value % 3 == 0 {
        println!("number is divisible by 3");
    } else if value % 2 == 0 {
        println!("number is divisible by 2");
    } else {
        println!("number is not divisible by 4,3,or 2");
    }
}
fn if_and_let(value: i16) -> i16 {
    let x = if value > 0 { value + 1 } else { value + 2 };
    return x;
}

//Repetition with Loops

//It’s often useful to execute a block of code more than once. For this task, Rust provides several loops, which will run through the code inside the loop body to the end and then start immediately back at the beginning. To experiment with loops, let’s make a new project called loops.

//Rust has three kinds of loops: loop, while, and for. Let’s try each one.

fn using_loop(mut value: i16) {
    //loop:The loop keyword tells Rust to execute a block of code over and over again forever or until you explicitly tell it to stop.
    println!("value of using_loop function:");
    loop {
        if value == 0 {
            break; // tell to get out of loop or stop the loop.
        }
        if value % 2 == 0 {
            value = value - 1;
            continue;
        }
        println!("{value}");
        value = value - 1;
    }
    // return value form loop.
    let mut counter = 0;
    let x = loop {
        if counter == 10 {
            break counter * 4;
        }
        counter = counter + 1;
    };
    println!("{x},{counter}");
}

// conditional looping
// run untill the condition is true.
fn while_loop(mut value: i16) {
    while value != 0 {
        println!("{value}");
        value -= 1;
    }
}

fn for_loop() {
    let a = [23, 32412, 8892, 234, 929];
    for i in a {
        println!("{0}", i);
    }
    for i in (1..4).rev() {
        println!("{0}", i);
    }
}

fn main() {
    let b = if_statement(true);
    println!("value form if_statement function: {b}");
    println!("");
    else_if(8);
    println!("");
    let b = if_and_let(22);
    println!("value form if_let function:{b}");
    using_loop(23);
    println!("");
    while_loop(10);
    for_loop();
}
