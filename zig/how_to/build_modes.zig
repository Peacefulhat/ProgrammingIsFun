const std = @import("std");
const print = std.debug.print;

// zig build-exe -Doptimize=safe build_mode.zig // Enable both safety checks and machine code optimizations
// zig build-exe -Doptimize=debug build_mode.zig // Prioritize bug detection, accurate debug info, compilation speed.
// zig build-exe -Ofast build_mode.zig // Prioritize runtime performance. Safety checks off.
// zig build-exe -Osmall build_mode.zig // Prioritize small binary size. Safety checks off.
// zig build-exe -fstrip  build_mode.zig // will strip all the debug symbols from exe.
// zig build-exe -fsingle_threaded build_mode.zig // will remove all the mutithreading features.
pub fn main() void {
    print("Hello, World!", .{});
}
