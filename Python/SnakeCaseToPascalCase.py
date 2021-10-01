# Python3 code to demonstrate working of 
# Convert Snake case to Pascal case
# Using title() + replace()
  
# initializing string
test_str = 'geeksforgeeks_is_best'
  
# printing original string
print("The original string is : " + test_str)
  
# Convert Snake case to Pascal case
# Using title() + replace()
res = test_str.replace("_", " ").title().replace(" ", "")
  
# printing result 
print("The String after changing case : " + str(res)) 
