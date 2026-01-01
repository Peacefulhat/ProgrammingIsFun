package main

import (
	"fmt"
)

/*
   #include<raylib.h>
   #cgo LDFLAGS: -lraylib
 */

import "C"

func main(){
		
    const screenWidth = 800;
    const screenHeight = 450;

    C.InitWindow(screenWidth, screenHeight, C.CString("raylib [<module>] example - <name>"));
    C.SetTargetFPS(60);
	for; !bool(C.WindowShouldClose());{
    
        C.BeginDrawing();
		C.ClearBackground(C.BLACK);
		C.DrawText(C.CString("Congrats! You created your first window!"), 190, 200, 20, C.LIGHTGRAY);
		C.DrawText(C.CString("Congrats! You created your first window!"), 190, 220, 20, C.LIGHTGRAY);
        C.EndDrawing();

	}
	
    C.CloseWindow()
	fmt.Println("Exited sucessfully")
}
