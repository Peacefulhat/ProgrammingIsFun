const std = @import("std");
const print = std.debug.print;

//struct: member + methods
// all struct are anonymous struct in zig
// you can have declartion inside struct like varibale name, const
// functions (or may be other structs i don't know)etc, that case the struct is called namespace.

//define a struct
const Point = struct {
    x: f32,
    y: f32 = 0,

    // namespace function (first parameter is not self(in this case not Point struct))
    fn new(x: f32, y: f32) Point {

        // anonymous struct literal
        return .{ .x = x, .y = y };
    }
    // methods
    fn distance(self: Point, other: Point) f32 {
        const diff_x = other.x - self.x;
        const diff_y = other.y - self.y;
        return @sqrt(diff_x * diff_x + diff_y * diff_y);
    }
};

// struct can have declarations and no fields at all.
// it has no fields, it's basically just a namespace.
const NameSpace = struct {
    const pi: f64 = 3.141592;
    var count: usize = 0;
};

pub fn main() void {
    // anonymous struct lieteral. y omitted since it has default value.
    const p1: Point = .{ .x = 0 };

    // using namespace function
    var p2 = Point.new(2.3, 5.4);
    // using method syntax
    print("{}\n", .{p1.distance(p2)});
    p2.y = 9.3;
    // using namespace function syntax
    print("{}\n", .{Point.distance(p1, p2)});

    // a namespace function with no fields have size zero;
    print("size of Point: {}\n", .{@sizeOf(Point)});
    print("size of Namespace: {}\n", .{@sizeOf(NameSpace)});

    // @fieldParentPtr() demo
    // if you have the address of the field of struct you can get the adress to the struct it self
    var p3 = Point.new(3.3, 11.2);
    setYBasedOnX(&p3.x, 33);
    print("p3.y: {}\n", .{p3.y});

    // pointer to struct
    const p3_ptr: *Point = &p3;
    // the dot operator de-reference a pointer to a struct automatically.
    // when accessing fields or calling methods
    p3_ptr.x = 4.4;
    print("p3.x: {}\n", .{p3.x});

    // struct filed order is determined by the compiler for optimal performace.
    // however, you can still calculate a struct base pointer given a field pointer.
}

fn setYBasedOnX(x: *f32, y: f32) void {
    // need to explictly define type, here it's *Point.
    const temp_point: *Point = @fieldParentPtr("x", x);
    temp_point.y = y;
}
