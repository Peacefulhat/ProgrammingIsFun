const std = @import("std");
const print = std.debug.print;
const testing = std.testing;

// this will tell the test runner to test the test in the imported files also
// test {
//     _ = @import("tests2.zig"); // this is a made up file name, assuming it has some test defined.
// }

// note: no name test will always run.
// test filter can be use to specifiy which test to run or not.
fn add(a: i32, b: i32) i32 {
    return (a +% b);
}

// put you test close to what they're testing
test "basic add functionality" {
    //
    try testing.expect(add(2, 3) == 5);
}

fn sub(a: i32, b: i32) i32 {
    return (a -% b);
}

const skip_flag = true;
test "basic sub functionality" {
    // this is how you can skip the test, also look inside the test_runner.zig file for more info.
    if (skip_flag) return error.SkipZigTest;
    try testing.expect(sub(2, 3) == -1);
}

const Foo = struct {
    a: bool,
    b: u8,
    c: []const usize,
    d: []const u8,
    fn new(flag: bool) Foo {
        return if (flag) .{ .a = true, .b = 1, .c = &[_]usize{ 1, 2, 3 }, .d = "Hello" } else .{ .a = false, .b = 0, .c = &[_]usize{ 4, 5, 6 }, .d = "Bye" };
    }

    // you can have tests inside any container.
    test "Inside Foo" {
        try testing.expect(true);
    }
};

test "new Foo: true" {
    // std.testing hasd many useful 'expect' function.
    const foo = Foo.new(true);
    try testing.expect(foo.a);
    try testing.expectEqual(@as(u8, 1), foo.b);
    try testing.expectEqualSlices(usize, &[_]usize{
        1,
        2,
        3,
    }, foo.c);
    try testing.expectEqualStrings("Hello", foo.d);
}

const Error = error{Boom};

fn harmless() Error!void {
    return error.Boom;
}

// you can test for sepecific error
test "explosive error" {
    try testing.expectError(error.Boom, harmless());
}

pub fn main() !void {}
