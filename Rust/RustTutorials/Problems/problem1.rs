//To check if given character is in lower case or uppercase
use std::io;

fn main() {
    println!("Program to check if character is uppercase of lowercase");
    let mut console_read = String::new();
    io::stdin()
        .read_line(&mut console_read)
        .expect("Failed to read");
    let ch: char = console_read.trim().parse().expect("Failed to Parse");
    if ch >= 'a' && ch <= 'z' {
        print!("This is lowerCase");
    } else if ch >= 'A' && ch <= 'Z' {
        print!("This is upperCase");
    } else {
        print!("Not a character");
    }
    return ();
}
