#![allow(nonstandard_style)]
#![allow(unused)]
// Pattern Matching in Rust

//Rust has an extremely powerful control flow construct called match that allows you to compare a value against a series of patterns and then execute code based on which pattern matches

//Patterns can be made up of literal values, variable names, wildcards, and many other things.
//the compiler confirms that all possible cases are handled.

// pattern that binds to values
//Another useful feature of match arms is that they can bind to the parts of the values that match the pattern

//In the match expression for this code,we add a variable called state to
//the pattern that matches values of the variant Coin::Quarter. When a Coin::Quarter matches,
//the state variable will bind to the value of that quarter’s state. Then,
//we can use state in the code for that arm.
#[derive(Debug)]
enum us_state {
    ALABAMA,
    ALASKA,
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
            //the binding for state will be the value UsState::Alaska. beacasue of enum coin.
            let a = 23;
            if a != 23 {
                a - 3
            } else {
                a + 2
            }
        }
    }
}

//The Option<T> match Pattern
fn PlusOne(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1),
    }
}

//Catch-All Patterns and the _ Placeholder

fn PlusOne2(x: Option<i32>) -> Option<i32> {
    //Note: For the last arm(catch-all value) that covers every other possible value, the pattern is the variable we’ve chosen to name other
    match x {
        // other =>    None,  // catch-all value: arm is made using `other` case// here becuse we are returning early, this will cause a panic
        Some(i) => Some(i + 1),
        other => None,
    }
}
// Note:  _ is a special pattern that matches any value and does not bind to that value. This tells Rust we aren’t going to use the value, so Rust won’t warn us about an unused variable.
fn ValueInCents2(Coin: coin) -> u8 {
    match Coin {
        //This seems very similar to a conditional expression used with if, but there’s a big difference:
        //With if, the condition needs to evaluate to a Boolean value, but here it can be any type. The type of coin in this example is the Coin enum that we defined on the first line
        coin::PENNY => 1,
        coin::NICKEL => 5,

        coin::DIME => 10,
        _ => 0, // This will catch all the possibility and return the value here.
        coin::QUARTER(state) => 25, // this is not called because `_`
    }
}

// Matches Are Exhaustive
//Matches in Rust are exhaustive: We must exhaust every last possibility in order for the code to be valid.
//Especially in the case of Option<T>, when Rust prevents us from forgetting to explicitly handle the None case,
//it protects us from assuming that we have a value when we might have null.

fn main() {
    //let x = coin::QUARTER;
    //println!("{}", ValueInCents(x));
    //  Pattern that binds to a value
    let x = coin::QUARTER(us_state::ALASKA);
    let x = coin::DIME;
    println!("{}", ValueInCents2(x));
    let Five = Option::<i32>::Some(5); // option enum
    let Six = PlusOne(Five);
    let none = PlusOne(Option::<i32>::None);

    println!("{}", Six.unwrap());
    println!("{}", none.is_none());

    // if let and let...else
    let ConfigMax = Some(5u8);
    match ConfigMax{
        Some(max) => {
        println!("The maximum is configured to be {max}");
        },
        _ => ()
    }
    //    The syntax if let takes a pattern and an expression separated by an equal sign.
    //However, you lose the exhaustive checking match enforces that ensures that you aren’t forgetting to handle any cases.
    let ConfigMax = Some(3u8);
    if let Some(max) = ConfigMax {
        println!("The maximum is configured to be {max}");
    }
    // We can include an else with an if let. The block of code that goes with the else is
    //the same as the block of code that would go with the _ case in the match expression
    //that is equivalent to the if let and else.
    
    let ConfigMax = Option::<u8>::None;
    if let Some(max) = ConfigMax {
        println!("The maximum is configured to be {max}");
    }else{
        println!("Hello");
    }
}

impl us_state {
    fn ExistedIn(&self, Year: u16) -> bool {
        match self {
            us_state::ALABAMA => Year >= 1819,
            us_state::ALASKA => Year >= 1959,
            _ => false // if state doesn't existed
        }
    }
}

// one way to do this (conditional nested if)
 fn DescribeStateQuarter(Coin: coin) -> Option<String> {
    if let coin::QUARTER(state) = Coin {
        if state.ExistedIn(1900) {
            Some(format!("{state:?} is pretty old, for America!"))
        } else {
            Some(format!("{state:?} is relatively new."))
        }
    } else {
        None
    }
}

// second way to do this(if let)
fn DescribeStateQuarter2(Coin: coin) -> Option<String> {
    let state = if let coin::QUARTER(state) = Coin {
        state
    } else {
        return None;
    };

    if state.ExistedIn(1900) {
        Some(format!("{state:?} is pretty old, for America!"))
    } else {
        Some(format!("{state:?} is relatively new."))
    }
}

//with let..else
//The let...else syntax takes a pattern on the left side and an expression on the right,
//very similar to if let, but it does not have an if branch, only an else branch.
//If the pattern matches, it will bind the value from the pattern in the outer scope.
//If the pattern does not match, the program will flow into the else arm, which must return from the function.

fn DescribeStateQuarter3(Coin: coin) -> Option<String> {
    let coin::QUARTER(state) = Coin else {
        return None;
    };

    if state.ExistedIn(1900) { // why this is state variable is visiblay in this scope, because of `let`.
        Some(format!("{state:?} is pretty old, for America!"))
    } else {
        Some(format!("{state:?} is relatively new."))
    }
}
