use std::io;

fn sum_of_n_natural_numbers(value: i16) -> i32 {
    let sum: i32 = ((value * (value + 1)) / 2).into(); // .into() will convert from smaller type to larger
                                                       // type
    sum
}
fn sum_of_n_natural_numbers_using_loops(value: i16) -> i32 {
    let mut sum: i32 = 0;
    let mut i: i16 = 1;
    while i <= value {
        sum += <i16 as Into<i32>>::into(i);
        i += 1;
    }
    sum
}
fn main() {
    let mut console_read = String::new();
    io::stdin()
        .read_line(&mut console_read)
        .expect("Faild to read");
    let value = console_read.trim().parse().expect("Failed to parse");
    let y = sum_of_n_natural_numbers_using_loops(value);
    println!("{0}", y);
}
