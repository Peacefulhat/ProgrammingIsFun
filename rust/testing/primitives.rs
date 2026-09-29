#![allow(unused_variables)]
#![allow(nonstandard_style)]
#![allow(unused_assignments)]

fn main() {
    // Constant
    const THREE_HOURS: u32 = 60 * 60 * 3;

    // Scaler types:
    // singed integer , unsigned interges, float, char, bool and
    // unit type (): meaning doesn't return any thing, and its
    // possible value is empty tuple ()

    // Compound Types:
    // Arrays like [1,2,3]
    // Tuples like (1, true)

    // unsuffxied value variable for float value is f64, and for int  value is i32 same for +ve values

    // scaler type
    let LaState: bool = false;
    let LaFloat: f32 = 23.333;
    let LaUnsigned: u32 = 32;
    let mut LaFloat2 = 12.23232;
    LaFloat2 = 234242.22323212f32;
    println!("{}", LaState);
    println!("{:.1}", LaFloat);
    let lp = &LaFloat2;
    println!("{}", std::mem::size_of_val(lp));
    // shadowing

    let Message = -213;
    println!("{}", Message);
    let Message = 2342.2322;
    println!("{}", Message);
    let Message = -2e-3;
    println!("{}", Message);
    // Note: Debug {:?} can be used with rust known types

    // Compound Types
    let arr: [i32; 5] = [1, 2, 3, 4, 5];
    println!("{:?}", arr);
    let tuple = (5u32, 1u8, true, -5.04f32);
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    let tuple2 = (23, 24, 25);
    let (x, y, z) = tup;
    println!("{0}", tup.2);
    println!("{:?}", tuple);
    println!("{:?}", tuple2);
    println!("{}", THREE_HOURS);
}
