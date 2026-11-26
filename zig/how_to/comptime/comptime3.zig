const std = @import("std");
const print = std.debug.print;

// anytype

const A = struct {
    pub fn toString(_: A) []const u8 {
        return ("A");
    }
};

const C = struct {
    const toString: []const u8 = "C";
};

const D = enum {
    a,
    d,
    pub fn toString(self: D) []const u8 {
        return (@tagName(self));
    }
};

// type reflection : lets a program inspect and modify its own types, structure, and behavior at runtime
// in this case some thing at compile time
// anytype, will accept practacly anthing that you pass in
fn pPrint(x: anytype) void {
    const T = @TypeOf(x);
    // Do we have a "toString declaration";

    if (!@hasDecl(T, "toString")) return;

    // is it a function?
    const decl_type = @TypeOf(@field(T, "toString"));

    if (@typeInfo(decl_type) != .@"fn") return;

    print("{s}\n", .{x.toString()});
}

pub fn main() void {
    const a = A{};
    const c = C{};
    const d = D.d;

    pPrint(a);
    pPrint(c);
    pPrint(d);
}
