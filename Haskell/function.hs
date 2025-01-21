
-- Funciton defination
-- double x  calculates the double of a value
double ::Integer->Integer 
double x = 2*x

-- perimeter of rectangle
perimeter::Integer->Integer->Integer
perimeter height width = double (height+width)

-- xor ,exclusive or.
xOr::Bool->Bool->Bool 
xOr a b = (a||b) && not(a&&b)

-- factorail
factorail::Integer->Integer
factorail 0 = 1
factorail n = n*factorail(n-1)

--negated conjuction
nand::Bool->Bool->Bool
nand True True = False
nand _ _ =True -- here using anonymous variables

