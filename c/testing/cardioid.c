#include <stdio.h>
#include <raylib.h>
#include <math.h>
#define REV 2 * 3.141
#define WIDTH 1280
#define HEIGHT 720
#define A 2
#define SCALE 70

void GetPointOnCardioid(Vector2* Current, float rAngle)
{
    float r = A * ( 1 - cosf(rAngle));
    Current->x = (WIDTH/2 + SCALE *r*cosf(rAngle));
    Current->y =  HEIGHT/3 + SCALE *r*sinf(rAngle);
}

void DrawCardioid(Vector2* Current, float rAngle)
{
    while( rAngle< REV){
        GetPointOnCardioid(Current, rAngle);
        DrawPixelV(*Current, RED);
        rAngle += 0.0001;
    }
}


int main(int argc, char**argv)
{
    InitWindow(800, 450, "Cardioid");
    SetTargetFPS(60);

    Vector2 first = {WIDTH/2, HEIGHT/2};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCardioid(&first, 0);                
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
