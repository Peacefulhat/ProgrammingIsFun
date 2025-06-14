package main

import (
	"fmt"
	"Hello/medium"
)

func main(){
	getvalue := medium.Intseq()
	fmt.Println("Clouser Function :: (Multiple Calls)")
	fmt.Println(getvalue())
	fmt.Println(getvalue())
	fmt.Println(getvalue())
	fmt.Println("Anonymous Function ::")
	fmt.Println(medium.AnonymousFunc(5))
	
	
}

