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

    // Printing vectors, try changing the code so that it print index as well
    #[derive(Debug)]
    struct list(Vec<i32>);

    impl fmt::Display for list {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            // create the reference to the vec<i32> in the list structure
            let Vec = &self.0;
            write!(f, "[")?;
            for (index, v) in Vec.iter().enumerate() {
                if index != 0 {
                    write!(f, ", ")?;
                }
                write!(f, "{0}:{1} ", index, v)?;
            }
            write!(f, "]")
        }
    }
    let items = list(vec![23, 24, 25, 26, 27]);
    println!("Debug: {:#?}", items);
    println!("Display: {}", items);
    //  color formatting challenge
    #[derive(Debug)]
    struct color {
        Red: u8,
        Green: u8,
        Blue: u8,
    }
    impl fmt::Display for color {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result{
            write!(f, "RGB ({0}, {1}, {2}) 0x{0:02X}{1:02X}{2:02X}", self.Red, self.Green, self.Blue)
        }
    }

    for Color in [
   color { Red: 128, Green: 255, Blue: 90}, 
   color { Red: 0, Green: 3, Blue: 254},
   color { Red: 0, Green: 0, Blue: 0}, 
    ]{
              println!("{}", Color);
    }
}
