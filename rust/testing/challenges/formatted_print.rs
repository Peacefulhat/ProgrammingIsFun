#![allow(non_snake_case)]
// these are most common formatting stuff for more information on formatting read std::fmt docs
fn main(){
    // println!("My name is {0}, {1} {0}", "Bond");
    // FIXME ^ Add the missing argument: "James"
    println!("My name is {0}, {1} {0}", "Bond", "James");
    println!("My name is {0}, {1} {0}", "James", "Bond");
    
    // print floating point number with precision
    let Pi = 3.14159;
    let e = 2.719;
    println!("{:.5}",Pi);
    println!("{0:.4}, {1:.1}",Pi, e);
}
