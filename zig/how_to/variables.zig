const std = @import("std");
const print = std.debug.print;

// Basic style guide.
// snake_case for variable names (mutable and immutable).
// camalCase for function names.
// PascaleCase for enums, unions, structs etc.

// global variable
const letter_A: u8 = 65; // const - immutable variable.
var vowel: u8 = 70;

fn funcAddOne(a: i32) i32 {
    return (a + 1);
}

pub fn main() void {
    vowel = 73;
    const PI = 3.141; // type not defined by us,and compiler will give it a comptime type.
    const garbage: u8 = undefined; // undefined: gives some garbage to the variable.
    print("garbage: {any}\n", .{garbage});
    print("letter_A: {}, vowel: {}\n", .{ letter_A, vowel });
    print("PI Type: {}\n", .{@TypeOf(PI)});
    print("funcAddOne: {}\n", .{funcAddOne(3)});
    const one_billion = 1_000_000_000;
    const binary_mask = 0b1_1111_1111;
    const permissions = 0o7_5_5;
    const big_address = 0xFF80_0000_0000_0000;
    print("one_billion: {}\n", .{one_billion});
    print("binary_mask: {b}\n", .{binary_mask});
    print("permissions: {o}\n", .{permissions});
    print("big_address: {x}\n", .{big_address});
    const sig_num: f32 = 123e+10; // e or E for exponent
    const sig_num2: f32 = 123.3E-10;
    const sig_num3: f32 = 0x103p-10; // p or P for hex exponent
    print("sig_num: {}\n", .{sig_num});
    print("sig_num2: {}\n", .{sig_num2});
    print("sig_num3: {x}\n", .{sig_num3});
    _ = std.math.inf(f64); // positive infinity
    _ = std.math.inf(f64); // negative infinity
    _ = std.math.nan(f64); // non a number

}
