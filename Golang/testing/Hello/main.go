package main

import (

	"Hello/medium"
)

func main(){
	p := medium.PlayerData{}
	p.PlayerId = 234
	p.PlayerName = "Peacefulhat"
	p.PlayerPosition.X = 23.0
	p.PlayerPosition.Y = 17.0
	medium.CurrentPlayerData(&p)
	
}
