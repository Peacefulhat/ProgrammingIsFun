use std::io;

fn main(){

    let mut row = String::new();
    io::stdin().read_line(&mut row).expect("Failed to read");
    let row:i32 = row.trim().parse().expect("Failed to parse");
    let mut first:char='A';
    // row and coloums are same 
    let mut i:i32=row*row;
    while i>0{
        if i%row!=0||i==row*row{
            print!("{0}",first);
        }else{
            print!("\n");
            first=((first as u8)+1) as char;
            print!("{0}",first);
        }
        i=i-1;
    } 
    
()
}