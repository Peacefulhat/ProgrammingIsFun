#![allow(non_snake_case)]
#![allow(dead_code)]
#![allow(unused_variables)]
#![allow(unused_imports)]
//use std::io;
use std::fmt;

#[derive(Debug)]
struct Person<'a> {
    name: &'a str,
    age: u8
}

// A structure holding two numbers. `Debug` will be derived so the results can
// be contrasted with `Display`.
#[derive(Debug)]
struct MinMax(i64, i64);

// Implement `Display` for `MinMax`.
impl fmt::Display for MinMax {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        // Use `self.number` to refer to each positional data point.
        write!(f, "({}, {})", self.0, self.1)
    }
}

// Define a structure where the fields are nameable for comparison.
#[derive(Debug)]
struct Point2D {
    x: f64,
    y: f64,
}

// Similarly, implement `Display` for `Point2D`.
impl fmt::Display for Point2D {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        // Customize so only `x` and `y` are denoted.
        write!(f, "x: {}, y: {}", self.x, self.y)
    }
}


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

    // Debug
    struct UnPrintable(i32);
    
    #[derive(Debug)]
    struct Structure(i32);
    
    #[derive(Debug)]
    struct DebugPrintable(i32);
    println!("Now {0:?} {1:?} will print!", Structure(3), DebugPrintable(-2342));
    
    let name = "Peter";
    let age = 27;
    let peter = Person { name, age };

    // Pretty print
    println!("{:#?}", peter);

    struct Structure2(i32);

// To use the `{}` marker, the trait `fmt::Display` must be implemented
// manually for the type.
impl fmt::Display for Structure2 {
    // This trait requires `fmt` with this exact signature.
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        // Write strictly the first element into the supplied output
        // stream: `f`. Returns `fmt::Result` which indicates whether the
        // operation succeeded or failed. Note that `write!` uses syntax which
        // is very similar to `println!`.
        write!(f, "{}", self.0)
    }
}
    let p = Point2D{x:2.73, y:3.323};
    println!("{}", Structure2(-32));
    println!("{:#?}", p);
    println!("{}", p);
}
