#include <raylib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define WIDTH   1280
#define HEIGHT  720
#define XOFFSET 50
#define YOFFSET 50
#define DEPTH   3
#define ANGLE_REDUCER 20
#define ANGLE_ADDER 20
#define HEIGHT_REDUCER 1
#define BRANCH_THICKNESS 8.0f

#define Radian(Angle) (Angle) * (3.14159265f / 180.0f)

typedef struct{
    Vector2 Point;
    float Angle;
    int Height;
}Branch;

Color Vector2GetColor(Vector2 Vec)
{
    return (Color){
        .r = (int)(Vec.x)  %  255,
        .g = (int)(Vec.y)  %  255,
        .b = ((int)Vec.y & (int)Vec.x) % 255,
        .a = 255
    };
}

Vector2 FindPoint(Branch B){
    return (Vector2) {
        B.Point.x + cosf(Radian(B.Angle)) * B.Height * DEPTH,
        B.Point.y + sinf(Radian(B.Angle)) * B.Height * DEPTH
    };

}

// Dynamic Fractal Tree. (Every branch can be seen as we draw per frame.)
void DrawFractalTreePerFrame(Branch B, int* branchesThisFrame, int maxBranchesPerFrame)
{
    if (B.Height < 0) return;

    if (*branchesThisFrame >= maxBranchesPerFrame) return;

    (*branchesThisFrame)++; 

    Color BranchColor = Vector2GetColor(B.Point);
    Vector2 Point2 = FindPoint(B);

    DrawLineEx(B.Point, Point2, BRANCH_THICKNESS, BranchColor);

    Branch Left = {
        .Point = Point2,
        .Angle = B.Angle - ANGLE_REDUCER,
        .Height = B.Height - HEIGHT_REDUCER
    };

    Branch Right = Left;
    Right.Angle = B.Angle + ANGLE_ADDER;

    DrawFractalTreePerFrame(Left, branchesThisFrame, maxBranchesPerFrame);
    DrawFractalTreePerFrame(Right, branchesThisFrame, maxBranchesPerFrame);
}

// Static Fractal Tree.
void DrawFractalTree(Branch B)
{

    if (B.Height <= 0) return;

    Color BranchColor = Vector2GetColor(B.Point);

    Vector2 Point2 = FindPoint(B);

    DrawLineEx(B.Point, Point2, BRANCH_THICKNESS, BranchColor);
    
    Branch Left = {
        .Point.x = Point2.x,
        .Point.y = Point2.y,
        .Angle = B.Angle - ANGLE_REDUCER,
        .Height = B.Height - HEIGHT_REDUCER
    };

    
    Branch Right = Left;
    Right.Angle = B.Angle + ANGLE_ADDER;
    
    
    DrawFractalTree(Left);
    DrawFractalTree(Right);
}

int main(int argc, char**argv)
{
    int maxBranchesPerFrame   = 0;
    int NotStill = 0;
    SetTargetFPS(60);
    InitWindow(WIDTH, HEIGHT, "Basic Window");
    Branch Root = {
        .Point.x = WIDTH/2, .Point.y = HEIGHT - YOFFSET,
        .Angle = -90, .Height = 10
    }; 
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if(NotStill)
        {
            int branchesThisFrame = 0;
            //        maxBranchesPerFrame += GetTime()*50;
            maxBranchesPerFrame += 2;
            DrawFractalTreePerFrame(Root, &branchesThisFrame, maxBranchesPerFrame);
        }
        
        else
        {
            DrawFractalTree(Root);
        }
      EndDrawing();
        
    }

    CloseWindow();

    return 0;
}
