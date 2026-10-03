#![allow(unused)]
#![allow(nonstandard_style)]

// for data allocated in heap
// Ownership
// Every value has a owner.
// one value and have only one owner at a time.
// if owner goes out of the scope the value is dropped

// Borrowing(reference)
// we can have indefinate amout of immutable references or can have one mutable reference at a time.
// reference should be valid


// here we changed the ownership of value  and then again send it back to original variable.
fn Preserve(mut S: String) -> String{
    S.push_str(", World 3");
    let mut Result =  S;
    Result
}
fn TransferOwnership(S: String){
    //This function will remove onwership of passed variable
    // the parameter is going to the new onwner and the value will be dropped,
    // when function goes out of scope
}

fn SendOwnership() -> String{
    let Result = String::from("Onweship Send"); // This variable onwer ship is going to transfered to other variable
    Result // return Result;
}

fn main() {
    // ownership
    let x = 23; // stack value
    let y = x;
    println!("{}", y);
    let Str = String::from("Hello, World!");
    let Str2 = Str; // ownership transferr (move) pointer ,len , capacity copied to Str2
                    // (pointer len , capacity are on the stack)
                    // invalidated the first variable
                    // one onwer at a time

    println!("{}", Str2);

    let Str = String::from("Hello, World2!");
    let Str2 = Str.clone(); // deep copy : data, len, capacity, pointer points to this copied data.
                            // it like creating a new String on heap
    println!("{}", Str2);
    println!("{}", Str);

    // data on stack copies one to one, in below example ownership is not transfered
    //    The reason is that types such as arrays that have a known size at compile time are stored entirely on the stack,
    //so copies of the actual values are quick to make. as long as types are premitives and are stored on stack not on heap.
    let arr:[i32;5] = [1, 2, 3, 4, 5];
    let arr2:[i32;5] = arr;
    println!("{:?}", arr);
    println!("{:?}", arr2);


    // functions and ownership
    let Str = String::from("Hello, World2!");
    TransferOwnership(Str);
    //println!("{}", Str);// This is error, because ownership was transfered and the value Str was bind to was dropped
    let NewOwner = SendOwnership();
    println!("{}", NewOwner);
    // peserving onwership with function call
    let mut Str = String::from("Hello, World2!");
    let mut Str = Preserve(Str);
    println!("{:?}", Str);

    // Reference
    // immutable reference
    let mut Str = String::from("New Thing");
    let X = &Str; // immutable reference: only allow to read the memory

    // mutable reference with function
    let mut Str = String::from("Hello, World2!");
    UpdateString(&mut Str); // allow to read or wirte to memory
    println!("{}", Str);
    
    //let mut Str2 = &mut Str; // only one mutable reference is allow on a mutable variable or
    //indefinate amount of immutable references, one thing at a time(mutable or immutable)
//    let mut Str3 = &mut Str;
    //println!("{} {}", Str2, Str3);// error
//    let Str3 = &Str;
    //     println!("{} {}", Str2, Str3); // error
    let Str2 = &Str;
    let Str3 = &Str;
    let Str4 = &Str;

    println!("{}, {}, {}", Str2, Str3, Str4);
    let mut Str = String::from("Hello, World2! mutable");
    let Str5 = TakeAndReturn(&mut Str); // more of like a mutable reference
    println!("{}", Str5);

}

fn TakeAndReturn(Str: &mut String) ->&mut String {
    Str
}

fn UpdateString(Str: &mut String){
    Str.push_str("No No, it's Third");
}
