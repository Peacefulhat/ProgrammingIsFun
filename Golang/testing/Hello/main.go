package main

import (
	"fmt"
	"Hello/medium"
)

func main(){
	p1 := medium.PlayerData{}
	p1.PlayerId = 234
	p1.PlayerName = "Peacefulhat"
	p1.PlayerPosition.X = 23.0
	p1.PlayerPosition.Y = 17.0
	
	p2 := medium.PlayerData{}
	p2.PlayerId = 223
	p2.PlayerName = "Peacefulhat"
	p2.PlayerPosition.X = 46.0
	p2.PlayerPosition.Y = 34.0
	fmt.Println(p1.DistanceTo(&p2))
	
}
