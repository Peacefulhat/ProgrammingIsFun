package pong
import "core:fmt"
import rl "raylibdef"

MARGIN         :: 5
WIDTH          :: 800
HEIGHT         :: 665
TITLE          :: "PONG"
SPEED          :: 10
RWIDTH         :: 10
RHEIGHT        :: 130
COLOR_BALL     :: RED
COLOR_RECT     :: RED
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

DrawComponent :: proc (^Left,^Right : rl.vec2, ^B : Ball, Ini : rl.vec2)
{
    #assert(Left  != nil);
    #assert(Right != nil);
    #assert(B     != nil);
    
    // middle line
    rl.DrawRectangle(WIDTH / 2, 0, 3, HEIGHT, COLOR_RECT);
    
    // paddles
    rl.DrawRectangle(Left.x, Left.y, RWIDTH, RHEIGHT, COLOR_RECT);
    rl.DrawRectangle(Right.x, Right.y, RWIDTH, RHEIGHT, COLOR_RECT);
    
    
    // Score region

    rl.DrawRectangle(0, 0, WIDTH, SCORE_REGION, RAYWHITE);
    rl.DrawRectangle(0, SCORE_REGION - 5, WIDTH,5, RED);
    
    // back button
    Rectangle Back={MARGIN, 20, 30, 30};
    DrawRectangleLinesEx(Back, 3, BLACK);
    DrawText("<-", Back.x + 5, Back.y + 5, 25, BLACK);
    
    
    Vector2 Mouse = rl.GetMousePosition();
    if (rl.CheckCollisionPointRec(Mouse, Back) && rl.IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        options = 0;
    }
    
    DrawText("SCORE", WIDTH / 2 - 110, 10, 30, RED);
    Score_Text: [20]u8;
    
    fmt.bprintf(&Score_Text, "%d : %d", Score.P1, Score.P2);
    
    rl.DrawText(cstring(Score_Text), WIDTH / 2, 10, 30, RED);
    GetScore(B);
    
    if(Score.State == true){
        Reset(B,Left,Right, Ini);
        Score.State = false;
    }
    
}

LeftPaddleMove :: proc (^Left: vec2)
{
    #assert(left != nil);
    
    if Left.y <= SCORE_REGION + SPEED {
        Left.y = SCORE_REGION + SPEED;
    }
    if (Left.y >= HEIGHT - RHEIGHT - SPEED) {
        Left.y = HEIGHT - RHEIGHT - SPEED;
    }

    if (rl.IsKeyDown(KEY_UP)) {
        Left.y -= SPEED;
    }
    if (rl.IsKeyDown(KEY_DOWN)) {
        Left.y += SPEED;
    }
    
    rl.DrawRectangle(Left.x, Left.y, RWIDTH, RHEIGHT, COLOR_RECT);
    
}

RightPaddleMove :: proc (^Right: vec2)
{
    #assert(Right != nil);
    
    if (Right.y <= SCORE_REGION + SPEED) {
        Right.y = SCORE_REGION + SPEED;
    }
    if (Right.y >= HEIGHT - RHEIGHT - SPEED) {
        Right.y = HEIGHT - RHEIGHT - SPEED;
    }
    if (IsKeyDown(KEY_W)) {
        Right.y -= SPEED;
    }
    if (IsKeyDown(KEY_S)) {
        Right.y += SPEED;
    }
    
    rl.DrawRectangle(Right.x, Right.y, RWIDTH, RHEIGHT, COLOR_RECT);
}

BallWallCollision :: proc (^B:Ball, dt:f32)
{
     #assert(B!= nil);
    vec_scaled_add2d(&B.Pos, B.Pos, B.Vel, dt * BALL_VEL_SCALE);
    
    // x wall collision
    if (B.Pos.x > WIDTH - B.Radius || B.Pos.x < B.Radius) {
        B.Vel.x = - B.Vel.x;
    }

    // y wall collision
    if (B.Pos.y > HEIGHT - B.Radius) {
        B.Vel.y = - B.Vel.y;
    }
    if (B.Pos.y < SCORE_REGION + B.Radius) {  
        B.Vel.y = - B.Vel.y;
    }

    rl.DrawCircle(B.Pos.x, B.Pos.y, B.Radius, COLOR_BALL);
}

