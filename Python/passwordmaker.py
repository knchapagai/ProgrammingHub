# importing libraries
import random
import string 

# print welcome message
print('Welcome to Password Maker!')
adjectives = ['sleepy', 'slow', 'smelly', 'wet', 'fat', 'red','orange', 'yellow', 'green','blue', 'purple', 'fluffy','white', 'proud', 'brave']
nouns = ['apple', 'dinosaur', 'ball','toaster', 'goat', 'dragon','hammer', 'duck', 'panda', 'cat','wolf']

# main function
while True:
    adjective = random.choice(adjectives)
    noun = random.choice(nouns)
    number = random.randrange(0, 100)
    special_char = random.choice(string.punctuation)
    password = adjective + noun + special_char + str(number)
    print(f"Your new password is: {password}")

    option = input('Would you like another password? Type y or n: ') 
    if option =='n':
        break
