use std::io;

fn main(){
   let mut row = String::new();
   io::stdin().read_line(&mut row).expect("Failed to read");
   let row:i32 = row.trim().parse().expect("Failed to parse");
   let mut t = 1;
   let mut v:i32 = 1;
   let mut total = (row*(row+1))/2;
   while total > 0 {
   if t > 0{
    print!("{0}",t);
    t = t - 1;
    total = total - 1;
   }
   if t == 0 {
    print!("\n"); 
    v = v + 1;
   t = v;
   }

   }
    ()
}
