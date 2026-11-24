const std = @import("std");
const print = std.debug.print;

// enums can have methods, we can specify the type of enum
const Color = enum(u8) {
    RED,
    GREEN,
    BLUE,
    YELLOW,

    fn isRed(self: Color) bool {
        return (self == .RED);
    }
};

// union
const PureColor = union { red: u8, green: u8, blue: u8 };

// tagged unions
fn taggedUnions() void {
    // Note: names of members of enum and unions members should have same name.
    const Values = enum {
        BIG,
        MEDIUM,
        SMALL,
    };

    // tagged unions
    const TaggedUnion = union(Values) {
        BIG: i32,
        MEDIUM: i32,
        SMALL: i32,
    };
    const tvalue: TaggedUnion = .{ .MEDIUM = 10 };
    switch (tvalue) {
        .BIG => |v| print("BIG: {}", .{v}),
        .MEDIUM => |v| print("MEDIUM: {}", .{v}),
        .SMALL => |v| print("SMALL: {}", .{v}),
    }
}
pub fn main() void {
    const color_set: Color = .YELLOW;
    const my_color = .{ .red = 255 };
    print("my_color: {}\n", .{my_color});
    print("color_set: {}\n", .{color_set});
    taggedUnions();
}
