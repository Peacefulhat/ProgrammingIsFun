#Hangman
import random
word_list=["aardvark","babbon","camel"]

random_word=word_list[random.randint(0,2)]
guess_limit=5
word_len=len(random_word)
guess=[]
temp=input()

for i in random_word:
    if temp==i:
        print("Right")
    else:
        print("Wrong")
        



    
