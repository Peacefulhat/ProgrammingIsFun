//When @This() is used at file scope, it returns a reference to the struct that corresponds to the current file.
const Point = @This();
x: f32,
y: f32 = 0,

// here makeing funciton public so we can use them from another file.
pub fn new(x: f32, y: f32) Point {
    return .{ .x = x, .y = y };
}

pub fn distance(self: Point, other: Point) f32 {
    const diff_x = other.x - self.x;
    const diff_y = other.y - self.y;
    return @sqrt(diff_x * diff_x + diff_y * diff_y);
}
