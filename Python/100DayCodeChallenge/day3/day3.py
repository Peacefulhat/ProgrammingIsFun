#conditional statements
# are statements depending on particular statement truth value we can do certain things,lets make decisions

#if condition:
    #do this
vh=100

if vh==100:
    print("100% View Port Height")

#if/else
#if conditional:
 #   do this
#else:
 #   do this

water_level=50
print("Bath Tub Water Level:")
if water_level>80:
    print("Drain Water")
else:
    print("Contine Filling Water")

print("\n")

print("Roller Coster Tickets:")
height=int(input("What is your height in cm? "))
if height>120:
    print("Can ride")
else:
    print("Can't ride")


# Relationl operators.
# == : lhs == rhs : true:false
# !=: lhs!=rhs : true:false
# >: lsh>rhs:true:false
#<: lsh<rhs:true:false
#>=:lsh>=rhs:true:false
#<=:lsh>=rhs:true:false


# modulo operator: gives the remainder. a%b=q , there q is some remainder a/b=p+q. p is quotient.

# check if a number is even or not
number_to_check=int(input("What is the number you want to check? "))

if number_to_check%2:
    print("Odd")
else:
    print("Even")

#nested if/else statement

#if condition:
#   if another condition:
        #do this:
#   else:
        #do this:
#else:
    #do this:

height=int(input("What is your height in cm? "))
if height>=120:
    print("Can ride")
    age=int(input("What is your age? "))
    if age<=18:
        print("Please pay $7.")
    else:
        print("Please pay $12.")
else:
    print("Sorry you have to grow taller before you can ride.")


# let say if we have more than 3 conditons we can use if/else if or called elif statement.

height=int(input("What is your height in cm? "))
if height>=120:
    print("Can ride")
    age=int(input("What is your age? "))
    if age<=12:
        print("Please pay $5.")
    elif age<=18:
        print("Please pay $17.")
    else:
        print("Please pay ")
else:
    print("Sorry you have to grow taller before you can ride.")


 #pizza dilivery 

print("Welcome to Python Pizza Deliveries!")
size=input("What size pizza do you want? S,M or L:")
pepperoni=input("Do you want pepperoni on you pizza? Y or N: ")
extra_cheese=input("Do you want extra cheese? Y or N:")

cost_small_pizza=15
cost_medium_pizza=20
cost_large_pizza=25
additional_pepperoni_small=2
additional_pepperoni_medium_large=3
additional_cheese=1
total_bill=0

if size=="S":
    total_bill+=15
elif size=="M":
    total_bill+=20
elif size=="L":
    total_bill+=25
else:
    print("You typed the wrong input")

if pepperoni=="Y":
    if size=="S":
        total_bill+=additional_pepperoni_small
    else:
        total_bill+=additional_pepperoni_medium_large

if extra_cheese=="Y":
    total_bill+=additional_cheese

print(f"Your total bill is: ${total_bill}")

#logical operators
#and
# A and B = True and True == True
# else false.
#or
# A or B = False and False == False
# else True

#not
# A==True ,not A ==False




# if conditions & condition2 & contition3
    #do this
# else:
    #do this



 
