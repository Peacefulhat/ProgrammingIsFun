const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    // Arrays
    // 5 byte array with undefined content (stack garbage).
    var my_array: [5]u8 = undefined;
    my_array[0] = 33;
    var my_array2 = [_]u16{ 1, 2, 3, 4 };
    //    var my_array3: [30]u8 = @splat(0); // set value to  0

    // The content is provided by the "foo" function, called at compile-time and
    // allows complex initializations.
    //    var my_array4: [40]u8 = @splat(foo());
    my_array2[2] *= 100;

    // multidimensional arrays
    const mat4x4 = [3][3]f32{
        .{ 1, 2, 3 },
        .{ 4, 5, 6 },
        .{ 7, 8, 9 },
    };

    print("2d array:\n", .{});
    for (mat4x4) |row| {
        for (row) |column| {
            print("{} ", .{column});
        }
        print("\n", .{});
    }
    //    try expect(mat4x4[1][1] == 1.0);

    // sentinal array
    const arra: [2:0]u8 = .{ 1, 2 };
    // in sentinal arrays arr.len is also accesible meaning that will have the sentinal element.
    print("array: {any}\nsentinal: {}\nlength: {}\n", .{ arra, arra[2], arra.len });
}
