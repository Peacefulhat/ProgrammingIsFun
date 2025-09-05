package pong

import rl "Include"

main :: proc() {
    rl.InitWindow(800, 450, cstring("Raylib + Odin: Hello World"))

    for !rl.WindowShouldClose() {
        rl.BeginDrawing()
        rl.ClearBackground(rl.Color{0,255,0,1})

        rl.DrawText(
            cstring("Hello Odin + Raylib!"),
            190,
            200,
            20,
            rl.RED,
        )

        rl.DrawCircle(200, 200, 50, rl.RED);
        rl.EndDrawing()
    }

    rl.CloseWindow()
}
