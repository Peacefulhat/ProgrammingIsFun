const std = @import("std");
const print = std.debug.print;

fn rightTriangle(rows: u8) void {
    for (1..rows + 1) |star| {
        for (1..star + 1) |_| {
            print("* ", .{});
        }
        print("\n", .{});
    }
}

fn for_loop_example() void {
    print("for_loop:\n", .{});
    var array = [_]u8{ 83, 84, 85, 86, 87, 88, 89, 90, 91 };

    // for loops
    // iterate over array
    for (array) |array_value| {
        print("{} ", .{array_value});
    }
    print("\n", .{});

    // iterate over a slice
    for (array[2..5]) |slice_value| {
        print("{} ", .{slice_value});
    }
    print("\n", .{});

    // adding range to have a index
    for (array, 0..) |array_value, index| { // here index will start from 0 and end to 8
        print("index: {}, value: {}\n", .{ index, array_value });
    }
    print("\n", .{});

    // alternate
    for (array, 0..array.len) |array_value, index| { // here index will start from 0 and end to 8
        print("index: {}, value: {}\n", .{ index, array_value });
    }
    print("\n", .{});

    // multi object iteration, all must have same length.
    for (array[0..2], array[1..3], array[2..4]) |a, b, c| {
        print("a: {}, b:{}, c:{}\n", .{ a, b, c });
    }
    print("\n", .{});

    // break and continue
    var array_sum: usize = 0;
    for (array) |item| { // here item is a usize and that is why sum is a usize
        if (item == 85) continue;
        if (item == 87) break;
        array_sum += item;
    }
    print("array_sum: {}\n", .{array_sum});

    // using a lable to break or continue from a nested loop
    var crazy_sum: usize = 0;
    outer: for (0..array.len) |outer_value| {
        inner: for (0..5) |inner_value| {
            if (outer_value == 5) break :outer;
            if (inner_value == 3) continue :inner;
            crazy_sum += outer_value + inner_value;
        }
    }
    print("crazy_sum: {}\n", .{crazy_sum});

    // you can obtain a pointer to the item to modify it.
    // the object must not ba const and you must use a pointer to it.
    // (remember) a slice is also a pointer type.
    for (&array) |*item| { // pointer to the item in array.
        item.* *= 2; // modifying the value .
        print("value: {}, type: {}\n", .{ item.*, @TypeOf(item) });
    }

    // for as an expression with else clause.
    const nums = [_]?u8{ 3, 9, 0, 77, null, null };
    print("nums: {any}\n", .{nums});
    const only_nums = for (nums, 0..) |value, i| {
        if (value == null) break nums[0..i];
    } else nums[0..];
    print("only_nums: {any}\n", .{only_nums}); // else clause and the for loop, must return same type value.

    rightTriangle(10);
}

fn while_loop_example() void {
    print("while_loop:\n", .{});
    // basic while loop
    var index: u8 = 0;
    while (index <= 3) {
        print("{} ", .{index});
        index += 1;
    }
    print("\n", .{});

    // continue experssion
    index = 3;
    while (index <= 10) : (index += 1) {
        print("{} ", .{index});
    }
    print("\n", .{});

    // complex continue experssion
    index = 10;
    var j_index: u8 = 2;
    while (index <= 17) : ({
        index += 1;
        j_index += 2;
    }) {
        print("{} ", .{index + j_index});
    }

    print("\n", .{});
    //break and continue , lables
    index = 0;
    outer: while (true) : (index += 1) {
        while (index < 10) : (index += 1) {
            if (index == 4) continue :outer;
            if (index == 6) break :outer;
            print("{} ", .{index});
        }
    }
    print("\n", .{});

    // while loop as experssion
    const start: u8 = 1;
    const end: u8 = 20;
    index = start;
    const num_in_range: u8 = 20;
    const in_range = while (index <= end) : (index += 1) {
        if (index == num_in_range) break true;
    } else false;
    print("in_range: {}\n", .{in_range});

    // capture with while, work only with onptionals
    count_down = 20;
    print("count_down: \n", .{});
    while (countDown()) |current_count_down_value| {
        print("{} ", .{current_count_down_value});
    } // else {} , if the optional becoms null can do stuff in else clause too.
}

var count_down: u8 = undefined;

fn countDown() ?u8 {
    if (count_down == 0) return null;
    count_down -= 1;
    return (count_down);
}

pub fn main() void {
    while_loop_example();
}
