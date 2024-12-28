use std::io;

fn star_print(rows:i32){
    let mut rc:i32 = 1;
    let mut star:i32 = rc;
    let mut tstar:i32 = (rows*(rows+1))/2;
    while tstar > 0{
    if star<=rc {
        print!("*");
        star+=1;
        tstar=tstar-1;
    }else{
    print!("\n");
    rc=rc+1;
    star=1;
    }
    }  
}


fn main(){
    let mut row=String::new();
    io::stdin().read_line(&mut row).expect("Failed to read row");
    let row:i32=row.trim().parse().expect("Failed to parse");

    star_print(row);
    ()
}
