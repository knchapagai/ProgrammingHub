import sys
import secrets
import string
import random

lowercase_char = string.ascii_lowercase
uppercase_char = string.ascii_uppercase
nums = string.digits
special_char = "!@#$%^&*()=+-~/[]{};:<>`"

password = ''
count = 0
length_error = False
uppercase_error = False
num_error = False
special_error = False

# User input
length = int(input("Required Password Length? "))
uppercase_req = int(input("How many Uppercase letter are Required? "))
num_req = int(input("How many Numbers are required? "))
special_req = int(input("How many special characters are required? "))

def error(length, uppercase_req, num_req, special_req):
    global length_error
    global uppercase_error
    global num_error
    global special_error
    if (length <= 0):
        length_error = True
    if (uppercase_req < 0):
        uppercase_error = True
    if (num_req < 0):
        num_error = True
    if (special_req < 0):
        special_error = True

def make_password(required_count, character_set):
    global count
    global password
    while (count < required_count):
        password += secrets.choice(character_set)
        count += 1
    count = 0

def shuffle(s):
    l = list(s)
    random.shuffle(l)
    return "".join(l)

#Error Message
error(length, uppercase_req, num_req, special_req)
if (length_error):
    print("Invalid length!")
if (uppercase_error):
    print("Invalid uppercase letter requirement!")
if (num_error):
    print("Invalid number requirement!")
if (special_error):
    print("Invalid special character requirement!")


if ((not length_error) and (not uppercase_error) and (not num_error) and (not special_error)):
    make_password(uppercase_req, uppercase_char)
    make_password(num_req, nums)
    make_password(special_req, special_char)
    make_password(length - len(password), lowercase_char)

    print("\nPASSWORD: %s\n" % shuffle(password))
else:
    print("Please fix any errors.")


input("Press ENTER to Exit!")