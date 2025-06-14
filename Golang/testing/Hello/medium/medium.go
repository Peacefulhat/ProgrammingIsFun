package medium


//Clouser

// here its returing a function and remember the old value of i and incremet it with every call.

func Intseq() func() int{
	i:=0
	return func() int{
		i++
		return i
	}
}





