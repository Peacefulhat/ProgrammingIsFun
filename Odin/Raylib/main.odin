 package pong

import "core:c"

foreign import raylib "system:raylib "

Color :: struct #packed {
    r, g, b, a: u8,
}

foreign raylib {
    InitWindow        :: proc(width: c.int, height: c.int, title: cstring) ---
    WindowShouldClose  :: proc() -> bool ---
    BeginDrawing      :: proc() ---
    ClearBackground   :: proc(color: Color) ---
    DrawText          :: proc(text: cstring, posX: c.int, posY: c.int, font_size: c.int, color: Color) ---
    EndDrawing        :: proc() ---
    CloseWindow       :: proc() ---
}

main :: proc() {
    InitWindow(800, 450, cstring("Raylib [core] example - basic window"))

    for !WindowShouldClose() {
        BeginDrawing()
        ClearBackground(Color{r=245, g=245, b=245, a=255})

        DrawText(
            cstring("Hello Odin + Raylib!"),
            190,
            200,
            20,
            Color{r=255, g=0, b=0, a=255},
        )

        EndDrawing()
    }

    CloseWindow()
}
