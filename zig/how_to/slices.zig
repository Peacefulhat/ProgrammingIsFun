const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    var array = [_]u8{ 23, 3, 82, 19, 89 };
    // slice, [] is used to create a slice

    var array_slice: []u8 = &array; // or array[3..] or array[0..3] etc.
    array_slice[0] += 33;
    print("{any}\n", .{array_slice});
    array_slice = array[3..];
    print("{any}\n", .{array_slice});

    // slice is multi item pointer  + length.
    print("array_slice_ptr: {*}\narray_slice_ptr: {}\narray_slice_ptr: {}\n", .{ array_slice.ptr, array_slice.len, @TypeOf(array_slice) });

    array_slice.ptr += 1; // pointer arithematics
    array_slice.len -= 1;
    print("array_slice_value: {}\narray_slice_len: {}\n", .{ array_slice[0], array_slice.len });

    array_slice.ptr -= 1; // pointer arithematics, manually updateing the ptr.
    array_slice.len += 1; // manually update the length of slice
    print("array_slice_value: {}\narray_slice_len: {}\n", .{ array_slice[0], array_slice.len });

    // slice of a slice
    const slice_of_array_slice: []u8 = array_slice[1..];
    print("slice_of_array_slice: {any}\n", .{slice_of_array_slice});

    // slice of sentinal array
    var s_array: [5]u8 = .{ 23, 45, 58, 9, 89 };
    s_array[3] = 0;

    const s_array_slice: [:0]u8 = s_array[0..3 :0]; // here zero is the sentinal value.
    print("s_array_slice: {any} ", .{s_array_slice});
    print("{any}\n", .{s_array_slice[3]});
    // Note: we can go from non-const to const, but other way around is not possible.

}
