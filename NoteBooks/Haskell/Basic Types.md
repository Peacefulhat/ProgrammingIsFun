
#### Boolean's:
- Type:Bool
- Literals:False or True
- Operations:
- not::Bool->Bool --negation
- (||)::Bool->Bool->Bool -- disjunction
- (&&)::Bool->Bool->Bool -- conjunction

#### Integers:
- Type:
- Int:Integer of 64 bits
- Integer (arbitrarily long)
- Literals: 15,(-22),34239874823420374
- Operations: +,-,*,div,mod(Euclidean modules),rem,^.
- Relational operators:<,> <=,>= ,== ,/=(not this  ! =).
>[!NOTE]Note
>mod and rem works differently if we have negative numbers
#### Reals:
- Type:
- Float: 32 bit floating-point reals.
- Double:64 bit floating-point reals
- Literals:3.14,1e-9,-3.0
- Operations:+,-,*,/(real division),** (exponent).
- Relational operators: <,>,<=,>=, == , /=.
- Integer to Real conversion: fromIntegral 
- Real to Integer conversion: round, floor,ceiling

- Example:
	- round 3.6
		- 4
	- round (-3.6)
		- -4
	- ceiling x returns a least integer greater or equal to x.
	- ceiling 2.1
		- 3
	- ceiling 2.9
		- 3
	- ceiling 2.6
		- 3

	- floor x returns a greatest integer less than or equal to x.
	- floor 2.1
		- 2
	- floor 2.9
		- 2


#### Characters
- Types:Char
- Literals:'a','A','\n'
- Relational operators: <,> <=,>=, == , /=
- 'a'<'b' is True.
- because b appears after 'a'
- Conversion functions:(it is necessary import Data.Char)
- ord::Char->Int
- chr::Int->Char

#### Operator Precedence:
- 9 !!, .
- 8 ^,^^ ,**
- 7 * , / ,div
- 6 +,-
- 5 :,++
- 4 == , /= ,< ,<=,> >= ,elem ,notElem
- 3 &&
- 2 ||
- 1 >>, >>=
- 0 $ $ ! ,seq
#### Some predefined functions
##### is even / odd:
- even::Integral a=>a->Bool 

> [!NOTE] Note
> Here, we can see that (Integral a) => a->Bool, the section inside the bracket , specifies the condition on a,meaning here Integral is specifying the type of a.
> You will notice there will be => with it.
> Integral a : is the condition on a, here its saying that a must be an Integral.
  
- odd::Integral a=>a->Bool

##### minimum and maximum of two values:

- min::Ord a => a-> a->a

- max::Ord a => a->a->a

>![NOTE] Note
>(Ord a) means that a must belong to order class, so that,the given value can be compared.
>Ord is a type.
>order class : which come first , or like which is greater , so that relational operators can be applied.

##### greatest common divisor, least common multiple:
- gcd::Integral a => a->a->a
- lcm::Integral a => a->a->a

##### mathematicals:
- abs::Num a => a->a
- sqrt::Floating a=>a->a
- log::Floating a=>a->a
- exp::Floating a=>a->a
- cos::Floating a=>a->a


[[Functions]]