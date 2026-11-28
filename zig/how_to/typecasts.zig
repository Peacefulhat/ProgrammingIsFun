const std = @import("std");
const print = std.debug.print;

fn add(a: u8, b: u16) u32 {
    return (a + b);
}
pub fn main() !void {
    //    Type coercion is the automatic or implicit conversion of a value from one data type to another by a programming language
    // coercion only happen when it's safe to do so.
    const a: u8 = 42;
    const b: u16 = a;
    const c: u32 = b;
    const d: u64 = c;
    const e: u128 = d;
    print("u8... u128: (value: {} type: {})\n", .{ e, @TypeOf(e) });

    const f: f16 = 3.1415;
    const g: f32 = f;
    const h: f64 = g;
    const i: f80 = h;
    const j: f128 = i;
    print("f16... f128: (value: {} type: {})\n", .{ j, @TypeOf(j) });
    // function call args coercion.
    const a_u8: u8 = 38;
    const a_result = add(a_u8, a_u8);
    print("result: {}\n", .{a_result});

    // safe narrowing comptime known value.
    const b_u64: u64 = 2000;
    const b_result = add(a_u8, b_u64);
    print("result: {}\n", .{b_result});

    // coercion in pointer
    const array = [_]u8{ 1, 2, 3 };
    const b_slice: []const u8 = &array;
    const c_ptr: [*]const u8 = &array;
    _ = c_ptr;

    // coercion in optionals
    var a_optional: ?u8 = null;
    a_optional = a_u8;

    // coercion in error unions
    var a_err: anyerror!u8 = error.InvalidNumber;
    a_err = a_u8;

    // peer type coercion resolution requires all barnches to coerce to a common type.
    const runtime_zero: usize = 0;
    const happy_medium = if (runtime_zero != 0) a else f;
    print("{} {}\n", .{ happy_medium, @TypeOf(happy_medium) });

    const k: u8 = @intFromFloat(f);
    print("{}\n", .{k});
    const l: f16 = @floatFromInt(c);
    print("{}\n", .{l});

    // you can cast pointer too
    const d_ptr: [*]const u8 = @ptrCast(b_slice); // length information is lost here
    print("{any}\n", .{d_ptr});

    // you can even re-interpret the bits of a value of one type
    // as another type without chainging those bits.

    const float: f64 = 3.141592;
    const bits: u64 = @bitCast(float);
    const as_u64: u64 = @intFromFloat(float);
    const as_f64: f64 = @bitCast(bits);
    print("bitcast: float to u64: {}\n", .{bits});
    print("as_u64: {}\n", .{as_u64});
    print("as_f64: {}\n", .{as_f64});

    // Narrowing int cast. if acceptable you can truncate bits.
    const big_int: u64 = 2000;
    const litte_int: u8 = @truncate(big_int);
    print("{}\n", .{litte_int});
}
