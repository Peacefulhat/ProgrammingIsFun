const std = @import("std");
const print = std.debug.print;

// comptime 2

// This funciton requires a comptime type parameter
fn typeNameLength(comptime T: type) usize {
    return (@typeName(T).len);
}

// struct with optional fields and impl declaration.
const A = struct {
    a: u8,
    b: ?u8,
    pub fn impl() void {}
};

// struct without optionals field.
const B = struct {
    a: u8,
    b: u8,
};

// using inline for
// if a field at given index is optional.
fn isOptFor(comptime T: type, field_index: usize) bool {
    const fields = @typeInfo(T).Struct.fields;
    inline for (fields, 0..) |field, i| {
        if (field_index == i and @typeInfo(field.type) == .Optional) return (true);
    }
    return (false);
}

// using a swith with inline prong.
fn isOptSwitch(comptime T: type, field_index: usize) bool {
    const fields = @typeInfo(T).Struct.fields;
    return switch (field_index) {
        // ranges in switches are inclusive. that is why fields.len - 1
        inline 0...fields.len - 1 => |idx| @typeInfo(fields[idx].type) == .Optional,
        else => false,
    };
}

// A tagged union with fields.
const U = union(enum) {
    a: A,
    b: B,

    // using inline else to handle all varients in one shot.
    fn hasImpl(self: U) bool {
        return switch (self) {
            inline else => |s| @hasDecl(@TypeOf(s), "impl"),
        };
    }
};
//note fib sum is wrong and currenlty give nth fib number.
fn fibSum(n: u32) u32 {
    // 0, is 0th element.
    if (n < 2) return (n);
    var n_term: u32 = 0;
    var first: u32 = 0;
    var second: u32 = 1;
    var i: u32 = 2;
    while (i <= n) : (i += 1) {
        n_term = first + second;
        first = second;
        second = n_term;
    }
    return (n_term);
}
pub fn main() void {
    // compile time expression evaluation.
    const condition = false;
    print("{}\n", .{@TypeOf(condition)});
    // here condition is known at compile time , so it's evaluated at compile time the if block i mean.
    if (condition) {
        @compileError("what");
    }

    // inline for, gets evaluated at compile time.

    const nums = [_]i32{ 2, 4, 6 };
    var sum: usize = 0;
    // an inline for is unrolled.
    inline for (nums) |num| {
        // a non-inline for can't deal with this types.
        const T = switch (num) {
            2 => f32,
            4 => i8,
            6 => bool,
            else => unreachable,
        };
        sum += typeNameLength(T);
    }

    print("sum: {}\n", .{sum});

    // inline while, gets evaluated at compile time.
    sum = 0;
    // we need a comptime var for the inline while given it's a comptime context.
    comptime var i = 0; // comptime variale declaration.(mutabale variable)
    // an inline while is unrolled.
    inline while (i < 3) : (i += 1) {
        // and can deal with types too.
        const T = switch (i) {
            0 => i32,
            1 => i8,
            2 => f64,
            else => unreachable,
        };
        sum += typeNameLength(T);
    }
    print("sum: {}\n", .{sum});

    const a: U = .{ .a = .{ .a = 0, .b = null } };
    const b: U = .{ .b = .{ .a = 0, .b = 0 } };
    print("a.hasImpl(): {}\n", .{a.hasImpl()});
    print("b.hasImpl(): {}\n", .{b.hasImpl()});
    // runtime normal function.
    print("fibsum: {}\n", .{fibSum(7)});
    // compile time noraml function eval, to make this happen function parameter, variable must be known at compile time.
    const ct_fib = comptime fibSum(7);
    print("comptime fibsum: {}\n", .{ct_fib});
    const ct_fib2 = comptime blk: {
        break :blk fibSum(7);
    };
    print("comptime fibsum: {}\n", .{ct_fib2});
}
