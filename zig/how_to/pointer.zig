const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    // pointers
    // single item pointer
    const letter_a: u8 = 'a';
    const letter_a_ptr: *const u8 = &letter_a;
    // letter_ptr.* += 1;
    print("letter_a_ptr_address: {}\nletter_a_ptr_value: {c}\nletter_a_ptr_type: {}\n", .{ letter_a_ptr, letter_a_ptr.*, @TypeOf(letter_a_ptr) });

    var letter_b: u8 = 'b';
    const letter_b_ptr: *u8 = &letter_b;
    letter_b_ptr.* += 1;
    print("letter_b_ptr_address: {}\nletter_b_ptr_value: {c}\nletter_b_ptr_type: {}\n", .{ letter_b_ptr, letter_b_ptr.*, @TypeOf(letter_b_ptr) });

    // multi-item pointer
    var array = [_]u8{ 18, 28, 32, 43, 50, 26 };
    var array_ptr: [*]u8 = &array; // this is like only pointer to the first element without length.
    print("array_ptr_type: {any}\n", .{@TypeOf(array_ptr)});
    print("array: {any}\n", .{array});
    array_ptr[0] += 30;
    array_ptr += 1; // moving the address by 1.
    print("array_ptr: {any}\n", .{array_ptr[0]});
    array_ptr -= 1; // the address sub by 1.
    print("array_ptr: {any}\n", .{array_ptr[0]});
    print("array: {any}\n", .{array});

    // pointer to array;
    var array2 = [_]u8{ 18, 28, 32, 43, 50, 26 };
    const arr_ptr = &array2; // this gives pointer to the first element with length.
    print("arr_ptr_type: {any}, arr_ptr_len: {}\n", .{ @TypeOf(arr_ptr), arr_ptr.len });

    // pointer to sentinal array
    array2[3] = 0; // setting the sentinal value
    const s_ptr: [*:0]u8 = array2[0..3 :0];
    print("s_ptr_type: {any}\n", .{@TypeOf(s_ptr)});
    // Note: if you want a pointer to point to null use and 'optional pointer' instead.
}
