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
    println!("P3: {:?}", p3);

    // Creating Instances with Struct Update Syntax
    let p4 = person {
        Name: String::from("Struct Update"),
        ..p3 // other fields are going to be same as p3
             // instance
    };

    let p4 = person {
        Age: 39,
        ..p3 // other fields are going to be same as p3
             // instance
    };

    println!("P4: {:?}", p4);
    //    println!("P3: {:?}", p3); // p3 is not accesible, its ownership was transfered to p4(heap data, not in stack -> string)
    //partial move occurs because `p3.Name` has type `String`, which does not implement the `Copy` trait

    // Tuple Structs
    // Tuple structs have the added meaning the struct name provides but don’t have names associated with their fields;
    //rather, they just have the types of the fields.
    //Tuple structs are useful when you want to give the whole tuple a name and make the tuple a different type
    //from other tuples, and when naming each field as in a regular struct would be verbose or redundant.

    // Example
    // Tuple Type
    #[derive(Debug)]
    struct color(i32, i32, i32);
    #[derive(Debug)]

    struct point(i32, i32, i32);
    let mut Player = point(23, 24, 35); // argument should be passed in similar order as in Tuple struct
    println!("Player Position: {:?}", Player);

    // unit like structs
    //    Unit-like structs can be useful when you need to implement a trait
    //on some type but don’t have any data that you want to store in the type itself.

    struct AlwaysEqual;
    let Sub = AlwaysEqual;
    // will study in later chapter's

    // area of rectangle
    let Width: u32 = 40;
    let Height: u32 = 50;

    println!(
        "(no grouping): Rectangle Area: {} meters",
        RectArea(&Width, &Height)
    );
    // refactring using tuples

    let Rect: (u32, u32) = (30, 50);
    println!("(tuple): Rectangle Area: {} meters", RectArea2(&Rect));

    // refactring with structs and tuple structs
    let Rectangle1 = rect(20, 50);
    println!(
        "(struct tuple): Rectangle Area: {} meters",
        RectArea3(&Rectangle1)
    );

    let Rectangle2 = rect2 {
        Width: 10,
        Height: 50,
    };
    println!(
        "(struct): Rectangle Area: {} meters",
        RectArea4(&Rectangle2)
    );
    /*Another way to print out a value using the Debug format is to use the dbg! macro, which takes ownership of an expression (as opposed to println!, which takes a reference), prints the file and line number of where that dbg! macro call occurs in your code along with the resultant value of that expression, and returns ownership of the value.

    Note: Calling the dbg! macro prints to the standard error console stream (stderr), as opposed to println!, which prints to the standard output console stream (stdout).*/
    let Rectangle3 = rect2 {
        Width: dbg!(3 * 10),
        Height: 50,
    };
    dbg!(RectArea4(&Rectangle2));

    let Rectangle2 = rect2 {
        Width: 10,
        Height: 50,
    };

    let Rectangle3 = rect2 {
        Width: 50,
        Height: 50,
    };
    println!("(method): Area of Rectangle: {}", Rectangle3.Area());

    // Methods with more parameters
    println!(
        "(method with more parameter): Area of Rectangle: {}",
        Rectangle3.CanHold(&Rectangle2)
    );

    // Associate function
    //All functions defined within an impl block are called associated functions because
    //they’re associated with the type named after the impl. We can define associated functions
    //that don’t have self as their first parameter (and thus are not methods) because they don’t
    //need an instance of the type to work with. We’ve already used one function like this:
    //the String::from function that’s defined on the String type.

    //Associated functions that aren’t methods are often used for constructors
    //that will return a new instance of the struct. These are often called new,
    //but new isn’t a special name and isn’t built into the language.
    let NewRectangle = rect2::New(5, 5); // as a constructor.
    println!("(Associate function): Rectangle: {:?}", NewRectangle);
}

struct rect(u32, u32);

#[derive(Debug)]
struct rect2 {
    Width: u32,
    Height: u32,
}

// Methods
// Unlike functions, methods are defined within the context of a struct (or an enum or a trait object,
// and their first parameter is always self, which represents the instance of the struct the method is being called on.

impl rect2 {
    fn Area(&self) -> u32 {
        self.Width * self.Height
    }

    fn Width(&self) -> bool {
        self.Width > 0
    }

    fn CanHold(&self, Other: &rect2) -> bool {
        self.Width > Other.Width && self.Height > Other.Height
    }

    // associate function // here first parameter is not self
    fn New(Width: u32, Height: u32) -> Self {
        // here Self is the rect2 struct type it self
        Self {
            Width, // struct init shorthand
            Height,
        }
        //The Self keywords in the return type and in the body of the function are aliases for
        //the type that appears after the impl keyword, which in this case is rect2.
    }
}

fn RectArea4(Side: &rect2) -> u32 {
    Side.Width * Side.Height
}

fn RectArea3(Side: &rect) -> u32 {
    Side.0 * Side.1
}

fn RectArea(Width: &u32, Height: &u32) -> u32 {
    Width * Height
}

fn RectArea2(Dim: &(u32, u32)) -> u32 {
    Dim.0 * Dim.1
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

//Note: in the signature for area, we use &self instead of rect: &rect2  The &self is actually short for self: &Self.
//Within an impl block, the type Self is an alias for the type that the impl block is for.(here rect2)
//Methods must have a parameter named self of type Self for their first parameter,
//so Rust lets you abbreviate this with only the name self in the first parameter spot.
//Note that we still need to use the & in front of the self shorthand to indicate that this method borrows the Self instance,
//just as we did in rect: &rect2.
//Methods can take ownership of self, borrow self immutably, as we’ve done here, or borrow self mutably &mut self, just as they can any other parameter.

