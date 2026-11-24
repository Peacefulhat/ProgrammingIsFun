const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    // bool
    var is_door_open: bool = false;
    is_door_open = !is_door_open;
    print("is_door_open: {}\n", .{is_door_open});

    // optional: provide null safty.
    // in zig, a value can be null, if its optional.
    const byte: ?u8 = 233;
    const is_byte_set: u8 = byte orelse 0; // if the value is null we can set the value to some thing wit 'orelse'.
    print("is_byte_set: {}\n", .{is_byte_set});

    if (byte) |captured_byte| {
        print("byte: {}\n", .{captured_byte});
    } else {
        print("byte: {any}\n", .{byte});
    }

    // Note: only optionals are allowed to be compared with null.

    // if as an experssion, curly braces are not allowed;
    const the_byte = if (byte) |b| b else 0;
    print("the_byte: {}\n", .{the_byte});
}
