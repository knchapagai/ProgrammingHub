#program to check whether the given number is Armstrong or not using a while loop
num = int(input("Enter the number: ")) 
sum = 0 
temp = num 
while (temp > 0): 
    digit = temp % 10 
    sum += digit ** 3 
    temp //= 10 
if (num == sum): 
    print("Armstrong number") 
else: 
    print("Not an Armstrong number")