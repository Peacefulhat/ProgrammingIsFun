package pong

import "core:fmt"

foreign import pmath "pmath.a"

foreign pmath {
    vec_scaled_add2d :: proc(result: ^rl.vec2, a,b:rl.vec2, scale: f32) ---
}

import rl "raylibdef"

MARGIN         :: 5
WIDTH          :: 800
HEIGHT         :: 665
TITLE          :: "PONG"
SPEED          :: 10
RWIDTH         :: 10
RHEIGHT        :: 130
COLOR_BALL     :: rl.RED
COLOR_RECT     :: rl.RED
P2LOC          :: ((WIDTH - RWIDTH) - 5)
BALL_VEL_SCALE :: 100
SCORE_REGION   :: 65

Pair :: struct {
    P1    : u32,
    P2    : u32,
    State : bool
}

Ball :: struct {
    Pos    : rl.vec2,
    Vel    : rl.vec2,
    Radius : i32
}


Options : u8 = 0;
Score   := Pair {0,0,false};

DrawComponents :: proc (Left: ^rl.vec2, Right : ^rl.vec2, B : ^Ball, Ini : ^rl.vec2)
{
        // middle line
    rl.DrawRectangle(WIDTH / 2, 0, 3, HEIGHT, COLOR_RECT);
    
    // paddles
    rl.DrawRectangle(i32(Left.x), i32(Left.y), RWIDTH, RHEIGHT, COLOR_RECT);
    rl.DrawRectangle(i32(Right.x), i32(Right.y), RWIDTH, RHEIGHT, COLOR_RECT);
    
    
    // Score region

    rl.DrawRectangle(0, 0, WIDTH, SCORE_REGION, rl.RAYWHITE);
    rl.DrawRectangle(0, SCORE_REGION - 5, WIDTH,5, rl.RED);
    
    // back button
    Back := rl.Rectangle{MARGIN, 20, 30, 30};
    rl.DrawRectangleLinesEx(Back, 3, rl.BLACK);
    rl.DrawText("<-", i32(Back.x) + 5, i32(Back.y) + 5, 25, rl.BLACK);
    
    
    Mouse := rl.GetMousePosition();
    if (rl.CheckCollisionPointRec(Mouse, Back) && rl.IsMouseButtonPressed(rl.MOUSE_LEFT_BUTTON)) {
        Options = 0;
    }
    

    GetScore(B);
    
    if(Score.State == true){
        Reset(B,Left,Right, Ini^);
        Score.State = false;
    }
    
}

LeftPaddleMove :: proc (Left: ^rl.vec2)
{
    
    if Left.y <= SCORE_REGION + SPEED {
        Left.y = SCORE_REGION + SPEED;
    }
    if (Left.y >= HEIGHT - RHEIGHT - SPEED) {
        Left.y = HEIGHT - RHEIGHT - SPEED;
    }

    if (rl.IsKeyDown(rl.KEY_UP)) {
        Left.y -= SPEED;
    }
    if (rl.IsKeyDown(rl.KEY_DOWN)) {
        Left.y += SPEED;
    }
    
    rl.DrawRectangle(i32(Left.x), i32(Left.y), RWIDTH, RHEIGHT, COLOR_RECT);
    
}

RightPaddleMove :: proc (Right: ^rl.vec2)
{
        
    if (Right.y <= SCORE_REGION + SPEED) {
        Right.y = SCORE_REGION + SPEED;
    }
    if (Right.y >= HEIGHT - RHEIGHT - SPEED) {
        Right.y = HEIGHT - RHEIGHT - SPEED;
    }
    if (rl.IsKeyDown(rl.KEY_W)) {
        Right.y -= SPEED;
    }
    if (rl.IsKeyDown(rl.KEY_S)) {
        Right.y += SPEED;
    }
    
    rl.DrawRectangle(i32(Right.x), i32(Right.y), RWIDTH, RHEIGHT, COLOR_RECT);
}

BallWallCollision :: proc (B: ^Ball, dt:f32)
{
    
    vec_scaled_add2d(&B.Pos, B.Pos, B.Vel, dt * BALL_VEL_SCALE);
    
    // x wall collision
    if (i32(B.Pos.x) > WIDTH - B.Radius || i32(B.Pos.x) < B.Radius) {
        B.Vel.x = - B.Vel.x;
    }

    // y wall collision
    if (i32(B.Pos.y) > HEIGHT - B.Radius) {
        B.Vel.y = - B.Vel.y;
    }
    if (i32(B.Pos.y) < SCORE_REGION + B.Radius) {  
        B.Vel.y = - B.Vel.y;
    }

    rl.DrawCircle(i32(B.Pos.x), i32(B.Pos.y), f32(B.Radius), COLOR_BALL);
}

