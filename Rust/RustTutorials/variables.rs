//variables and mutability.
// by default variables are immutable
// once a value is bounded the variable you can not change its value.
// const variable: main difference between const variable and immutable variable is that const
// variable get evaluated in complie time and immutable variable get evaluated in run time.
const PI: f64 = 3.14159;
fn main() {
    // immutable varialbe.
    println!("immutable varable");
    let x = 23;
    println!("{x}");
    // mutabe variable.
    println!("");
    println!("mutable variable");
    let mut y = 23; // mut variable allows change of value.
    println!("before: {y}");
    y = 27;
    println!("after: {y}");
    println!("");
    // shadowing : with this we can define varible with same name in
    // same scope.
    // when we define the the variable with same name as previous one   it means that the previous
    // variable in now not visible to compiler and new one is visible    in a sense the previous
    // variable is shadowed by new one.
    println!("shadowing");
    let z = 1234;
    println!("{z}");
    let z = 23.324;
    println!("{z}");
    let z = true;
    println!("{z}");
    let z = "hello";
    println!("{z}");
    println!("");
    println!("constant");
    println!("{PI}");
}
