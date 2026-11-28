const std = @import("std");
const print = std.debug.print;
// typles
pub fn main() void {
    // creating a tuple
    const tuple_a: struct { u8, bool } = .{ 78, true };
    print("tuple: {any}, type: {any}\n", .{ tuple_a, @TypeOf(tuple_a) });
    // acessing a tuple members with index.
    print("tuple_a.@\"0\": {}, tuple_a.bool: {}, tupel_a.len: {}\n", .{ tuple_a[0], tuple_a[1], tuple_a.len });
    // accesing a tuple member with fields with @""
    print("tuple_a.u8: {}\n", .{tuple_a.@"0"});

    // side note
    // @ can be used to define any type of identifiers, even reserved words, numbers etc
    // example: const @"while" = 23;
    // _ = @"while"; etc.

    // concatinating tuples.
    const tuple_b: struct { f16, i32 } = .{ 3.14, -42 };
    const tuple_c = tuple_a ++ tuple_b;
    print("tuple_c: {any}, type: {any}\n", .{ tuple_c, @TypeOf(tuple_c) });

    // pointer to a tuple
    const tuple_ptr = &tuple_c;
    print("tuple_ptr: {any}, type: {any}\n", .{ tuple_ptr[0], @TypeOf(tuple_ptr) });

    // iterating on tuple, Note: tuple field index must be known at comptime.
    // that why using inline to evaluete(unroll) the for at comptime
    inline for (0..tuple_a.len) |tuple_index| {
        print("tuple_a.{}: {}\n", .{ @TypeOf(tuple_a[tuple_index]), tuple_a[tuple_index] });
    }
    varArgs(tuple_a);
}

fn varArgs(x: anytype) void {
    const var_info = @typeInfo(@TypeOf(x));
    if (var_info != .@"struct") @panic("not a tuple");
    if (!var_info.@"struct".is_tuple) @panic("not a tuple");
    print("x: ", .{});
    inline for (x) |field| {
        print("{} ", .{field});
    }
}
