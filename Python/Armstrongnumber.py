#program to check whether the given number is Armstrong or not using a while loop
num = int(input("Enter the number: ")) 
sum = 0 
n = str(num)

for i in range(0, len(n)):
    sum+=int(n[i])**len(n)
if num == sum:
    print("Entered number is an armstrong's number")
else:
    print("Entered number is not an armstrong's number")
    
