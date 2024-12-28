fn fib(value: i8) -> i8 {
    if value == 0 {
        return 0;
    }
    if value == 1 {
        return 1;
    }
    fib(value - 1) + fib(value - 2)
}
fn main() {
    let mut i = 0;
    let mut fibsum = 0;
    loop {
        if i == 8 {
            break;
        }
        fibsum += fib(i);
        i += 1;
    }
    println!("{0}", fibsum);
}
