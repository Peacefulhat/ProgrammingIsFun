const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    // block
    {
        const PI: f32 = 3.1415;
        print("PI: {}\n", .{PI});
    }

    // block as an experssion, can return a value.
    // using a 'lable' and 'break'
    const n_sum: i32 = my_block: { // here my_block is a lable
        const end: i32 = 5;
        var sum: i32 = 0;
        var i: i32 = 1;
        for (0..end) |_| {
            sum += i;
            i += 1;
        }
        break :my_block sum; // here we are returing a value from the experssion with break
    };
    print("sum of n natural numbers: {}\n", .{n_sum});

    const state: u8 = 1;
    // switch can be used as experssion also.
    switch (state) {
        0...20 => |current_state| {
            print("state was in between 0 to 20, value was: {}\n", .{current_state});
        },
        else => {
            print("state was in between 20 to 255", .{});
        },
    }
}
