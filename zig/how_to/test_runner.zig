const std = @import("std");
const builtin = @import("builtin");

pub fn main() !void {
    for (builtin.test_functions) |t| {
        if (t.func()) |_| {
            std.debug.print("PASS: {s}\n", .{t.name});
        } else |err| switch (err) {
            error.SkipZigTest => {
                std.debug.print("SKIPPED: {s}\n", .{t.name});
            },
            else => {
                std.debug.print("FAIL: {s} ({s})\n", .{ t.name, @errorName(err) });
            },
        }
    }
}
