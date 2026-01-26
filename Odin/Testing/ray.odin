package ray

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


MOUSE_LEFT_BUTTON :: 0
KEY_S             :: 83
KEY_W             :: 87
KEY_DOWN          :: 264
KEY_UP            :: 265

LIGHTGRAY  :: Color { 200, 200, 200, 255 };   // Light Gray
GRAY       :: Color { 130, 130, 130, 255 };  // Gray
DARKGRAY   :: Color { 80, 80, 80, 255 };      // Dark Gray
YELLOW     :: Color { 253, 249, 0, 255 };     // Yellow
GOLD       :: Color { 255, 203, 0, 255 };     // Gold
ORANGE     :: Color { 255, 161, 0, 255 };     // Orange
PINK       :: Color { 255, 109, 194, 255 };   // Pink
RED        :: Color { 230, 41, 55, 255 };     // Red
MAROON     :: Color { 190, 33, 55, 255 };     // Maroon
GREEN      :: Color { 0, 228, 48, 255 };      // Green
LIME       :: Color { 0, 158, 47, 255 };      // Lime
DARKGREEN  :: Color { 0, 117, 44, 255 };      // Dark Green
SKYBLUE    :: Color { 102, 191, 255, 255 };   // Sky Blue
BLUE       :: Color { 0, 121, 241, 255 };     // Blue
DARKBLUE   :: Color { 0, 82, 172, 255 };      // Dark Blue
PURPLE     :: Color { 200, 122, 255, 255 };   // Purple
VIOLET     :: Color { 135, 60, 190, 255 };    // Violet
DARKPURPLE :: Color { 112, 31, 126, 255 };    // Dark Purple
BEIGE      :: Color { 211, 176, 131, 255 };   // Beige
BROWN      :: Color { 127, 106, 79, 255 };    // Brown
DARKBROWN  :: Color { 76, 63, 47, 255 };      // Dark Brown
WHITE      :: Color { 255, 255, 255, 255 };   // White
BLACK      :: Color { 0, 0, 0, 255 };         // Black
BLANK      :: Color { 0, 0, 0, 0 };           // Blank (Transparent)
MAGENTA    :: Color { 255, 0, 255, 255 };     // Magenta
RAYWHITE   :: Color { 245, 245, 245, 255 };   // My own White (raylib logo)


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


main:: proc()
{
    SetTargetFPS(60);
    InitWindow(800,600, "RaylibOdin");
    for ;!WindowShouldClose();{
        BeginDrawing();
        
        DrawText("Hello, This is Raylib Example !", 800-570, 300, 25, RED);
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
}
