#loops: things that have to happen over and over again.
# for loops with list.
# for some_variable_name in list_name:
#        some_operation performed

fruits=["apple","peach","pear"]

for fruit in fruits:
    print(fruit)
    print(fruit + "pie")

print(fruits)
# sum function
students=[125,252,235,218,181,188,247]
total=sum(students)
print(total)

# sum function using for loops
sum=0
for score in students:
    sum+=score

print(sum)
# max number
max2=max(students)
print(max2)
max=-1
for score in students:
    if(max<score):
        max=score

print(max)

# range base for loop
# for number in range (a,b,c): a<=number<b , c is steps. increment
#          do_some_things

for number in range(1,10):
    print(number)

    
tsum=0
for number in range(1,101):
    tsum+=number;

print(number)

