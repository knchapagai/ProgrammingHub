str=input("Enter the string:")
rev=""
l=len(str)
for i in range(l-1,-1,-1):
    rev=rev+str[i]
if rev==str:
    print ("Palindrome")
else:
    print ("not palindrome")
