use std::io;

fn main() {
    let mut rows = String::new();
    io::stdin().read_line(&mut rows).expect("Failed to read");
    let rows: i16 = rows.trim().parse().expect("Failed to parse rows");

    let mut cols = String::new();
    io::stdin().read_line(&mut cols).expect("Failed to read");
    let cols: i16 = cols.trim().parse().expect("Failed to parse cols");

    let mut i: i16 = 1;
    while i <= rows * cols {
        if i % cols == 0 {
            print!("*");
            print!("\n");
        } else {
            print!("*");
        }
        i += 1;
    }
    ()
}
