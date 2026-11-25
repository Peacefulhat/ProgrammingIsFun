const std = @import("std");
const print = std.debug.print;

// functions
fn add(a: u8, b: u8) u8 {
    return (a + b);
}

// a function that never returns.
fn oops() noreturn {
    @panic("Oops!");
}
// if a function is never called, it isn't even evaluated.

// A 'pub' function can be imported from another namespace;
pub fn sub(a: u8, b: u8) u8 {
    return (a -| b);
}

// An 'extern' fucnton is linked in from an external object file.
extern "c" fn atan2(a: f64, b: f64) f64;

// An export function is made available fro use in the generated object file.
export fn mul(a: u8, b: u8) u8 {
    return (a *| b);
}

// you can force inlining of a function, but usually not necessary.

inline fn add2(a: u8) u8 {
    return (a +| 2);
}

// pass by value or reference
// all passed parameter to the a function is going to be a constant.

// how it may look like const, const n:u8, internally
// by value
fn addOne(n: u8) void {
    // work around with constants
    var d_n: u8 = 0;
    d_n += (n + 1);
    print("{}\n", .{d_n});
}

// by reference,
// how it may look like const, const n: *u8., internally
fn addOneTwo(n: *u8) void {
    n.* += 1 + 2;
}

// recursion
fn fib(n: u8) u8 {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (fib(n - 1) + fib(n - 2));
}

pub fn main() void {
    var u: u8 = 9;
    addOne(u); // things happen inside the function.
    print("u: {}\n", .{u});
    addOneTwo(&u);
    print("u: {}\n", .{u});
    var start: u8 = 0;
    const end: u8 = 12;
    for (0..end) |_| {
        print("{} ", .{fib(start)});
        start += 1;
    }
}
