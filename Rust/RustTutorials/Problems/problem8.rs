use std::io;


fn main(){
    let mut row = String::new();
    io::stdin().read_line(&mut row).expect("Failed to read");
    let row:i32=row.trim().parse().expect("Failed to parse");
    let mut total:i32=(row*(row+1))/2;
    let mut term:i32=1;
    let mut first:i32=1;
    let mut temp:i32=term;
    while total > 0 {
      if term>0{
        print!("{0}",temp);
        temp=temp+1;
        term=term-1;
        total=total - 1;
      }
      if term == 0 {
      print!("\n");
      first = first+1;
      term=first;
      temp = term;
      }
    }
    ()
}
