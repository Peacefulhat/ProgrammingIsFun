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

RAYWHITE          :: Color { 245, 245, 245, 255};
RED               :: Color {255, 0, 0, 1};
BLUE              :: Color {0, 0, 255, 1};
DARKBLUE          :: Color { 0, 82, 172, 255};  
BLACK             :: Color {0, 0, 0, 1};
MOUSE_LEFT_BUTTON :: 0
KEY_S             :: 83
KEY_W             :: 87
KEY_DOWN          :: 264
KEY_UP            :: 265


foreign raylib {
    InitWindow             :: proc(width: i32, height: i32, title: cstring) ---
    WindowShouldClose      :: proc() -> bool ---
    BeginDrawing           :: proc() ---
    ClearBackground        :: proc(color: Color) ---
    DrawText               :: proc(text: cstring, posX: i32, posY: i32, font_size: i32, color: Color) ---
    EndDrawing             :: proc() ---
    CloseWindow            :: proc() ---
    DrawRectangle          :: proc(posX: i32, posY:i32, width: i32, height: i32, color: Color) ---
    DrawRectangleLinesEx   :: proc(rec: Rectangle, lineThick: f32, color: Color) ---
    CheckCollisionPointRec :: proc(Point: Vector2, rec: Rectangle) -> bool ---
    GetMousePosition       :: proc() -> Vector2 ---
    IsMouseButtonPressed   :: proc(button: i32) -> bool ---
    IsKeyDown              :: proc(key: i32) -> bool ---
    DrawCircle             :: proc(posX: i32, posY: i32, radiou: f32, color: Color) ---
    SetTargetFPS           :: proc(fps: i32) ---
    GetFrameTime           :: proc() -> f32 ---
}

foreign pmath {
    
}
