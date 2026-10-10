#![allow(unused)]
#![allow(nonstandard_style)]

use std::collections::*;

fn main() {
    //A vector allows you to store a variable number of values next to each other.
    /*    pub struct Vec<T, A = Global>
    where
        A: Allocator,
    {
        /* private fields */ }
     */
    let mut MyVector = Vec::<i32>::new();
    let v = vec![1, 2, 3]; // initialization with vec! macro
    MyVector.push(-23); // add item to end of vector
    MyVector.push(73); // add item to end of vector
    MyVector.push(33); // add item to end of vector
    MyVector.push(-93); // add item to end of vector
    println!("{}", MyVector[0]); // index based accessing.
                                 //println!("{}", MyVector.pop().unwrap());// `pop` return Option<T>
    println!("{}", MyVector.len()); // index based accessing. `pop` return Option<T>
    println!("{}", MyVector.capacity());
    MyVector.extend([1, 2, 3]);
    println!("{}", MyVector.len());
    MyVector.extend([4, 5, 6]);
    println!("{}", MyVector.capacity());
    for item in &MyVector {
        // if not borrowed ownership of MyVector will go away
        println!("{}", item);
    }
    println!("{}", MyVector.capacity());
    // Option<&T> return type kindof
    let MyVecSlice = MyVector.get(1); // index; returns Option<&i32>
    println!("{}", MyVecSlice.unwrap());

    let MyVecSlice = MyVector.get(100);
    println!("{:?}", MyVecSlice); // just return None,
                                  // Because of invalid index.

    let MyVecSlice = MyVector.get(..3); //slice;// returns Option<&[i32]>

    println!("{}", MyVector.capacity());
    for Elem in MyVector {
        println!("{}", Elem);
    }

    let mut v = vec![100, 32, 57];
    for i in &mut v {
        *i += 50; //derefrecing &mut{integer}
    }
    println!("{:?}", v);
    #[derive(Debug)]
    enum SpreadsheetCell {
        Int(i32),
        Float(f64),
        Text(String),
    }


    let row = vec![
        SpreadsheetCell::Int(3),
        SpreadsheetCell::Text(String::from("blue")),
        SpreadsheetCell::Float(10.12),
    ];
    println!("{:?}", row);
    //A string is a collection of characters. We’ve mentioned the String type previously,
    //A hash map allows you to associate a value with a specific key. common called a `map`.
}
