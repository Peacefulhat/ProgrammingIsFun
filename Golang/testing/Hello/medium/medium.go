package medium

//Clouser
//Closures “capture” and remember the variables from their surrounding scope.

//Go closure is a nested function that allows us to access variables of the outer function even after the outer function is closed.

// here its returing a function and remember the old value of i and incremet it with every call.

func Intseq() func() int{
	i:=0
	return func() int{
		i++

		return i
	}
}

// Anonymous function , a function with out a name

func AnonymousFunc(size int16) int {
	
	sumFunc := func(size int16) int16 {
		var sum int16 = 0
		for i := int16(0); i < size; i++ {
			sum += i
		}
		return sum
	}(size)
	return int(sumFunc)
}

// Recursive

func Recursive(n int) int {
	if n == 0 {
		return 1;
	}
	return n*Recursive(n-1)
}

// Anonymous function can be recursive

func Arecursive(n int32) int32 {
	// its like function type.
	var fact func(n int32) int32
	
	fact = func(n int32) int32{
		if n == 1{
			return 1;
		}
		return n*fact(n-1)
	}
		
	return fact(n)
}


// Pointers

func Pointers(n *int32) int32{
	*n++
	return *n
}

func PointerToArray(n *[]int32) int32{
	sum := int32(0)
	
	for i := int32(0); i<int32(len(*n)); i++{
		sum += (*n)[i]
	}
	return sum
}

// Todo finish it
func PointerTo2DArray() {

}
