const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    var array = [_]u8{ 23, 3, 82, 19, 89 };
    // slice, [] is used to create a slice
    // slice is pointer to first element + length (not sure if its like c (pointer to the first element)).

    var array_slice: []u8 = &array; // or array[3..] or array[0..3] etc.
    print("{any}\n", .{array_slice});
    array_slice = array[3..];
    print("{any}\n", .{array_slice});
}
