#![allow(nonstandard_style)]
// Ownership is a set of rules that govern how a Rust program manages memory.
/*
But knowing that the main purpose of ownership is to manage heap data can help explain why it works the way it does.
Ownership Rules
-> Each value in Rust has an owner.
-> There can only be one owner at a time.
-> When the owner goes out of scope, the value will be dropped.
 */

/*
Memory Allocation:

With the String type, in order to support a mutable, growable piece of text, we need to allocate an amount of memory on the heap, unknown at compile time, to hold the contents. This means:

''->   The memory must be requested from the memory allocator at runtime.
->   We need a way of returning this memory to the allocator when we’re done with our String.

 */

/*
Rust takes a different path: The memory is automatically returned once the variable that owns it goes out of scope. Here’s a version of our scope example from Listing 4-1 using a String instead of a string literal:

    {
        let s = String::from("hello"); // s is valid from this point forward

        // do stuff with s
    }                                  // this scope is now over, and s is no
                                       // longer valid

There is a natural point at which we can return the memory our String needs to the allocator: when s goes out of scope. When a variable goes out of scope, Rust calls a special function for us. This function is called drop, and it’s where the author of String can put the code to return the memory. Rust calls drop automatically at the closing curly bracket.

*/
/*
the concept of copying the pointer, length, and capacity without copying the data probably sounds like making a shallow copy. But because Rust also invalidates the first variable, instead of being called a shallow copy, it’s known as a move
 */

fn main() {
    //Heap data copy and struff
    let mut MyStr = String::from("Hello, World!"); // from function is used to create a string on heap using string literal.
    MyStr.push_str(", world!"); // push_str() appends a literal to a String
    let MyStr2 = MyStr; // shallow copy(aka move) MyStr memory will be pointed by MyStr2 and then MyStr will be invalidated.

    let mut MyStr = String::from("Hello, World!"); // from function is used to create a string on heap using string literal.
    MyStr.push_str(", world!"); // push_str() appends a literal to a String
    let MyStr2 = MyStr.clone(); // clone() function is used to perfom a deep copy
    println!("{MyStr}");

    //When you assign a completely new value to an existing variable,
    //Rust will call drop and free the original value’s memory immediately.
    //Consider this code, for example:

    let mut s = String::from("hello");
    s = String::from("ahoy"); // here hello strings memory is free with drop function.
    println!("{s}, world!");

    //Stack-Only Data: Copy
    let x = 5;
    let y = x;
    println!("x = {x}, y = {y}");
    /*
    The reason is that types such as integers that have a known size at compile time are stored entirely on the stack, so copies of the actual values are quick to make. That means there’s no reason we would want to prevent x from being valid after we create the variable y. In other words, there’s no difference between deep and shallow copying here, so calling clone wouldn’t do anything different from the usual shallow copying, and we can leave it out.

    Rust has a special annotation called the Copy trait that we can place on types that are stored on the stack, as integers are. If a type implements the Copy trait, variables that use it do not move, but rather are trivially copied, making them still valid after assignment to another variable.
     Here are some of the types that implement Copy:
     ->All the integer types, such as u32.
     ->The Boolean type, bool, with values true and false.
     ->All the floating-point types, such as f64.
     ->The character type, char.
     ->Tuples, if they only contain types that also implement Copy. For example, (i32, i32) implements Copy, but (i32, String) does not.

         */

    //Ownership and Functions
    //The mechanics of passing a value to a function are similar to those when assigning a value to a variable. Passing a variable to a function will move or copy, just as assignment does.
    // in heap allocted type: move will happen(shallow copy)
    // in stacked allocated types: copy will happen(deep copy)
    let s = String::from("hello"); // s comes into scope

    //    takes_ownership(s); // s's value moves into the function...
    // ... and so is no longer valid here
    takes_ownership(s.clone());
    println!("{s}");
    let x = 5; // x comes into scope

    makes_copy(x); // Because i32 implements the Copy trait,
                   // x does NOT move into the function,
    // so it's okay to use x afterward.
    
    // Return Values and Scope: Returning values can also transfer ownership.
    
    let s1 = gives_ownership(); // gives_ownership moves its return
                                // value into s1
    println!("{s1}");
    let s2 = String::from("hello"); // s2 comes into scope

    let s3 = takes_and_gives_back(s2); // s2 is moved into
                                       // takes_and_gives_back, which also
                                       // moves its return value into s3
                                       // Here, s3 goes out of scope and is dropped. s2 was moved, so nothing
                                      // happens. s1 goes out of scope and is dropped.
    println!("{s3}");

    // stack variable passed to function as copy not actual variable
    let x = 23;
    let y = change_owner(x);
    println!("{x}, {y}");
}
// Here, x goes out of scope, then s. However, because s's value was moved,
// nothing special happens.

fn change_owner(x: i32) ->i32{
    x
}
fn gives_ownership() -> String {
    // gives_ownership will move its
    // return value into the function
    // that calls it

    let some_string = String::from("yours"); // some_string comes into scope

    some_string // some_string is returned and
                // moves out to the calling
                // function
}

// This function takes a String and returns a String.
fn takes_and_gives_back(a_string: String) -> String {
    // a_string comes into
    // scope

    a_string // a_string is returned and moves out to the calling function
}

fn takes_ownership(some_string: String) {
    // some_string comes into scope
    println!("{some_string}");
} // Here, some_string goes out of scope and `drop` is called. The backing
  // memory is freed.

fn makes_copy(some_integer: i32) {
    // some_integer comes into scope
    println!("{some_integer}");
} // Here, some_integer goes out of scope. Nothing special happens.x


/*
When a variable that includes data on the heap goes out of scope, the value will be cleaned up by drop unless ownership of the data has been moved to another variable.
*/
