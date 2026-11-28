const std = @import("std");
const print = std.debug.print;

// struct memory layout

// an extern struct has a guaranted memory layout
// compatible with c abi. padding ensures alignment of fields and fields
// order is preserved is in the source code.

const Extern = extern struct {
    a: u16, // 2 byte align.
    // padding 6 bytes.
    b: u64, // 8 byte align.
    c: u16, // 2 byte align.
    // padding //6bytes.
};
// total size: 24 bytes;

const Normal = struct {
    // compiler may change order of fields.
    a: u16, // 2 byte align.
    b: u64, // 8 byte align.
    c: u16, // 2 byte align.
    // a ,c 4 + padding(4)
    // b 8
};
// align automatically
// total size 16 bytes;
// can rearrangment of fields to pack them as much as it can .

// a packed struct preserves fields order but packs fields
//together with no padding in between so fields only use
// their actual bit width in size. padding may be used at the
// end to ensure alignment at the struct boundary in memory.

//This means that a packed struct can participate in a @bitCast or a @ptrCast to reinterpret memory
const Packed = packed struct {
    a: u16,
    b: u64,
    c: u16,
    // 6 bytes of padding
};

pub fn main() void {
    print("extern_struct_c: {}\n", .{@sizeOf(Extern)});
    print("normal_struct_zig: {}\n", .{@sizeOf(Normal)});
    print("packed_struct_zig: {}\n", .{@sizeOf(Packed)});
    // bit casting on packed structs;
    const w: Whole = .{ .num = 65535 };
    print("w: {}\n", .{w});
    const w_cast: Parts = @bitCast(w);
    print("w_cast: {}\n", .{w_cast});
}

const Whole = packed struct { num: u16 };
const Parts = packed struct { half: u8, q3: u4, q4: u4 };
