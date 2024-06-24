import random
#Generate 5 random numbers between 10 and 30

first=input("Enter your first number: ").strip()
second=input("Enter your sencond number: ").strip()

randomlist = random.sample(range(10, 30), 5)
print(randomlist)
