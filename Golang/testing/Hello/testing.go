package main

import (
	"fmt"
)

const mystring = "Hello,World!"
const mystring2 = "GoodNight,World!"

func myfunction(mystring string) string {
	return mystring

}

func if_function(value bool) bool {
	if value {
		return value
	}
	return false;
}

func if_else_function(value bool) bool {
	if value {
		return value
	}else{
		return value
	}
}


func if_else_if(value int16) {
	if value < 10 && value > 0 {
		fmt.Println("value greater than 10")
	}else if value < 20 && value >10{
		fmt.Println("value less than 20")
	}else if value < 30 && value > 20{
		fmt.Println("value less than 30")
	}else{
		fmt.Println("value less than 10 or greater than 30")
	}
}

func Switch(value int16) int16{
	switch value {
	case 1:
		{
			return value<<1
		}
	case 2:
		{
			return value<<2
		}

	case 3:
		{
			return value<<3
		}

	case 4,5:
		{
			return (value<<4)&5
		}
		
	default:
		{
			return value
		}
	}
}


func arrays(size int) {
	var a [5]int
	for i:=0; i<size; i++ {
		a[i]=i*2;
	}
	for i:=0; i< size; i++ {
		fmt.Println(a[i])
	}
}

func main() {
	var type_check int16
	fmt.Printf("%T",type_check)
	arrays(5);

}
