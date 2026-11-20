#![allow(nonstandard_style)]

/*
pointer version of rust is reference, rust also provides raw pointer.

A reference is like a pointer in that it’s an address we can follow to access the data stored at that address; that data is owned by some other variable. Unlike a pointer, a reference is guaranteed to point to a valid value of a particular type for the life of that reference.

references: they allow you to refer to some value without taking ownership of it.
Because the reference does not own it, the value it points to will not be dropped when the reference stops being used.

-> We call the action of creating a reference borrowing.
-> Just as variables are immutable by default, so are references. We’re not allowed to modify something we have a reference to.
Note: Mutable references allow to modify the borrowed values.
Note: The opposite of referencing by using & is dereferencing, which is accomplished with the dereference operator, *
example: &String is immutable reference.
example: &mut String is a mutable reference.
 */

fn CalculateLength(s: &String) -> usize {
    // s is a reference to a String
    s.len()
} // Here, s goes out of scope. But because s does not have ownership of what
  // it refers to, the String is not dropped.

// Mutable references
fn CalculateLength2(s: &mut String) -> usize {
    // s is a reference to a String
    s.push_str(", World");
    s.len()
} // Here, s goes out of scope. But because s does not have ownership of what
  // it refers to, the String is not dropped.

fn main() {
    let MyStr = String::from("Heloo");
    let StringLength = CalculateLength(&MyStr);
    println!("Immutable reference:\nString: {MyStr}\nLength: {StringLength}"); // this is not possible because ownership was moved and the moved
                                                                               // variable gone out of the scope

    let mut MyStr = String::from("Heloo");
    let StringLength = CalculateLength2(&mut MyStr);
    println!("Mutable reference:\nString: {MyStr}\nLength: {StringLength}");

    //Note: If you have a mutable reference to a value, you can have no other references to that value.
    // let mut s = String::from("hello");

    //let r1 = &mut s;
    //let r2 = &mut s;

    /*    A data race is similar to a race condition and happens when these three behaviors occur:

    Two or more pointers access the same data at the same time.
    At least one of the pointers is being used to write to the data.
    There’s no mechanism being used to synchronize access to the data.

    Data races cause undefined behavior and can be difficult to diagnose and fix when you’re trying to track them down at runtime;
    Rust prevents this problem by refusing to compile code with data races!
     */
    let mut s = String::from("hello");

    {
        let r1 = &mut s;
    }
    let r2 = &mut s;

    //Note: We also cannot have a mutable reference while we have an immutable one to the same value.
    /*    let mut s = String::from("hello");

    let r1 = &s; // no problem
    let r2 = &s; // no problem
    let r3 = &mut s; // BIG PROBLEM

    println!("{r1}, {r2}, and {r3}");
     */
    
    let mut s = String::from("hello");

    let r1 = &s; // no problem
    let r2 = &s; // no problem
    println!("{r1} and {r2}");
    // Variables r1 and r2 will not be used after this point.

    let r3 = &mut s; // no problem
    println!("{r3}");

    // Danggling references
    let reference_to_nothing = dangle();
  
  
  
}

/*
fn dangle() -> &String { // dangle returns a reference to a String

    let s = String::from("hello"); // s is a new String

    &s // we return a reference to the String, s
} // Here, s goes out of scope and is dropped, so its memory goes away.
  // Danger!
 */

//This works without any problems. Ownership is moved out, and nothing is deallocated.
fn no_dangle() -> String {
    let s = String::from("hello");
    s 
}
// Quick summery:

//At any given time, you can have either one mutable reference or any number of immutable references.
//References must always be valid.
