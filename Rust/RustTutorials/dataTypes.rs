// data types: Every value in Rust is of a certain data type, which tells Rust what kind of data is being specified so it knows how to work with that data.
// rust is statically typed languaged,which means that it must know the type of all variables at
// compile time.
fn main() {
    // scalar types:
    //A scalar type represents a single value. Rust has four primary scalar types: integers, floating-point numbers, Booleans, and characters.
    // integer type:
    let l: i8 = 127; // signed int i8 = 1byte ,i16=2byte and so on.
    println!("integer i8: {l}");
    let l: u8 = 255; // unsigned int u8=1byte and so on.
    println!("unsigned integer u8: {l}");
    // floating-point types:
    //Rust also has two primitive types for floating-point numbers, which are numbers with decimal points. Rust’s floating-point types are f32 and f64, which are 32 bits and 64 bits in size, respectively. The default type is f64 because on modern CPUs, it’s roughly the same speed as f32 but is capable of more precision. All floating-point types are signed.
    let l: f32 = 2.71; // explicit type define of variable.
    println!("floating-point f32: {l}");
    let l = 2342.2344; // implicit type define of variable.
    println!("floating-point f64: {l}");

    // Booleans:
    let l: bool = true;
    println!("boolean: {l}");
    let l = false;
    println!("boolean: {l}");

    // character type:
    //char literals with single quotes, as opposed to string literals, which use double quotes.
    //Rust’s char type is four bytes in size and represents a Unicode Scalar Value, which means it can represent a lot more than just ASCII.
    let l = 'A';
    println!("character: {l}");
    let l: char = 'z';
    println!("character: {l}");

    //Compound Types:

    //Compound types can group multiple values into one type. Rust has two primitive compound types: tuples and arrays.

    //The Tuple Type:

    //A tuple is a general way of grouping together a number of values with a variety of types into one compound type. Tuples have a fixed length: once declared, they cannot grow or shrink in size.

    //We create a tuple by writing a comma-separated list of values inside parentheses. Each position in the tuple has a type, and the types of the different values in the tuple don’t have to be the same.

    let l: (u8, i8, char) = (255, 127, 'A');
    println!("{0}", l.0); // l.0 or l.1 ... will allow us to access the element at that index like
                          // l.0 l.index
                          //The tuple without any values has a special name, unit. This value and its corresponding type are both written () and represent an empty value or an empty return type. Expressions implicitly return the unit value if they don’t return any other value.
                          // Arrays type:
                          //Unlike a tuple, every element of an array must have the same type. Unlike arrays in some other languages, arrays in Rust have a fixed length.
                          //syntax let arrayName:[type;size]=[values];
    let l: [i8; 5] = [1, 2, 3, 4, 5];
    println!("value of array : {0}", l[4]);
    // index start form 0

    // arrayName[index] this how to access elements of array.

    // other ways to define array.
    let a = [3; 5];
    println!("value of array: {0}", a[3]);
    //The array named a will contain 5 elements that will all be set to the value 3 initially. This is the same as writing let a = [3, 3, 3, 3, 3]; but in a more concise way.
    let a = [1, 2, 3, 4, 5]; // implicit array type.
    println!("value of array: {0}", a[1]);
}
