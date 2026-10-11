#![allow(unused)]
#![allow(nonstandard_style)]

//Rust groups errors into two major categories: recoverable and unrecoverable errors
//recoverable error: such as a file not found error, we most likely just want to report the problem to the user and retry the operation.
//Unrecoverable errors: are always symptoms of bugs, such as trying to access a location beyond the end of an array, and so we want to immediately stop the program.

//Most languages don’t distinguish between these two kinds of errors and handle both in the same way,
//using mechanisms such as exceptions. Rust doesn’t have exceptions. Instead, it has the type Result<T, E>
//for recoverable errors and the panic! macro that stops execution when the program encounters an unrecoverable error.
//This chapter covers calling panic! first and then talks about returning Result<T, E> values.
//Additionally, we’ll explore considerations when deciding whether to try to recover from an error or to stop execution.

// Two ways to cause panic :
// 1) by taking an action that causes our code to panic (such as accessing an array past the end)
// 2) By default, these panics will print a failure message, unwind, clean up the stack, and quit.
// Via an environment variable, you can also have Rust display the call stack when a panic occurs
//to make it easier to track down the source of the panic.

// Note see rust book : unwindning and aborting in response to panic.

use std::fs::File;

fn main() {
    // unrecoverable errors

    //    panic!("Crash and Burn"); we are calling panic! macro ourselves.
    let my_vec = vec![1, 2, 3];
//    println!("{}", my_vec[99]); // here it happeing by the code, we were trying to access at invlid index.

    // recoverable errors
    /*
    enum Result<T, E> {
                Ok(T),
                Err(E)
        }
     */
let MyFile = File::open("helo.txt");
}

