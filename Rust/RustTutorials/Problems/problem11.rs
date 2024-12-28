use std::io;

fn main(){
    let mut read_row=String::new();
    io::stdin().read_line(&mut read_row).expect("Failed to read");
    let read_row:i32 = read_row.trim().parse().expect("Failed to parse");
    let mut i:i32 = 1;
    let mut first:char ='A';
    while i<=read_row*read_row {
            print!("{}",first);
            first=((first as u8)+1)as char;
         if i%read_row==0{
            println!();
            first='A';
         }
        i+=1;
    }
    ()
}