package rayincl

foreign import raylib "system:raylib"

Color :: struct #packed {
    r, g, b, a: u8,
}

Rectangle :: struct #packed {
    x      : f32,               
    y      : f32,               
    width  : f32,
    height : f32          
}

vec2 :: struct #packed {
    x : f32,
    y : f32
}

Vector2 :: struct #packed {
    x : f32,
    y : f32
}

RED  :: Color{255, 0, 0, 255}
BLUE :: Color{0, 0, 255, 255}

foreign raylib {
    InitWindow           :: proc(width: i32, height: i32, title: cstring) ---
    WindowShouldClose    :: proc() -> bool ---
    BeginDrawing         :: proc() ---
    ClearBackground      :: proc(color: Color) ---
    DrawText             :: proc(text: cstring, posX: i32, posY: i32, font_size: i32, color: Color) ---
    EndDrawing           :: proc() ---
    CloseWindow          :: proc() ---
    DrawRectangle        :: proc(rec: Rectangle, lineThick: f32, color: Color) ---
    GetMousePosition     :: proc() -> Vector2 ---
    IsMouseButtonPressed :: proc(button: i32) -> bool ---
    DrawCircle           :: proc(posX: i32, posY: i32, radiou: f32, color: Color) ---
}
