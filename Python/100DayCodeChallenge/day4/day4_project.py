#Day4 Project
# Rock paper scissors
import random
RPS=["""
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
"""

,"""
     _______
---'    ____)____
           ______)
          _______)
         _______)
---.__________)
"""

,"""
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
"""]

your_guess=int(input("What do you choose? Type 0 for Rock, 1 for Paper or 2 for Scissors."))
if(your_guess<=2):
    print(RPS[your_guess])
    
    computer_guess=random.randint(0,2)
    
    print(RPS[computer_guess])
    
    if(your_guess==computer_guess):
        print("Draw")
    elif(your_guess==0 and computer_guess==2):
            print("You Win")
    elif(your_guess>computer_guess):
        print("You Win")
    else:
        print("You Loose")
else:
    print("Invalid input")

# logic think in terms of which terms was greater in sequence of signs 0 1 2 (RPS)
