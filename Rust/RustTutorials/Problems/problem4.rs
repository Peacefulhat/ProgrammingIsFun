// 1 2 3
// 4 5 6
// 7 8 9
use std::io;

fn main(){
let mut r=String::new();
io::stdin().read_line(&mut r).expect("Failed to read row");
let r:i16=r.trim().parse().expect("Failed to parse row");
let mut c=String::new();
io::stdin().read_line(&mut c).expect("Failed to read row");
let c:i16=c.trim().parse().expect("Failed to parse col");
let mut i:i16=1;

  while i <= r*c {
  if i%c==0 {
      print!("{0}",i);
      print!("\n");
  }else{
  print!("{0} ",i);
  }
  i=i+1;
  } 
    ()
}
