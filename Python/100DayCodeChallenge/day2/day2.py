#Data Types: define what kind of data we are dealing with.

print("Hello"[0]) # print() H
print("Hello"[4]) #print() o
print("Hello"[-1])# print() o , -1 ,-2 ... are the index from end of string.

#python premitive data types

#string
print("123"+"345")

#integer= whole number without decimals.eg -1 ,2,0,21

print(123+123);

# large Integer
print(123_456_789)# the benifit of using number is like this, is because its easier to visualize.

#float = number with points
print(1.2524)

#boolean
print(True) #start with capital letter.



# how to know the type of data
# type() function gives the data type.
print(type("sudo"))
print(type(123))
print(type(1.234))
print(type(True))


# what if i want to convert int to string or string to int, this can be done done in python.
#conversion from one type to another is called type conversion

#int() converts a type to integer
#float() converts a type to a float
#bool() converts a type to a boolean
#str() converts a type to a string

#print("Number of letter in your name: " + str(len(input("Enter your name?"))))

#Mathematical operations.

print(134-23)#subtraction.
print(23*3)#multiplication.
print(6/3)#divides(float divsion).
print(6//3)#integer divsion.
print(2**3)#exponet.

#Number Manipulation

#flooring a number : removes all the decimal places using int() function.

#round() : round to next number if its equal or greater than five in decimals.,round(number,number_of_digts_to_round)


bmi=3.85
print(int(bmi))
print(round(bmi))

score=0
#Use score a point

score+=1
print(score)
score-=1

print(score)
score*=1
print(score)
score+=32;
print(score)


#f strings
# in python,we can use f-strings to insert a variable or an expression into a string.
my_var=f"player is notebooks {score}"
print(my_var)
