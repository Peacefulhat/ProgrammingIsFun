const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    // A string literal is a const pointer to a sentinel terminated array.
    // the sentinel is 0 also know as the null character in c.
    // The array's bytes are included as part of the generated binary file.

    const hello = "hello"; // string literal
    print("type_of_hello: {any}\nsentinel_element: {any}\n", .{ @TypeOf(hello), hello[hello.len] });

    // when you need a more general type for strings in zig,
    // you'll use a slice of bytes, either [] const u8, []u8

    // indexing into a string produces inividual bytes.
    //    print("hello[2]: {0c}, hello[1]: {1c} \n", .{ hello[2], hello[1] });
    print("hello[2]: {0c}, hello[2]: {0any} \n", .{hello[2]}); // 0 is like the argument postion in the passed tuple.
    // all zig source code is encode as utf-8, but strings can contain non-utf-8 using '\x' syntax.
    // Note we can conerce a literal into a slice of bytes.
    var hello_acute: []const u8 = "h\xe9llo";
    print("{any}", .{hello_acute});
    hello_acute = "h\u{e9}llo"; // unicode syntax.
    print("{s}\n", .{hello_acute});

    // multi line string, don't process escape sequences.
    const multiline =
        \\This is a multiline
        \\string in zig . this \n
        \\will not be processed
    ;
    print("{s}\n", .{multiline});
    // There are no characters in zig.
    // A unicode code point literal is specified with using single quotes.
    const bolt: u21 = 'h'; // u21 provides all the character for langauges.
    // currenlty on my devie utf-8 character are not rendering so for now im using 'h' as replacement.
    print("{u}", .{bolt}); // u is for unicode printing

    //std.unicode provides function fro handling unicode text.
    // std.ascii provides fucntion for handling ASCII text.
}
