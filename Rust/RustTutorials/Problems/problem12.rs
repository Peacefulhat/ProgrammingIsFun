use std::io;

fn main()
{
     let mut row = String::new();
     io::stdin().read_line(&mut row).expect("Failed to read");
     let row:i32=row.trim().parse().expect("Failed to parse");
     let mut col = String::new();
     io::stdin().read_line(&mut col).expect("Failed to read");
     let col:i32=col.trim().parse().expect("Failed to parse");
    let mut first:char='A';    
     let mut i:i32=1;
    let mut tr:u8=0;
    let mut tc:i32=1; 
     while i<=row*col{
       if tc<=col{
        print!("{0}",first);
        first= ((first as u8)+1)as char;
        tc=tc+1;
       i=i+1; 
       }else{
        println!();
        tr=tr+1;
        first='A';
        first=((first as u8)+tr)as char;
        tc=1;
       }
     }
    
()
}