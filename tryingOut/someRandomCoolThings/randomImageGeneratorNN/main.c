#include "raylib.h"
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#define screenWidth 800
#define screenHeight 450
#define FRAMERATE 20
#define FONTSIZE  


bool movingchar(int randomNumber){
        static int y=0;
        static int i=0;
        char randomText[2]={(char)randomNumber,'\0'};
	
	if(y>screenHeight){
	  printf("(x,y)::{%d,%d}\n",FONTSIZE*i,y);
	  return true;
	}
	if(FONTSIZE*i>screenWidth){
	  i=0;
	  y+=FONTSIZE+1;
	}
        DrawText(randomText, FONTSIZE*i, y, FONTSIZE, DARKGRAY);
	i++;
	return false;
}


int main(void) {
    SetRandomSeed(time(NULL));
    InitWindow(screenWidth, screenHeight, "raylib-NN");

    SetTargetFPS(FRAMERATE);
    int y=0;
    int i=0;
    while (!WindowShouldClose()) {
      int random=GetRandomValue(65, 90);
	BeginDrawing();
        ClearBackground(RAYWHITE);
	
	if(movingchar(random)){
	    break;
	}
        EndDrawing();
     }
    CloseWindow();
    return 0;
}



