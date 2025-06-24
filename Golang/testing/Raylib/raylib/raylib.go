package raylib

/*
  #cgo LDFLAGS: -lraylib
  #include<raylib.h>
 */
import "C"


func WindowCreate() uint8{
    const screenWidth = 800;
    const screenHeight = 450;

    C.InitWindow(screenWidth, screenHeight, C.CString("raylib [<module>] example - <name>"));

    C.SetTargetFPS(60);
	for; !bool(C.WindowShouldClose());{
    
        C.BeginDrawing();
		C.ClearBackground(C.RAYWHITE);
		C.DrawText(C.CString("Congrats! You created your first window!"), 190, 200, 20, C.LIGHTGRAY);

        C.EndDrawing();

	}
	
    C.CloseWindow(); 

    return 0;
}
