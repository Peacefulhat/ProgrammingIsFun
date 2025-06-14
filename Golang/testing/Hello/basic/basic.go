package basic

import "fmt"

// constants
const MAX = 100
const mystring = "Hello,World!"
const mystring2 = "GoodNight,World!"

// function
func myfunction(mystring string) string {
	return mystring

}

func multi_return(a int32, b int32) (int32 , int32){
	return (a+b),(a-b) // return sum and difference
}

func Variadic_funcs(cmd_args ... string){ // cmd_args is like array of stirngs
	for i:=0 ;i<len(cmd_args); i++{
	fmt.Println(cmd_args[i]) 
}
}

//Maps (hashtables)

func Maps(name string){
	m := make(map[string]int)
	// name = age , name is like key here and age is like value
	m["Hello"] = 23
	m["World"] = 24
	
	//delete(m,"Hello"); // delete a value based on key
	//clear(m) // clear whole map
	
	fmt.Println("Maps value at give name ::", m[name])
	fmt.Println("Maps length :: ", len(m))
	fmt.Println("Maps", m)

	//2d maps // just keep nesting maps for nd maps
	mat := make(map[int]map[int]float32)
	mat[2] = map[int]float32{5:3.14}
	fmt.Println("2d Maps :: ",mat)
}

// if statemets
func if_function(value bool) bool {
	if value {
		return value
	}
	return false
}

func if_else_function(value bool) bool {
	if value {
		return value
	} else {
		return value
	}
}

func if_else_if(value int16) {
	if value < 10 && value > 0 {
		fmt.Println("value greater than 10")
	} else if value < 20 && value > 10 {
		fmt.Println("value less than 20")
	} else if value < 30 && value > 20 {
		fmt.Println("value less than 30")
	} else {
		fmt.Println("value less than 10 or greater than 30")
	}
}

// switch
func Switch(value int16) int16 {
	switch value {
	case 1:
		{
			return value << 1
		}
	case 2:
		{
			return value << 2
		}

	case 3:
		{
			return value << 3
		}

	case 4, 5:
		{
			return (value << 4) & 5
		}

	default:
		{
			return value
		}
	}
}

// arrays
func oned_arrays(size int) {
	var a [5]int
	for i := 0; i < size; i++ {
		a[i] = i * 2
	}

	for i := 0; i < size; i++ {
		fmt.Println(a[i])
	}
}

func twod_arrays(rows int16, cols int16) {
	var arr [MAX][MAX]int
	fmt.Printf("\n")
	var i int16 = 0
	for ; i < rows; i++ {
		var j int16 = 0
		for ; j < cols; j++ {
			fmt.Scan(&arr[i][j])
		}
	}

	i = 0
	for ; i < cols; i++ {
		var j int16 = 0
		fmt.Printf("[")
		for ; j < cols; j++ {
			// (Todo): printing does not work
			fmt.Printf((string)(arr[i][j]), ",")
		}
		fmt.Printf("]\n")
	}

}

func arrays_different_syntax() {
	b := [...]float32{2.2, 2.25, 3.5}
	c := [...][2]float32{{2.3, 2.5}, {2.6, 2.7}}

	fmt.Println(b)
	fmt.Println(c)
}

// slices

func slices() {
	// first way to make slice
	var s []string
	s = append(s, "First")
	s = append(s, "Second")

	// second way to make slice using make([] T, length, capcity) function
	d := make([]int, 5)

	c := make([]string, len(s)) // this is need for copy
	c = append(c, "Third")
	copy(c, s) // copy possbile only if lens are similar

	fmt.Println("First Slice ::", s)
	fmt.Println("Integer Slice :: ", d)
	fmt.Println("Second Slice ::", c)
	fmt.Println("Length of string:: ", len(s))
	
	l := c[0:3] // last is exclude form the slice(0,1,2) not 3
	fmt.Println("Thirde Slice ::", l)
	l = l[:2] // it like include everything that comes before :2(0,1) 
	fmt.Println("Third Slice ::", l)
	// 2D Slice
	rows, cols := 3, 4
grid := make([][]int, rows) // 3 rows

for i := range grid {
	grid[i] = make([]int, cols) // each row has 4 columns
}
	grid[1][2] = 99
	fmt.Println("2D Slice:: ",grid[1][2])

}

