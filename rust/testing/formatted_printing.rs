#![allow(non_snake_case)]
#![allow(dead_code)]
#![allow(unused_variables)]

fn main(){
    let MyStr = format!("format!(): This macro write a formatted text to a string");
    print!("print!(): This prints the formatted text to the console\n");
    print!("{}",MyStr);
    let MyStr2 = format!("printf style strings with more flexiblity");
    print!("\n{} {}\n",MyStr, MyStr2); // replaces the orderwise first set of parns with first argument and so on.
    print!("{1} {0}\n", MyStr, MyStr2); // in this parns we can also define order in which things can go.
    println!("println!(): is Similar to print but adds a newline");
    eprint!("eprint!(): is similar to print but text it printed to io::stderr\n");
    eprintln!("eprintln!(): is similar to eprint!() but adds an newline");
    // some more things related to formated text printing

    // Different formatting can be invoked by specifying the format character
    // after a `:`.
    println!("Base 10:               {}",   69420); // 69420
    println!("Base 2 (binary):       {:b}", 69420); // 10000111100101100
    println!("Base 8 (octal):        {:o}", 69420); // 207454
    println!("Base 16 (hexadecimal): {:x}", 69420); // 10f2c
    
    // You can right-justify text with a specified width. This will
    // output "    1". (Four white spaces and a "1", for a total width of 5.)
    println!("{number:>5}", number=1);
    println!("{number:a>5}", number=1);


    // You can pad numbers with extra zeroes,
    println!("{tin:0>5}", tin=0); // 00001
    // and left-adjust by flipping the sign. This will output "10000".
    println!("{number:0<5}", number=1); // 10000
    // You can use named arguments in the format specifier by appending a `$`.
    println!("{number:0>width$}", number=1, width=5);

}
