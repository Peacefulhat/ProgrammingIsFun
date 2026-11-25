const std = @import("std");
const print = std.debug.print;

// error set: error sets are like enums with but they are only dedicated for errors.
const InputError = error{EmptyInput};

// error set can be merged togther with '||' symbol
const ParseError = InputError || std.fmt.ParseIntError;

// the return type of this function is error union using the '!' symbol
// error union is basicaly union of error set and the other return type after '!' symbol.
fn parseNumber(str: []const u8) ParseError!u8 {
    if (str.len == 0) return error.EmptyInput;
    return std.fmt.parseInt(u8, str, 10);
}

fn sliceAreTheSame(a: []const u8, b: []const u8) bool {
    if (a.len != b.len) {
        return false;
    }

    for (0..a.len) |index| {
        if (a[index] != b[index]) {
            return false;
        }
    }
    return true;
}
// errors in zig
const HttpStatus = error{
    OK,
    BAD_REQUEST,
    UN_AUTHORIZED,
    PAYMENT_REQUIRED,
    FORBIDDEN,
    NOT_FOUND,
    METHOD_NOT_ALLOWED,
    NOT_ACCEPTABLE,
    REQUEST_TIMEOUT,
    INTERNAL_SERVER_ERROR,
};

const valid_address: [3][]const u8 = .{ "www.example.com", "www.google.com", "www.bbc.com" };

fn openPage(page_url: []const u8) ![]const u8 { // ! [] const u8 is like union of error enum and the return value.
    for (valid_address) |valid_url| {
        if (sliceAreTheSame(page_url, valid_url)) {
            return ("Page Here");
        }
    }
    return (HttpStatus.NOT_FOUND);
}

fn openPages() void {
    const webpage_list: [4][]const u8 = .{ "www.example.com", "www.google.com", "www.bbc.com", "www.ziglang.org" };

    for (webpage_list) |page| {
        print("Opeaning: {s}\n", .{page});
        _ = openPage(page) catch |status_error| {
            print("\tStatus: {any}\n", .{status_error});
        };
    }
}

fn openPagesTry() !void {
    const webpage_list: [4][]const u8 = .{ "www.example.com", "www.google.com", "www.bbc.com", "www.ziglang.org" };

    for (webpage_list) |page| {
        print("Opeaning: {s}\n", .{page});
        _ = try openPage(page); // what try does is, if it encounters an error, return it else don't do anything
    }
    print("no errors\n", .{});
}

const MulError = error{MUL_BY_ZERO};
fn mult(a: i32, b: i32) !i32 {
    if (b == 0) {
        return (MulError.MUL_BY_ZERO);
    }
    return a * b;
}

fn error_example() void {
    // catch only works with error union type.
    openPagesTry() catch |error_status| {
        print("\tStatus: {any}\n", .{error_status});
    };
    const mul_result = mult(3, 0) catch 0; // here in catch 0; we are setting if there is an error set the value to 0 with catch.
    print("mul_result: {}\n", .{mul_result});

    // with if and payload capture
    const mul_result2 = mult(3, 2);
    if (mul_result2) |mul_res| {
        print("mul_res: {any}\n", .{mul_res});
    } else |error_mul| {
        print("error: {any}\n", .{error_mul});
    }
}

pub fn main() ParseError!void {
    const input = "383";
    var result = parseNumber(input);
    print("{}\n", .{@TypeOf(result)});
    print("{any}\n", .{result});

    // catch, catch can be used to catch the payload of error union.
    // you can use 'catch' to provide a default error.
    result = parseNumber(input) catch 42; // if error happens put 42 in the result.

    // you can use 'catch' with 'switch' to handle each type of error.
    result = parseNumber(input) catch |err| switch (err) {
        error.EmptyInput => blk1: {
            print("Empty input is not allowed\n", .{});
            break :blk1 42; // if input was empty the put default value 42.
        },
        error.Overflow => blk2: {
            print("overflow happened\n", .{});
            break :blk2 0; // if input was empty the put default value 42.
        },
        else => |e| {
            return e;
        },
    };

    // you can use 'catch' with 'unreachable' to ignore the error if its' never going to happen.
    result = parseNumber("23") catch unreachable;
    result = parseNumber("238");
    // you can use 'catch' to propagate the error to the caller.
    //    result = parseNumber("282") catch |err| return err; in this case we will return with the caught error when we exit the main.
    //     'try' is shorcut for keyword for this error catch.
    //    result = try parseNumber("283");

    // Note: if can handle error union, optionals, boolean.
    if (result) |value| { // on success we will have value.
        print("value: {}\n", .{value});
    } else |err| { // on failure we will get error.
        switch (err) {
            error.Overflow => print("overflow is not allowed\n", .{}),
            else => print("something went wrong\n", .{}),
        }
    }
    // Note: while can work with error unions smiliar to optionals.
    // 'anyerror' keyword , (example: anyerror!u8, or !u8), can be used to return any kind of error.
}
