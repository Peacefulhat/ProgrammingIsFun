use std::io;

fn star_print(row:i32){
let mut rc:i32=1;
let mut tstar=(row*(row+1))/2;
let mut star=rc;
let mut printable:i32=1;

while tstar>0{
if star<=rc{
print!("{0} ",printable);
printable+=1;
tstar-=1;
star+=1;
}else{
print!("\n");
rc+=1;
star=1;
}
}
} 



fn main(){
    let mut row = String::new();
    io::stdin().read_line(&mut row).expect("Failed to read");
    let row:i32=row.trim().parse().expect("Failed to Parse");
    star_print(row);
    ()
}
