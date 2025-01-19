#tip calculator

print("Welcome to the tip  calculator!")

total_bill=int(input("What was the total bill? $"))

tip=int(input("How much tip you like to give? 10,12 or 15?"))

total_bill_with_tip=(((tip/100)*total_bill)+total_bill)
split=int(input("How many people to split the bill?"))

print(f"Each person should pay: ${round(total_bill_with_tip/split,3)}")
          
