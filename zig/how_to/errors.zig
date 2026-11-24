const std = @import("std");
const print = std.debug.print;

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

pub fn main() void {
    error_example();
}
