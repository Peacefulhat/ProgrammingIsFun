#![allow(nonstandard_style)]
#![allow(unused)]
// Pattern Matching in Rust

//Rust has an extremely powerful control flow construct called match that allows you to compare a value against a series of patterns and then execute code based on which pattern matches

//Patterns can be made up of literal values, variable names, wildcards, and many other things.
//the compiler confirms that all possible cases are handled.
#[derive(Debug)]
enum us_state{
    ALABAMA,
    ALASKA
}

#[derive(Debug)]
enum coin {
    PENNY,
    NICKEL,
    DIME,
    QUARTER(us_state),
}


fn ValueInCents(Coin: coin) -> u8 {
    match Coin {
        //This seems very similar to a conditional expression used with if, but there’s a big difference:
        //With if, the condition needs to evaluate to a Boolean value, but here it can be any type. The type of coin in this example is the Coin enum that we defined on the first line
        coin::PENNY => 1,
        coin::NICKEL => 5,
        coin::DIME => 10,
        coin::QUARTER(state) => {
            let a = 23;
            if a != 23 {
                a - 3
            } else {
                a + 2
            }
        }
    }
}

fn main() {
    //let x = coin::QUARTER;
    //println!("{}", ValueInCents(x));
   //  Pattern that binds to a value
    let x = coin::QUARTER(us_state::ALASKA);
    
}
