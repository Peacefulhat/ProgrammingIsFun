#Hangman

import random

d_list=["aardvark","baboon","camel"]

selected_word=d_list[random.randint(0,len(d_list)-1)]

correct_letters=[]
times_to_guess=len(selected_word)
print(selected_word)
while(times_to_guess>0):
    display=""
    user_guess=input(" guess your letter ::").lower()
    for letter in selected_word:
        if(user_guess==letter):
            
            times_to_guess-=1

            continue;
        display+="_"
    print(display)
        
print(display)
               

               
