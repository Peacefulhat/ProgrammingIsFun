#![allow(nonstandard_style)]
#![allow(unused)]

#[derive(Debug)]
// struct
struct person {
    Name: String, // these members are called fields
    Age: u32,
}

fn main() {
    // instace of the struct
    /* We create an instance by stating the name of the struct and then add curly brackets containing key: value pairs, where the keys are the names of the fields and the values are the data we want to store in those fields. We don’t have to specify the fields in the same order in which we declared them in the struct.
     */

    let p = person {
        Name: String::from("Hello"),
        Age: 23,
    };
    println!("{:?}", p);
    // Accesing the fields with fields name.
    println!("[Name: {}, Age: {}]", p.Name, p.Age);
    //Note that the entire instance must be mutable; Rust doesn’t allow us to mark only certain fields as mutable.
    //p.Name = String::from("world");// error
    let mut p = person {
        Name: String::from("Hello"),
        Age: 23,
    };

    p.Name = String::from("World");
    println!("[Name: {}]", p.Name);
    let mut p2 = Construct(String::from("Person2"), 25);
    println!("[Name: {}, Age: {}]", p2.Name, p2.Age);
    p2.Name = String::from("Hello, Person2");
    println!("[Name: {}]", p2.Name);
    let p3 = Construct2(String::from("n3ew"), 38);
    println!("{:?}", p3);

    // Creating Instances with Struct Update Syntax
    let p4 = person {
        Name: String::from("Struct Update"),
        ..p3 // other fields are going to be same as p3
            // instance
    };
    println!("{:?}", p4);
}

// returning struct constructed struct from function
fn Construct(NewName: String, NewAge: u32) -> person {
    person {
        Name: NewName,
        Age: NewAge,
    }
}

// using the field init shorthand
//Because the email field and the email parameter have the same name, we only need to write email rather than email: email.

fn Construct2(Name: String, Age: u32) -> person {
    person { Name, Age }
}
