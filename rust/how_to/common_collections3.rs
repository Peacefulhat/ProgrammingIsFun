//A hash map allows you to associate a value with a specific key. common called a `map`.
#![allow(unused)]
#![allow(nonstandard_style)]
use std::collections::HashMap;

fn main() {
    let mut scores = HashMap::new();
    scores.insert(String::from("Blue"), String::from("Blue2")); // type of the hashmap key: string , value: string.
                                                                //     scores.insert(String::from("Yellow"), 50); // not allowed
    scores.insert(String::from("Yellow"), String::from("Yellow2"));
    let mut scores = HashMap::new();
    scores.insert(String::from("Blue"), 50);
    let val = scores.get("Blue"); // Option<&V>: return to value Some(&V) return.
    println!("{}", val.unwrap());

    let mut scores = HashMap::new();
    scores.insert(30, 50);
    scores.insert(30, 30);
    let val = scores.get(&30);
    let mut scores = HashMap::new();
    scores.insert(String::from("Yellow1"), 50);
    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 32);

    // iterate over hashmap
    for (key, value) in &scores {
        println!("{key}: {value}");
    }
    //Managing Ownership in Hash Maps

    //For types that implement the Copy trait, like i32,
    //the values are copied into the hash map. For owned values like String,
    //the values will be moved and the hash map will be the owner of those values.

    let field_name = String::from("Favorite color");
    let field_value = String::from("Blue");
    let mut map = HashMap::new();
    map.insert(field_name, field_value);
    //map.insert(field_name.clone(), field_value.clone()); // this will clone the values in hashmap from string.
    // field_name and field_value are invalid at this point, try using them and
    // see what compiler error you get!
    //println!("{} {}", field_name, field_value);// error
    print!("Hashmap: ");
    for (Key, Value) in &map {
        println!("{Key} {Value}");
    }

    let mut scores = HashMap::new();
    scores.insert(1, 0);
    scores.insert(2, 0);
    scores.insert(3, 0);
    scores.insert(2, 1);

    print!("Hashmap: \n");
    for (Key, Value) in &scores {
        // will print the hashmap in an unorder manner, default behaviour of hashmap.
        println!("{Key} {Value}");
    }

    let mut scores = HashMap::new();
    scores.insert(1, false);
    scores.insert(2, false);
    scores.insert(3, false);
    scores.insert(2, true);

    //    Adding a Key and Value Only If a Key Isn’t Present
    scores.entry(4).or_insert(false);

    print!("Hashmap: \n");
    for (Key, Value) in &scores {
        // will print the hashmap in an unorder manner, default behaviour of hashmap.
        println!("{Key} {Value}");
    }
    let text = "hello world wonderful world";

    let mut map = HashMap::new();

    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0); // check if word is present or not in hashmap,
        //
        *count += 1; // changing the value of the word.
                     //The or_insert method returns a mutable reference (&mut V) to the value for the specified key.
                     //Here, we store that mutable reference in the count variable, so in order to assign to that value,
                     //we must first dereference count using the asterisk (*). The mutable reference goes out of scope at
                     //the end of the for loop, so all of these changes are safe and allowed by the borrowing rules.
    }

    println!("{map:?}");
}


// Note: more functions and in depth explations visit rust docs std collecitons web page
