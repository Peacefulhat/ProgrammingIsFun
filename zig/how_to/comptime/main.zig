const std = @import("std");
//const Point = @import("Point.zig").Point(f32);
const Point = @import("Point.zig");
const Point2D = Point.Point2D;
const Point3D = Point.Point3D;

pub fn main() void {
    // Point2D struct
    {
        const P = Point2D(i32); // alias for Point function
        const p1 = P.new(5, 5);
        const p2 = P.new(3, 3);

        std.debug.print("{}\n", .{p1});
        std.debug.print("{}\n", .{p2});
        std.debug.print("{}\n", .{p1.distance(p2)});
        std.debug.print("{}\n", .{P.distance(p2, p1)});
    }

    // Point2D struct
    {
        const P = Point3D(f32); // alias for Point function
        const p1 = P.new(5.2, 5.3, 3.9);
        const p2 = P.new(3.2, 3.3, 3.9);

        std.debug.print("{}\n", .{p1});
        std.debug.print("{}\n", .{p2});
        std.debug.print("{}\n", .{p1.distance(p2)});
        std.debug.print("{}\n", .{P.distance(p2, p1)});
    }
}
