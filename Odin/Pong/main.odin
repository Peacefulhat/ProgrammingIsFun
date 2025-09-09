package pong

import rl "raylibdef"

foreign import "pmath.a"

main :: proc(){
    rl.SetTargetFPS(60);
    rl.InitWindow(800, 450, cstring("Raylib + Odin: Hello World"))
    PaddleLeft := rl.vec2 {5, 5};
    PaddleRight := rl.vec2 {P2LOC, 5};
    BallVel := rl.vec2 {2, 2};
    ball := Ball {{WIDTH/2,HEIGHT/2},BallVel,6};
    dt := rl.GetFrameTime();
    
    for !rl.WindowShouldClose() {
        dt := rl.GetFrameTime(); 
        rl.BeginDrawing()
        rl.ClearBackground(rl.Color{0,255,0,1})
        switch(Options){
        case 0:
            HomeScreen();
            break;
        case 1:
            DrawComponents(&PaddleLeft, &PaddleRight, &ball, &BallVel);
            LeftPaddleMove(&PaddleLeft);
            RightPaddleMove(&PaddleRight);
            BallWallCollision(&ball, dt*1.2);
            PaddleBallCollision(&ball, &PaddleLeft, &PaddleRight, dt);

        case 2:
            // settings not implemented yet
            Settings();

            
        case 3:
            QuitScreen();
            
        }
        rl.EndDrawing()
    }

    rl.CloseWindow()
}
