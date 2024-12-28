use std::io;

fn main(){
let mut row_input=String::new();
io::stdin().read_line(&mut row_input).expect("Failed to read");
let mut row_input:u8=row_input.trim().parse().expect("Failed to parse");
let mut i:i32=1;
let mut c:i32=1;
let mut value:char='A';
value=((value as u8)+row_input-1)as char;
while row_input > 0 {
if i<=c{
    print!("{}",value);
    value=((value as u8)+1)as char; 
    i+=1;
}else{
    println!();
    row_input-=1;
    c+=1;
    i=1;
    value='A';
    value=((value as u8)+row_input - 1 )as char; 
}
;

}

()
}