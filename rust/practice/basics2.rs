#![allow(nonstandard_style)]
#![allow(unused)]

fn main() {
    // Slice (Type: &str) Slices let you reference a contiguous sequence of elements in a collection;
    let mut Str = String::from("This is Slice");
    let Slice = &Str[2..5]; // [) interval
    let Slice = &Str[2..]; // 2 to end - 1
    let Slice = &Str[..5]; // 0 to 4
    let Slice = &Str[..]; // whole string as slice
    println!("{}", Slice);
    let mut Str = String::from("int:: NewVar = 23;");
    let mut StringSlice = &Str[..];
    let Updatedtext = SliceFunc(&StringSlice);
    println!("{}", Updatedtext);

    // other slice type is &i32
    let a = [1, 2, 3, 4, 5];
    let slice = &a[1..3];

    SliceFunc2("Helo, world"); // string literal are like of
                               // &str type
}

fn SliceFunc2(Str: &str) {
    println!("{}", Str);
}
fn SliceFunc(Str: &str) -> &str {
    let Token = String::from("int::");
    let Slice = &Token[..];
    if Str[..Token.len()] == Slice[..] {
        println!("found");
        return &Str[Token.len()..];
    }
    &Str[..]
}
