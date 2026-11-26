const std = @import("std");
const print = std.debug.print;

fn catAlloc(allocator: std.mem.Allocator, a: []const u8, b: []const u8) ![]u8 {
    const buffer_len = a.len + b.len;
    const buffer = try allocator.alloc(u8, buffer_len);
    errdefer allocator.free(buffer);
    std.mem.copyForwards(u8, buffer[0..], a);
    std.mem.copyForwards(u8, buffer[a.len..], b);
    return buffer;
}

test "catAlloc" {
    const hello: []const u8 = "Hello ";
    const world: []const u8 = "world";
    const allocator = std.testing.allocator;
    const slice = try catAlloc(allocator, hello, world);
    defer allocator.free(slice);
    try std.testing.expectEqualStrings(hello ++ world, slice);
}

fn sliceOfAlloc(allocator: std.mem.Allocator, item: anytype, n: usize) ![]@TypeOf(item) {
    const slice = try allocator.alloc(@TypeOf(item), n);
    @memset(slice, item);
    return slice;
}

const Foo = struct {
    a: u8 = 42,
    b: []const u8 = "Hello, World!",
};
pub fn main() !void {
    // fixed buffer allocator

    // if we know the required memory size in advance, we can create
    // a fixed size array for it as a buffer.
    var buffer: [12]u8 = undefined;
    // and then  use that buffer as the backing-store for a fixedbufferallocator.

    var fba = std.heap.FixedBufferAllocator.init(&buffer); // need a slice to u8
    const allocator = fba.allocator();
    const hello: []const u8 = "Hello ";
    const world: []const u8 = "world";
    const result = catAlloc(allocator, hello, world) catch unreachable;
    print("result: {s}\n", .{result});

    const foo = Foo{};
    const n = 2;
    //    var buffer2: [n * @sizeOf(Foo)]u8 = undefined;
    var buffer2: [n * @sizeOf(Foo) + @alignOf(Foo)]u8 = undefined; // always align things
    //must satisfy both when allocating.
    var fba2 = std.heap.FixedBufferAllocator.init(&buffer2); // need a slice to u8
    const allocator2 = fba2.allocator();

    const result2 = try sliceOfAlloc(allocator2, foo, n);
    print("{any}", .{(result2[0].b)});
}
