const std = @import("std");
const print = std.debug.print;

pub fn main(init: std.process.Init) !void {
    // stdout is for the actual output of your application.
    // if you are implementing gzip, then only the compressed bytes should be sent to
    // stdot, not any debuggin message.

    const io = init.io;

    // Get a File for standard out, then create a
    // File.Writer and get its Io.Writer.
    var buffer: [4096]u8 = undefined;
    var writer = std.Io.File.stdout().writerStreaming(
        io,
        &buffer,
    );
    var stdout = &writer.interface;
    // format specifer this that go in '{}'symbol
    // {[argument][specifier]:{fill}{alignment}{width}.[precision]}
    try stdout.writeAll("Hello, world!\n");
    try stdout.print("A number: {d:.2}\n", .{3.14159});
    try stdout.print("Run `zig build test` to run the tests.\n\n", .{});

    // All printing functions take a comptime format string that can
    // contain placeholders for arguments to print. These placeholders
    // are called format specifiers and have the form:
    // `{[argument][specifier]:[fill][alignment][width].[precision]}`
    const float: f64 = 3.1415;
    try stdout.print("float: `{}` `{0d}`, `{0d:0<10.2}` `{0d:0^10.2}` `{0d:0>10.2}`  \n\n", .{float});

    // Integers can formatted as decimal, binary, hex, octal, ASCII, or Unicode.
    const int: u8 = 42;
    try stdout.print("int decimal: {} \n", .{int});
    try stdout.print("int binary: {b} \n", .{int});
    try stdout.print("int octal: {o} \n", .{int});
    try stdout.print("int hex: {x} \n", .{int});
    try stdout.print("int ASCII: {c} \n", .{int}); // max 8 bits
    try stdout.print("int Unicode: {u} \n\n", .{int}); // max 21 bits

    // Works for anything that can be sliced.
    const string = "Hello, world!";
    try stdout.print("string: `{s}` `{0s:_^20}` \n\n", .{string});

    const optional: ?u8 = 42;
    try stdout.print("optional: `{?}` `{?}` \n", .{ optional, @as(?u8, null) });
    // You can further format after the ?.
    try stdout.print("optional: `{?d:0>10}` \n\n", .{optional});

    const error_union: anyerror!u8 = error.WrongNumber;
    try stdout.print("error union: `{!}` `{!}` \n", .{ error_union, @as(anyerror!u8, 13) });
    // You can further format after the !.
    try stdout.print("error union: `{!d:0>10}` \n\n", .{@as(anyerror!u8, 13)});

    // Don’t forget to flush!
    try writer.flush();
}
