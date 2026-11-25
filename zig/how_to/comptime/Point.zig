pub fn Point(comptime T: type) type { // generic struct
    return struct {
        x: T,
        y: T,
        const Self = @This();
        pub fn new(x: T, y: T) Self {
            return .{ .x = x, .y = y };
        }

        pub fn distance(self: Self, other: Self) f64 {
            const diff_x: f64 = switch (@typeInfo(T)) {
                .int => @floatFromInt(other.x - self.x),
                .float => (other.x - self.x),
                else => @compileError("Only floats or ints allowed"),
            };

            const diff_y: f64 = switch (@typeInfo(T)) {
                .int => @floatFromInt(other.y - self.y),
                .float => (other.y - self.y),
                else => @compileError("Only floats or ints allowed"),
            };

            return @sqrt(diff_x * diff_x + diff_y * diff_y);
        }
    };
}
