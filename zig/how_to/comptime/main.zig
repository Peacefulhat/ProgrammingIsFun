const std = @import("std");
//const Point = @import("Point.zig").Point(f32);
const Point = @import("Point.zig").Point;

pub fn main() void {
    {
        const P = Point(i32); // alias for Point function
        const p1 = P.new(5, 5);
        const p2 = P.new(3, 3);

        std.debug.print("{}\n", .{p1});
        std.debug.print("{}\n", .{p2});
        std.debug.print("{}\n", .{p1.distance(p2)});
        std.debug.print("{}\n", .{P.distance(p2, p1)});
    }
}
