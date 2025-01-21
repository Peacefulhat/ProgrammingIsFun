#day5 project
#password generator.
#easy version
import random

letter="abcdefghijklmnopqrstuvwxyz"
numbers="0123456789"
symbols="!#$%&()*,+"

print("Welcome to the PyPassword Generator!")
nr_letters=int(input("How many letters would you like in your password?\n"))
nr_numbers=int(input("How many numbers would you like in your password?\n"))
nr_symbols=int(input("How many symbols would you like in your password?\n"))

your_password=""
for _ in range(1,nr_letters+1):
    rand=random.randint(0,25)
    your_password+=letter[rand]
    

for _ in range(1,nr_numbers+1):
    rand=random.randint(0,9)
    your_password+=numbers[rand]

for _ in range(1,nr_symbols+1):
    rand=random.randint(0,9)
    your_password+=symbols[rand]

print(f"Easy vesrsion: Your Generated Password is: {your_password}")


# for hard version. We can agian randomize the password

hard_password=[]
for a in your_password:
    hard_password.append(a)

random.shuffle(hard_password)
# shuffle() takes in list and shuffle the list items persnent.

changed_password=""
for a in hard_password:
    changed_password+=a;
    
print(f"Hard version: Your Generated Password is: {changed_password}")


