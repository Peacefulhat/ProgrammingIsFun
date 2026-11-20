#![allow(nonstandard_style)]
#![allow(unused)]
fn FirstWordInString(Str: &String) -> String {
    let mut Word = String::from("");
    for Index in Str.chars() {
        if Index == ' ' {
            break;
        }
        Word.push(Index);
    }
    Word
}

fn FirstWordInString2(S: &String) -> usize {
    let Bytes = S.as_bytes(); // convert string to array of bytes
    for (I, &Item) in Bytes.iter().enumerate() {
        // we create an iterator over the array of bytes using the iter method
        // iter is a method that returns each element in a collection and that enumerate wraps the result of iter and returns each element as part of a tuple instead. The first element of the tuple returned from enumerate is the index, and the second element is a reference to the element
        if Item == b' ' {
            // b' ' -> byte literal syntax for space
            // reference to a element in bytes array
            // here we are mapping  b' ' to byte and comparing with element in byte array
            // and return the index at which we found our match
            return I;
        }
    }
    // whole length of string is returned
    S.len()
}

fn main() {
    let mut Str = String::from("Helloafjad kjfda");
    let FirstWord = FirstWordInString2(&Str);
    print!("|");
    print!("{FirstWord}");
    print!("|\n");
    Str.clear();

    // String Slices
    //A string slice is a reference to a contiguous sequence of the elements of a String, and it looks like this:
    // [starting_index..ending_index], starting index is first element,
    //and ending_index is one more than last position in the slice

    let s = String::from("hello world");

    let hello = &s[0..5];
    let world = &s[6..11];

    //    With Rust’s .. range syntax, if you want to start at index 0,
    //you can drop the value before the two periods. In other words, these are equal:

    let s = String::from("hello");
    // Note like this interval: [) index are in this fashion
    let slice = &s[0..2];
    println!("{slice}");
    let slice = &s[..2];
    println!("{slice}");
    let slice = &s[2..s.len()];
    println!("{slice}");
    let slice = &s[2..];
    println!("{slice}");
    let slice = &s[..];
    println!("{slice}");
    //    Note: String slice range indices must occur at valid UTF-8 character boundaries.
    //If you attempt to create a string slice in the middle of a multibyte character,
    //your program will exit with an error.

    // &str -> String Slice type
    let mut Str = String::from("Helloafjad kjfda");
    let FirstWord = FirstWordInString3(&Str);
    print!("|");
    print!("{FirstWord}");
    // Str.clear(); error
    print!("|");

    // String literals as Slices
    let S = "Hello, world!";
    //The type of S here is &str: It’s a slice pointing to that specific point of the binary.
    //This is also why string literals are immutable; &str is an immutable reference.

    // String slices as parameter to functions
    let mut Str = String::from("Helloafjad kjfda");
    let FirstWord = FirstWordInString4(&Str[7..]);
    print!("|");
    print!("{FirstWord}");
    // Str.clear(); error
    print!("|");

    // other types of slices
    #[derive(Debug)]
    struct PP([i32;5]);
    let a = [1, 2, 3, 4, 5];
    let slice = &a[..2];
    //It works the same way as string slices do, by storing a reference to the first element and a length
    println!("{:?}", slice);
    
}

// slice version
fn FirstWordInString3(S: &String) -> &str {
    // return a string slice
    let Bytes = S.as_bytes();
    for (I, &Item) in Bytes.iter().enumerate() {
        if Item == b' ' {
            return &S[0..I];
        }
    }
    &S[..]
}

// string slices as parameter
fn FirstWordInString4(S: &str) -> &str {
    // return a string slice
    let Bytes = S.as_bytes();
    for (I, &Item) in Bytes.iter().enumerate() {
        if Item == b' ' {
            return &S[0..I];
        }
    }
    &S[..]
}

//Summary

//The concepts of ownership, borrowing, and slices ensure memory safety in Rust programs at compile time.
//The Rust language gives you control over your memory usage in the same way as other systems programming languages.
//But having the owner of data automatically clean up that data when the owner goes out of scope means you don’t have
//to write and debug extra code to get this control.

/*Note: &str can be a stack allocated string slice, or slice to a String
(which is heap allocated) and in &'static str's case can be a string literal,
stored in text segment of the binary.
 */
