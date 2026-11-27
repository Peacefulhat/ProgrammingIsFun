const std = @import("std");
const Io = std.Io;
const print = std.debug.print;

// generic linked list that use the provided alocator.
pub fn List(comptime T: type) type {
    return struct {
        const Node = struct {
            allocator: std.mem.Allocator,
            data: T,
            next: ?*Node,

            fn init(allocator: std.mem.Allocator, data: T) !*Node {
                const node = try allocator.create(Node);
                node.allocator = allocator;
                node.data = data;
                node.next = null;
                return node;
            }

            fn deinit(self: *Node) void { // recursive call.
                if (self.next) |ptr| ptr.deinit();
                self.allocator.destroy(self);
            }
        };
        const Self = @This();
        allocator: std.mem.Allocator,
        head: ?*Node,
        pub fn init(allocator: std.mem.Allocator, data: T) !Self {
            return .{
                .allocator = allocator,
                .head = try Node.init(allocator, data),
            };
        }

        pub fn deinit(self: *Self) void {
            self.head.?.deinit();
            self.head = null;
        }

        pub fn append(self: *Self, data: T) !void {
            var tail: *Node = self.head.?;
            while (tail.next) |ptr| tail = ptr;
            tail.next = try Node.init(self.allocator, data);
        }

        pub fn lookup(self: Self, data: T) bool {
            var current: ?*Node = self.head;
            return while (current) |node_ptr| {
                if (node_ptr.data == data) break true;
                current = node_ptr.next;
            } else false;
        }
        pub fn printList(self: Self) void {
            var current: ?*Node = self.head;
            print("List: ", .{});
            if (current != null) {
                while (current) |node| {
                    print("{}, ", .{node.data});
                    current = node.next;
                }
                print("\n", .{});
            }
        }
    };
}

fn debugAllocVersion() !void {
    const LList = List(usize);
    var gpa = std.heap.DebugAllocator(.{}){}; // last {} are for creating instance.
    const allocator = gpa.allocator();
    const iterations: usize = 100;
    const item_count: usize = 1000;

    for (0..iterations) |_| {
        var my_list: LList = try LList.init(allocator, 13);
        defer my_list.deinit();
        for (0..item_count) |i| {
            try my_list.append(i);
        }
        // print("[", .{});
        // print("\tit: {}\n", .{it});
        // my_list.printList();
        // print("]", .{});
    }
}

// generic linked list that use the provided alocator.
pub fn List2(comptime T: type) type {
    return struct {
        const Node = struct {
            data: T,
            next: ?*Node,

            fn init(allocator: std.mem.Allocator, data: T) !*Node {
                const node = try allocator.create(Node);
                node.data = data;
                node.next = null;
                return node;
            }
        };
        const Self = @This();
        arena: std.heap.ArenaAllocator,
        head: ?*Node,
        pub fn init(allocator: std.mem.Allocator, data: T) !Self {
            // allocator will become backing allocator for arena allocator or child allocator.
            var list = Self{
                .arena = std.heap.ArenaAllocator.init(allocator),
                .head = null,
            };
            list.head = try Node.init(list.arena.allocator(), data);
            return list;
        }

        pub fn deinit(self: *Self) void {
            self.head.?.deinit();
            self.head = null;
        }

        pub fn append(self: *Self, data: T) !void {
            var tail: *Node = self.head.?;
            while (tail.next) |ptr| tail = ptr;
            tail.next = try Node.init(self.arena.allocator(), data);
        }

        pub fn lookup(self: Self, data: T) bool {
            var current: ?*Node = self.head.?;
            return while (current) |node_ptr| {
                if (node_ptr.data == data) break true;
                current = node_ptr.next;
            } else false;
        }
        pub fn printList(self: Self) void {
            var current: ?*Node = self.head;
            print("List: ", .{});
            if (current != null) {
                while (current) |node| {
                    print("{}, ", .{node.data});
                    current = node.next;
                }
                print("\n", .{});
            }
        }
    };
}

fn arenaAllocVersion() !void {
    const LList = List(usize);
    // we use the page_allocator as bakcing allocator for the
    // arena allocator. page_allocator is not recommended for
    // normal allocations since it allocates a full page of memory per allocation.
    //  don't use page_allocator as default allocator. it will be very inefficient.
    // if you creating an new allocator then you can use this alloctor as backing alloctor
    // which will ask os for memory page and for there you can track how much data is you have put in the page and
    // how you want to free it etc.
    const allocator = std.heap.c_allocator;
    const iterations: usize = 100;
    const item_count: usize = 1000;

    for (0..iterations) |_| {
        var my_list: LList = try LList.init(allocator, 13);
        defer my_list.deinit();
        for (0..item_count) |i| {
            try my_list.append(i);
        }
        //print("[", .{});
        //print("\tit: {}\n", .{it});
        //my_list.printList();
        //print("]", .{});
    }
}
pub fn main() !void {
    try arenaAllocVersion();
    try debugAllocVersion();
}

// more about allocator
// if you don't need any special allocation stratigies , go with general purpose allocator, debugallocator
//var gpa = std.heap.DebugAllocator(.{}){};
// when integrating with c, use
// std.heap.c_allocator.

// when targeting WASM, use
// std.heap.wasm_alloctor

// when using for testing, use
// std.heap.testing_allocator and std.testing.falling_allocator;

// A memory pool that can allocate objects of a single type very quickly.
// Use this when you need to allocate a lot of objects of the same type,
// because it outperforms general purpose allocators.
// this is more efficient since previously allocated slots can be re-used
// instead of allocating new ones.
// Functions that potentially allocate memory accept an `Allocator` parameter.
// std.heap.MemoryPool;
