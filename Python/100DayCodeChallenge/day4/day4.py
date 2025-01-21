#day 4
# python lists.

#Randomisation: when we want to generate outputs, that are not predictable.example:games
#mersen twister.

# importing random module, which contains random() which can generate random numbers
import random

#random.randint(a,b); gives N, which a<=N<=b

random_integer=random.randint(1,10)
print(random_integer)

# what is a module?
# a module is a python file that can contain variables, functions and classes.
# Why use modules.
# modules allow us to split our code into  multiple files.
#instead of writing all our code inside a single python file.

#import my_module

#print(my_module.my_favourite_number)

# random() is used for floating point random number, 0.0<=x<1.0.
# uniform(a,b) is used for floating point random number,a<=N<=b.
random_floats=random.random()*7;
print(random_floats)

#Head, Tails program,range (0<x<2) this was the behaviour of the program.

head_tail=random.random()*2;

print(head_tail)
if head_tail>1 and head_tail<2:
    print("Heads")
else:
    print("Tails")


# lists: is a data structure, lets us store collection/groups of data,can be related or not.
# lists can contain same type of data or combination of data.
#syntax <name_of_list>= [value,vlaue1,...]

state_of_america=["Delaware","Pennsylvania","LA"]

print(state_of_america[0])# using index value i can acces the list element

# i can use -ve index to access the list from back side.

print(state_of_america[-1])

# to append data to the lsit we can use append().

state_of_america.append(23)

print(state_of_america[-1])

# to append the list of data with .extend([]).

state_of_america.extend(["AngelaLand","Akashland"])

print(state_of_america[-1])


#Banker Roulette

friends=["Alice","Bob","Cahrlie","David","Emanvel"]

pick_random=random.randint(0,4)

print(f"{friends[pick_random]} is the going to pay for food bill")


# nested list
#<list_name>=[[list1],value,[list2],...]

dirty_dozen=[["Apple","Tomato"],"grapes"]

print(dirty_dozen)

