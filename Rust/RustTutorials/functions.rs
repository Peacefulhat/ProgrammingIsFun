// function:
//Rust code uses snake case as the conventional style for function and variable names, in which all letters are lowercase and underscores separate words.
// Rust doesn’t care where you define your functions, only that they’re defined somewhere in a scope that can be seen by the caller.
//Syntax: fn functionName(){ function body}

// statement do not return value; function definnation can be a statement.becasuse if function does
// not return any value then it is a statement.
fn another_function() {
    println!("i'm another function");
}
// parmeters:
fn print_labled_measurment(mut value: i32, unit_lable: char) {
    value = value + 1;
    // here value is mutable variable and unit_lable is immutable.
    println!("the measurment is: {value}{unit_lable}");
}
//Functions with Return Values

//Functions can return values to the code that calls them. We don’t name return values, but we must declare their type after an arrow (->). In Rust, the return value of the function is synonymous with the value of the final expression in the block of the body of a function. You can return early from a function by using the return keyword and specifying a value, but most functions return the last expression implicitly.

fn plus_five(value: i32) -> [i32; 5] {
    let x = [1, 2, 3, value, 5];
    x
    // last exp will be functions return value. if we explicitly cal     return then we to
    // terminate it with semicolone and we dont terminate last expression or expression in general.
}
// calling a function is an expression;
// calling a macro is an expression;
fn main() {
    another_function();
    another_function2();
    print_labled_measurment(5, 'h');
    let x = plus_five(5);
    println!("{0},{1},{2}", x[0], x[3], x[4]);
    let y = {
        let x = 3;
        x + 3
    };
    println!("The value of y is: {0}", y);
}
fn another_function2() {
    println!("i'm another function 2");
}
