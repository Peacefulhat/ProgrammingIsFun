#![allow(nonstandard_style)]
#![allow(unused)]

pub mod garden;
//(as) keyword:There’s another solution to the problem of bringing two types of
//the same name into the same scope with use:
//After the path, we can specify as and a new local name, or alias, for the type.
//pub use garden::sum as new_sum; // alias
pub use garden::sum; // alternate way to import module
//use crate::garden::sum; // abs path to module

// we can use nested paths to bring the same items into scope in one line.
//We do this by specifying the common part of the path, followed by two colons,
//and then curly brackets around a list of the parts of the paths that differ
use std::io::{self, Write}; // multiple imports, here self imports io module it self and Wirte module to if Wirte is a module.

use rand::random;
//Adding rand as a dependency in Cargo.toml tells Cargo to download the rand package and
//any dependencies from crates.io and make rand available to our project.

//If we want to bring all public items defined in a path into scope,
//we can specify that path followed by the * glob operator:
use std::collections::*;

fn main() {
    let Plant = garden::vegetables::vegetable {
        Name: String::from("Asparagus"),
        Calorie: 20,
        RichInVitamins: String::from("Vitamin K , Vitamin A, Vitamin C, folate"),
    };
    garden::VegitableDetails(&Plant);
//    let temp = new_sum::add(23, 24); // using alias
    let temp = sum::add(23, 24); // using alias
    println!("second module form one module: {}", temp);
    println!("{}", random::<u8>());

    // this show that glob operator is used to import all the public members of module from path `std::collections`
    let mut MyHashMap = HashMap::new(); // insert some value after insertion in hashmap.
    MyHashMap.insert(
    "Adventures of Huckleberry Finn".to_string(),
    "My favorite book.".to_string(),
    );
    let mut MyHashSet = HashSet::new();
    MyHashSet.insert(23u8);
    println!("{:?}", MyHashSet);
    
    // parent functions was called inside log()
    sum::log("This is a String slice(aka string literal)");
}
