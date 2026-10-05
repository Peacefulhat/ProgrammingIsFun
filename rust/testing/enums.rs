#![allow(nonstandard_style)]
#![allow(unused)]

#[derive(Debug)]
enum ipaddr_kind {
    V4,
    V6,
}
//we can put data directly into each enum variant.
//This new definition of the IpAddr enum says that both V4 and V6 variants will have associated String values.
//The name of each enum variant that we define also becomes a function that constructs an instance of the enum.
#[derive(Debug)]
enum ipaddr2 {
    V4(String),
    V6(String),
}

// There’s another advantage to using an enum rather than a struct: Each variant can have different types and amounts of associated data.
#[derive(Debug)]
enum ipaddr3 {
    V4(u8, u8, u8, u8),
    V6(String),
}

struct ipv4addr {}

struct ipv6addr {}

enum ipaddr4 {
    V4(ipv4addr),
    V6(ipv4addr),
}

//Note: This code illustrates that you can put any kind of data inside an enum variant: strings, numeric types, or structs, for example. You can even include another enum!

#[derive(Debug)]
//except the enum doesn’t use the struct keyword and all the variants are grouped together under the Message type
enum message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

struct QuitMessage; // unit struct
struct MoveMessage {
    x: i32,
    y: i32,
}
struct WriteMessage(String); // tuple struct
struct ChangeColorMessage(i32, i32, i32); // tuple struct

//But if we used the different structs, each of which has its own type, we couldn’t as easily define a function to take any of these kinds of messages as we could with the Message enum defined,  which is a single type

//Note: We can also define methods similar to struct in enum
impl message {
    fn PrintMsg(&self) {
        println!("{:#?}", self);
        // method body would be defined Here
    }
}

// Option Enum
//The Option type encodes the very common scenario in which a value could be something, or it could be nothing.
//it does have an enum that can encode the concept of a value being present or absent. This enum is Option<T>

/*enum Option<T> {
    None,
    Some(T),
}
 */

//all you need to know is that <T> means that the Some variant of the Option enum can hold one piece of data of any type, and that each concrete type that gets used in place of T makes the overall Option<T> type a different type.

fn main() {
    // Enums: enums give you a way of saying a value is one of a possible set of values.

    // Enum Values
    let VersionFour = ipaddr_kind::V4;
    let VersionSix = ipaddr_kind::V6;
    Route(&VersionSix);
    println!("Ip: {:#?},{:#?}", VersionFour, VersionSix);
    let Home = ipaddr {
        Kind: ipaddr_kind::V4,
        Address: String::from("127.0.0.1"),
    };

    let Loopback = ipaddr {
        Kind: ipaddr_kind::V6,
        Address: String::from("::1"),
    };
    println!("(ipaddr): {:#?}, {:#?}", Home, Loopback);

    // ipaddr2::V4() is a function call that takes a String argument and returns an instance of the IpAddr type. We automatically get this constructor function defined as a result of defining the enum.
    let Home = ipaddr2::V4(String::from("127.0.0.1"));
    let Loopback = ipaddr2::V6(String::from("::1"));
    println!("(ipaddr2): {:#?}, {:#?}", Home, Loopback);

    let Home = ipaddr3::V4(127, 0, 0, 1);
    let Loopback = ipaddr3::V6(String::from("::1"));
    println!("(ipaddr3): {:#?}, {:#?}", Home, Loopback);

    let mut m = message::Write(String::from("hello"));
    m = message::Move { x: 23, y: 24 };
    m.PrintMsg();
    
    let some_number = Option::<i32>::Some(5);
    let some_char = Some('e');
    let absent_number: Option<i32> = None;
    println!("{:#?}, {:#?}, {:#?}", some_number, some_char, absent_number);
    println!("{}", some_number.unwrap() + 23); //pub const fn unwrap(self) -> T returns the contained sum, consuming self.
}

#[derive(Debug)]
struct ipaddr {
    Kind: ipaddr_kind,
    Address: String,
}

fn Route(IpKind: &ipaddr_kind) {}
// Note: In general, in order to use an Option<T> value, you want to have code that will handle each variant. You want some code that will run only when you have a Some(T) value, and this code is allowed to use the inner T. You want some other code to run only if you have a None value, and that code doesn’t have a T value available. The match expression is a control flow construct that does just this when used with enums: It will run different code depending on which variant of the enum it has, and that code can use the data inside the matching value.