PaddleBallCollision :: proc (B: ^Ball, Left, Right : ^rl.vec2, dt: f32)
{
    
    // left paddle right edge
    if (i32(B.Pos.x - f32(B.Radius)) <= (i32(Left.x) + RWIDTH) &&
        (i32 (B.Pos.y) >= i32(Left.y)) && (i32(B.Pos.y) <= i32(Left.y) + RHEIGHT)) {
        B.Vel.x = - B.Vel.x;
    }
    
    // right paddle left edge
    if ((i32(B.Pos.x) + B.Radius) >= i32(Right.x) &&
    (B.Pos.y >= Right.y) && (B.Pos.y <= Right.y + RHEIGHT)) {
        B.Vel.x = - B.Vel.x;
    }    
}

GetScore :: proc (B: ^Ball)
{
    if i32(B.Pos.x) < B.Radius { 
        Score.P2 += 1;
        Score.State = true;
    }
    if (i32(B.Pos.x) > WIDTH - B.Radius) {  
        Score.P1 += 1;
        Score.State = true;
    }
    
}

Reset :: proc (B: ^Ball, Left: ^rl.vec2, Right : ^rl.vec2, Ini : rl.vec2)
{
       
    B.Pos.x = WIDTH/2;
    B.Pos.y = HEIGHT/2;
    Left.x  = MARGIN;
    Left.y  = MARGIN;
    Right.x = P2LOC;
    Right.y = MARGIN;
    B.Vel.x = Ini.x;
    B.Vel.y = Ini.x;
}

HomeScreen :: proc ()
{
    Title    :: rl.vec2 {150,100};
    Line     :: rl.vec2 {145,160};
    Play     :: rl.Rectangle {250,230,200,50};
    Settings :: rl.Rectangle {250,300,300,50};
    Boffset  :: rl.vec2 {25,5};
    Quit     :: rl.Rectangle {250,370,200,50};
    
    rl.DrawText("HELLO,PONG", i32(Title.x), i32(Title.y), 70, rl.BLACK);
    rl.DrawText("==================", i32(Line.x), i32(Line.y), 50, rl.RED);

    rl.DrawRectangleLinesEx(Play, 3, rl.BLACK);
    rl.DrawText("PLAY", i32(Play.x) + i32(Boffset.x), i32(Play.y) + i32(Boffset.y), 50, rl.DARKBLUE);
    
    rl.DrawRectangleLinesEx(Settings, 3, rl.BLACK);
    rl.DrawText("SETTINGS", i32(Settings.x) + i32(Boffset.x), i32(Settings.y) + i32(Boffset.y), 50, rl.DARKBLUE);
    
    rl.DrawRectangleLinesEx(Quit, 3, rl.BLACK);
    rl.DrawText("QUIT", i32(Quit.x)+ i32(Boffset.x), i32(Quit.y) + i32(Boffset.y), 50, rl.DARKBLUE);
    
    Mouse := rl.GetMousePosition();
    
    if(Mouse.x > Play.x && Mouse.x < Play.x + 200) &&
        (Mouse.y > Play.y && Mouse.y < Play.y + 50)
    {
        if rl.IsMouseButtonPressed(rl.MOUSE_LEFT_BUTTON)
        {
            Options=1;
        }
    }
    
    if (Mouse.x > Settings.x && Mouse.x < Settings.x + 200) &&
        (Mouse.y > Settings.y && Mouse.y < Settings.y + 50)
    {
        if rl.IsMouseButtonPressed(rl.MOUSE_LEFT_BUTTON)
        {
            Options=2;
        }
    }
    
    if (Mouse.x > Quit.x && Mouse.x <Quit.x + 200) &&
        (Mouse.y > Quit.y && Mouse.y < Quit.y + 50)
    {
        if rl.IsMouseButtonPressed(rl.MOUSE_LEFT_BUTTON)
        {
            Options=3;
        }
    }
}

QuitScreen :: proc ()
{
    for i: i32 = 0; i < 120; i+=1 {
        rl.BeginDrawing();
        rl.ClearBackground(rl.BLACK);
        rl.DrawText("GOODBYE!", 80, 100, 100, rl.RED);
        rl.DrawText("Thanks For Playing", 100, 250, 30, rl.RED);
        rl.EndDrawing();
    }
    
}

Settings :: proc ()
{
}