PaddleBallCollision :: proc (^B:Ball, PaddleLeft, PaddleRight : vec2, dt: f32)
{
    #assert(B != nil);
    // left paddle right edge
    if ((B.Pos.x - B.Radius) <= (Left.x + RWIDTH) &&
    (B.Pos.y >= Left.y) && (B.Pos.y <= Left.y + RHEIGHT)) {
        B.Vel.x = - B.Vel.x;
    }
    
    // right paddle left edge
    if ((B.Pos.x + B.Radius) >= Right.x &&
    (B.Pos.y >= Right.y) && (B.Pos.y <= Right.y + RHEIGHT)) {
        B->Vel.x = - B->Vel.x;
    }    
}

Get_Score :: proc (^B: Ball)
{
    if B.Pos.x < B.radius { 
        Score.P2 += 1;
        Score.State = true;
    }
    if (B.Pos.x > WIDTH - B.Radius) {  
        Score.P1 += 1;
        Score.State = true;
    }
    
}

Reset :: proc (^B:Ball, ^Left, ^Right : vec2, Ini : vec2)
{
    #assert(b != nil);
    #assert(left != nil);
    #assert(right != nil);
    
    B.pos.x = WIDTH/2;
    B.pos.y = HEIGHT/2;
    Left.x  = MARGIN;
    Left.y  = MARGIN;
    Right.x = P2LOC;
    Right.y = MARGIN;
    B.Vel.x = Ini.x;
    B.Vel.y = Ini.x;
}

HomeScreen :: proc ()
{
    Title    :: vec2 {150,100};
    Line     :: vec2 {145,160};
    Play     :: Rectangle {250,230,200,50};
    Settings :: Rectangle {250,300,300,50};
    Boffset  :: vec2 {25,5};
    Quit     :: Rectangle {250,370,200,50};
    
    rl.DrawText("HELLO,PONG", i32(Title.x), i32(title.y), 70, BLACK);
    rl.DrawText("==================", i32(Line.x), i32(Line.y), 50, RED);

    rl.DrawRectangleLinesEx(Play, 3, BLACK);
    rl.DrawText("PLAY", Play.x + i32(Boffset.x), Play.y + i32(Boffset.y), 50, DARKBLUE);
    
    rl.DrawRectangleLinesEx(Settings, 3, BLACK);
    rl.DrawText("SETTINGS", Settings.x + i32(Boffset.x), Settings.y + i32(Boffset.y), 50, DARKBLUE);
    
    DrawRectangleLinesEx(Quit, 3, BLACK);
    DrawText("QUIT", Quit.x+ i32(Boffset.x), Quit.y + i32(Boffset.y), 50, DARKBLUE);
    
    rl.Vector2 Mouse = rl.GetMousePosition();
    
    if(Mouse.x > Play.x && Mouse.x < Play.x + 200) &&
        (Mouse.y > Play.y && Mouse.y < Play.y + 50)
    {
        if rl.IsMouseButtonPressed(rl.MOUSE_LEFT_BUTTON)
        {
            options=1;
        }
    }
    
    if (Mouse.x > Settings.x && Mouse.x < Settings.x + 200) &&
        (Mouse.y > Settings.y && mouse.y < Settings.y + 50)
    {
        if rl.IsMouseButtonPressed(rl.MOUSE_LEFT_BUTTON)
        {
            options=2;
        }
    }
    
    if (Mouse.x > Quit.x && Mouse.x <Quit.x + 200) &&
        (Mouse.y > Quit.y && Mouse.y < Quit.y + 50)
    {
        if rl.IsMouseButtonPressed(rl.MOUSE_LEFT_BUTTON)
        {
            options=3;
        }
    }
}

QuitScreen :: proc ()
{
    for i:32=0; i < 120; i++ {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("GOODBYE!", 80, 100, 100, RED);
        DrawText("Thanks For Playing", 100, 250, 30, RED);
        EndDrawing();
    }
    
}

Settings :: proc ()
{
}

