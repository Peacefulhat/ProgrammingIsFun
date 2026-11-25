const std = @import("std");
const Point = @import("struct2.zig");

// this file and struct2.zig, are used to show how to organise code in different zig file.

pub fn main() void {
    const p1: Point = .{ .x = 3.3, .y = 5.5 };
    const p2 = Point.new(9.9, 8.9);

    std.debug.print("{}\n", .{p1});
    std.debug.print("{}\n", .{p2});
    std.debug.print("{}\n", .{p1.distance(p2)});
    std.debug.print("{}\n", .{Point.distance(p2, p1)});
}
