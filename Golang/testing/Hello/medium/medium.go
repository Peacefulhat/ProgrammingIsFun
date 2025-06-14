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
