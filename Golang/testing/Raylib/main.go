package main

import (
	"Raylib/raylib"
	"fmt"
)

func main(){
	if raylib.WindowCreate() == 0 {
		fmt.Println("Everything Went Fine")
	}else{
		fmt.Println("Window Created Not Worked Fine")
	}	

}
