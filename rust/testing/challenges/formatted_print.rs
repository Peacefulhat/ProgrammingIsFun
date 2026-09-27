#![allow(non_snake_case)]
#![allow(nonstandard_style)]
#![allow(dead_code)]
#![allow(unused_imports)]

use std::fmt;
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
    /* challenge
    Display: 3.3 +7.2i
    Debug: Complex { real: 3.3, imag: 7.2 }
    Display: 4.7 -2.3i
    Debug: Complex { real: 4.7, imag: -2.3 }
     */
    #[derive(Debug)]
    struct complex{
        Real: f64,
        Img: f64
    }
    impl fmt::Display for complex {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            if self.Img > 0.0 {
                write!(f, "{} + {}i", self.Real, self.Img)
            }
            else{
                write!(f, "{} - {}i", self.Real, self.Img.abs())
            }
        }
    }
    let A = complex{Real: 3.3, Img: 7.2};
    let B = complex{Real: 4.7, Img: -2.3};
    println!("Display: {}", A);
    println!("Debug: {:?}", A);
    println!("Display: {}", B);
    println!("Debug: {:?}", B);
}
