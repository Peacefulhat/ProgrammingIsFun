
- Functions in Haskell are pure:
	- They only return results calculated relative to their parameters.
- Functions do not have side effects.
	- They do not modify the parameters.
	- They do not modify the memory.
	- They don not modify the input/output.
- A function always returns the same result applied to the same parameters.
#### Definition of Functions:
- Functions identifiers start with a lowercase.
- To introduce a function:
	- First,its type declaration(header) is given.(is optional step,because of type inference ).
	- Then its definition is given,using formal parameters.
- Example's of function definition.
- Function definition
- double x  calculates the double of a value
	double ::Integer->Integer 
	double x = 2*x

- perimeter of rectangle
	perimeter::Integer->Integer->Integer
	perimeter height width = double (height+width)

- xor ,exclusive or.
	xOr::Bool->Bool->Bool 
	xOr a b = (a||b) && not(a&&b)

- factorial
	factorial::Integer->Integer
	factorial 0 = 1
	factorial n = n * factorial(n-1)

#### Definition with patterns:
- Functions can be defined with patterns:
- Example:
- factorial::Integer->Integer
- factorial 0 = 1 --base case,pattern
- factorial n = n * factorial(n-1) -- recurrence relation, other pattern. 
- The evaluation of the patterns in from top to bottom and returns the result of the first matching branch.
- patterns are considered more elegant than the if-then-else and they have many more applications.
>[!NOTE] Note
>when defining functions with patterns, we must always define base case first then the recursive case.
>evaluation happens from top to bottom.

- (underscore(_)) represents an anonymous variables:There is no relation between different _ )
- Example:
	- nand::Bool->Bool->Bool
	- nand True True=False
	- nand _ _=True

#### Definition with Guards
- Function can be defined with guards:
	- Example:
		- valabs::Int->Int
		- valabs n
			- | n>=0 =n
			- |otherwise = -n
- Guard evaluation is top-down and returns the result of the first true branch.
- Pattern definitions can also have guards.
- The otherwise is the same as True, but more readable.
>[!NOTE] Note
>Equality goes after every guard!