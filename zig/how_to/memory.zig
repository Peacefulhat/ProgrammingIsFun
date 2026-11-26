const std = @import("std");
const print = std.debug.print;

// memroy section or where the bytes are.

// memory layout of zig program.
// Text (Code) Segment. Stores compiled machine instructions and is typically marked read-only and executable.
// Rodata (Read-Only Data). Holds string literals, compile-time constants (const), and static lookup tables.
// Data & BSS Segments. Stores mutable global and container-level var declarations. Initialized variables live in .data, while zero-initialized variables reside in .bss.
// Heap (Allocator-Managed). Zig has no hidden global heap or default runtime allocator. Dynamic memory is explicitly requested through an std.mem.Allocator interface, which may back allocations via OS pages (page_allocator), arenas (ArenaAllocator), or even a stack-allocated buffer (FixedBufferAllocator).
//Stack. Stores local function variables, return addresses, and call frames. Because Zig does not perform hidden heap allocations, large local arrays stay on the stack unless you explicitly allocate them.

// will be stored in the global constant section(Rodata segment) of the program memory layout.
const pi: f64 = 3.1415;

// will be stored in the global data section && bss segment of the program memory layout.
var count: usize = 0;

fn locals() u8 {
    // all of these local variables are
    // gone once the function exits. They live on the
    // function stack frame.
    const a: u8 = 1;
    const b: u8 = 2;
    const result: u8 = a + b;
    // here a copy of result is returned
    // since it's a primitve numeric type.
    return (result);
}

//fn badIdea() *u8 {
//    var x: u8 = 42;
//    // x live on the stack
//    // invalid pointer once the function returns
//    // and its stack frame is destroyed.
//    return &x;
//}

fn badIdea2() []u8 {
    const array: [5]u8 = .{ 'H', 'e', 'l', 'l', 'o' };
    // remember, a slice is also a pointer.
    const s = array[1..];
    // this is an error since array will be destoryed.
    // when the function returns. 's' will be left dangling.
    return s;
}

// caller must free returned bytes.
fn goodIdea(allocator: std.mem.Allocator) std.mem.Allocator.Error![]u8 {
    var array: [5]u8 = .{ 'H', 'e', 'l', 'l', 'o' };
    // s is []u8 with length 5 and a pointer to bytes on the heap.
    const s = try allocator.alloc(u8, 5);
    std.mem.copy(u8, s, &array);
    // this is ok since 's ' points to bytes allocated on
    // the heap and thus outlives the function's stack frame.
    return s;
}

// take a output variable, returning number of bytes written to it.
fn catOutVarLen(a: []const u8, b: []const u8, out: []u8) usize {

    // make sure we have enough space, (in out)
    std.debug.assert(a.len + b.len <= out.len);
    @memcpy(out[0..a.len], a);
    // need to specify length explicitly.
    @memcpy(out[a.len .. a.len + b.len], b); // start from a.len

    // return number of bytes written.
    return (a.len + b.len);
}

test "catOutVarLen" {
    const hello: []const u8 = "Hello ";
    const world: []const u8 = "world";
    // output buffer.
    var out_buffer: [128]u8 = undefined;
    // write to buffer, get length;
    const len = catOutVarLen(hello, world, &out_buffer);
    try std.testing.expectEqualStrings(hello ++ world, out_buffer[0..len]);
}

// Take an output variable returing a slice from it.
fn catOutVarSlice(a: []const u8, b: []const u8, out: []u8) []u8 {
    // make sure we have enough space, (in out)
    std.debug.assert(a.len + b.len <= out.len);
    @memcpy(out[0..a.len], a);
    @memcpy(out[a.len .. a.len + b.len], b);
    return out[0 .. a.len + b.len];
}

test "catOutVarSlice" {
    const hello: []const u8 = "Hello ";
    const world: []const u8 = "world";
    // output buffer.
    var out_buffer: [128]u8 = undefined;
    // write to buffer, get length;
    const slice = catOutVarSlice(hello, world, &out_buffer);
    try std.testing.expectEqualStrings(hello ++ world, slice);
}

const Exitr = enum { Boom };
fn extes() !void {
    return error.Boom;
}
// take an allocator, return bytes allocated with it. Caller must free the return bytes.
fn catAlloc(allocator: std.mem.Allocator, a: []const u8, b: []const u8) ![]u8 {
    const buffer_len = a.len + b.len;
    const buffer = try allocator.alloc(u8, buffer_len);
    errdefer allocator.free(buffer); // if error happends in this scope the memory will be free and if not it will this line will not run.
    //    try extes();
    //@memcpy(buffer[0..a.len], a);
    //@memcpy(buffer[a.len .. a.len + b.len], b);
    std.mem.copyForwards(u8, buffer[0..], a);
    std.mem.copyForwards(u8, buffer[a.len..], b);
    return buffer;
}

test "catAlloc" {
    const hello: []const u8 = "Hello ";
    const world: []const u8 = "world";
    //  testing memroy allcator.
    const allocator = std.testing.allocator;
    //    const allocator = std.heap.smp_allocator;

    // write to buffer, get length;
    const slice = try catAlloc(allocator, hello, world);
    defer allocator.free(slice);
    try std.testing.expectEqualStrings(hello ++ world, slice);
}

const Foo = struct {
    s: []u8,
    // when a type needs to initialize resource, such as allocating
    // memroy it's convention to do it in a 'init' method.
    fn init(allocator: std.mem.Allocator, s: []const u8) !*Foo {
        // 'create' allocates space on the heap for a single value.
        // It returns a pointer.
        const foo_ptr = try allocator.create(Foo);
        print("foo_ptr: {}\n", .{@TypeOf(foo_ptr)});
        errdefer allocator.destroy(foo_ptr);

        // alloc allocates space on the heap for many values.
        foo_ptr.s = try allocator.alloc(u8, s.len);
        std.mem.copyForwards(u8, foo_ptr.s, s);
        return foo_ptr;
    }

    // when a type needs to clean-up resource, it's convention
    // to do it in a 'deinit' method.
    fn deinit(self: *Foo, allocator: std.mem.Allocator) void {
        // 'free' works on slices allocated with 'alloc'
        allocator.free(self.s);
        // 'destroy' works on pointer allocated with 'create'
        allocator.destroy(self);
    }
};

pub fn main() !void {
    print("Memory!\n", .{});
    const allocator = std.heap.smp_allocator;
    const foo = Foo.init(allocator, "hello") catch unreachable;
    defer foo.deinit(allocator); // free resource
    print("{any}", .{foo.s.len}); // supports auto derefencing

}

// Note:
// defer in zig is block level
// errdefer is used to free the memory which might be leaking because of some error.
