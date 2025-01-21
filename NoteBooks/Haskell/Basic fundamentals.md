##### Note: Done in Haskell interpreter.
(kind of like an overview)
##### Examples
#### Expression:

- 3+2x2=7(no bodmas result)
- (3+2)x2=10(bodmas result)
- even 62=True (boolean value)
- even "Albert" -- type error.
- div 14 4 = 3 (integer value)(integer division)
- even(62) = True -- parentheses not necessary, when passing arguments.
#### Types:

- :type some_value:- will return its type .
- examples:
- :type 'D'
- 'D':: Char
- :type "Emma"
- "Emma"::[char]
- :type not
- not::Bool->Bool
- :type length
- length::foldable t=> t a->Int
	foldable means its can be list,tree etc.

#### Functions:

- factorial :: Integer->Integer
- factorial 0 = 1
- factorial n = n * factorial(n-1)

	
	map factorial [0..5]
	[1,1,2,5,24,120]
- kind of like it takes in a function and a list of arguments and evaluate the result and put them in a list.	

#### comments
- "--": is used for writing comments in Haskell.
#### Negative value:
- Negative value should be written with in parenthesis"()".
[[Basic Types]]