use std::io; // import for input output operations.
fn main() {
    println!("Guess the number!"); // print line things to console;
    println!("Please input your guess.");
    let mut guess = String::new();
    io::stdin() // read lined from console
        .read_line(&mut guess)
        .expect("Failed to read line"); // if unable to read print this.

    println!("You guessed: {guess}");
}
